#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct{
    int id;
    char marca[64];
    char modelo[64];
    int ano;
    char categoria[64];
    char combustivel[64];
    int cilindros;
    double cilindrada;
    char transmissao[32];
    char tracao[32];
    double consumoCidade;
    double consumoEstrada;
    double co2;
    int turbo;
    Data dataRegistro;
} Veiculo;

typedef struct No{
    Veiculo dado;
    struct No* prox;
} No;

typedef struct{
    No* inicio;
} Lista;

Data parseData(char* s){
    Data d;
    int ano, mes, dia;
    sscanf(s, "%d-%d-%d", &ano, &mes, &dia);
    d.dia = dia;
    d.mes = mes;
    d.ano = ano;
    return d;
}

void formatData(Data d, char* buffer){
    sprintf(buffer, "%02d/%02d/%04d", d.dia, d.mes, d.ano);
}

Veiculo parseVeiculo(char* s){
    Veiculo v;
    char linha[512];
    strcpy(linha, s);
    char* token;

    token = strtok(linha, ",");
    v.id = atoi(token);
    token = strtok(NULL, ",");
    strcpy(v.marca, token);
    token = strtok(NULL, ",");
    strcpy(v.modelo, token);
    token = strtok(NULL, ",");
    v.ano = atoi(token);
    token = strtok(NULL, ",");
    strcpy(v.categoria, token);
    token = strtok(NULL, ",");
    strcpy(v.combustivel, token);
    token = strtok(NULL, ",");
    v.cilindros = atoi(token);
    token = strtok(NULL, ",");
    v.cilindrada = atof(token);
    token = strtok(NULL, ",");
    strcpy(v.transmissao, token);
    token = strtok(NULL, ",");
    strcpy(v.tracao, token);
    token = strtok(NULL, ",");
    v.consumoCidade = atof(token);
    token = strtok(NULL, ",");
    v.consumoEstrada = atof(token);
    token = strtok(NULL, ",");
    v.co2 = atof(token);
    token = strtok(NULL, ",");
    v.turbo = (strcmp(token, "true") == 0);
    token = strtok(NULL, ",\n");
    v.dataRegistro = parseData(token);

    return v;
}

void formatVeiculo(Veiculo v, char* buffer){
    char dataFormatada[16];
    char combustivelFormatado[64];
    int i;

    formatData(v.dataRegistro, dataFormatada);
    strcpy(combustivelFormatado, v.combustivel);
    for(i = 0; combustivelFormatado[i] != '\0'; i = i + 1){
        if(combustivelFormatado[i] == ';') combustivelFormatado[i] = ',';
    }

    sprintf(buffer, "[%d ## %s ## %s ## %d ## %s ## [%s] ## %d ## %.1f ## %s ## %s ## %.2f ## %.2f ## %.1f ## %s ## %s]",
        v.id, v.marca, v.modelo, v.ano, v.categoria, combustivelFormatado, v.cilindros, v.cilindrada,
        v.transmissao, v.tracao, v.consumoCidade, v.consumoEstrada, v.co2, v.turbo ? "true" : "false", dataFormatada);
}

Veiculo* lerCsv(char* caminhoArquivo, int* n){
    FILE* arq = fopen(caminhoArquivo, "r");
    char linha[512];
    Veiculo* retorno;
    int i;

    *n = 0;
    fgets(linha, 512, arq);
    while(fgets(linha, 512, arq) != NULL) *n = *n + 1;
    fclose(arq);

    retorno = (Veiculo*) calloc(*n, sizeof(Veiculo));
    arq = fopen(caminhoArquivo, "r");
    fgets(linha, 512, arq);
    i = 0;
    while(fgets(linha, 512, arq) != NULL){
        retorno[i] = parseVeiculo(linha);
        i = i + 1;
    }
    fclose(arq);

    return retorno;
}

int pesquisarSequencial(Veiculo* v, int n, int id){
    int retorno = -1;
    for(int i = 0; i < n; i = i + 1){
        if(v[i].id == id) retorno = i;
    }
    return retorno;
}

void initLista(Lista* l){
    l->inicio = NULL;
}

void inserirInicio(Lista* l, Veiculo v){
    No* novo = (No*) malloc(sizeof(No));
    novo->dado = v;
    novo->prox = l->inicio;
    l->inicio = novo;
}

void inserir(Lista* l, Veiculo v, int posicao){
    if(posicao == 0){
        inserirInicio(l, v);
        return;
    }
    No* atual = l->inicio;
    for(int i = 0; i < posicao - 1; i = i + 1) atual = atual->prox;
    No* novo = (No*) malloc(sizeof(No));
    novo->dado = v;
    novo->prox = atual->prox;
    atual->prox = novo;
}

void inserirFim(Lista* l, Veiculo v){
    No* novo = (No*) malloc(sizeof(No));
    novo->dado = v;
    novo->prox = NULL;
    if(l->inicio == NULL){
        l->inicio = novo;
        return;
    }
    No* atual = l->inicio;
    while(atual->prox != NULL) atual = atual->prox;
    atual->prox = novo;
}

Veiculo removerInicio(Lista* l){
    No* removido = l->inicio;
    Veiculo retorno = removido->dado;
    l->inicio = removido->prox;
    free(removido);
    return retorno;
}

Veiculo remover(Lista* l, int posicao){
    if(posicao == 0) return removerInicio(l);
    No* atual = l->inicio;
    for(int i = 0; i < posicao - 1; i = i + 1) atual = atual->prox;
    No* removido = atual->prox;
    Veiculo retorno = removido->dado;
    atual->prox = removido->prox;
    free(removido);
    return retorno;
}

Veiculo removerFim(Lista* l){
    if(l->inicio->prox == NULL) return removerInicio(l);
    No* atual = l->inicio;
    while(atual->prox->prox != NULL) atual = atual->prox;
    No* removido = atual->prox;
    Veiculo retorno = removido->dado;
    atual->prox = NULL;
    free(removido);
    return retorno;
}

int main(){
    int n;
    Veiculo* veiculos = lerCsv("/tmp/veiculos.csv", &n);
    Lista lista;
    int id;
    int qtdComandos;
    char comando[8];
    char buffer[256];

    initLista(&lista);

    while(scanf("%d", &id) == 1 && id != -1){
        int pos = pesquisarSequencial(veiculos, n, id);
        if(pos != -1) inserirFim(&lista, veiculos[pos]);
    }

    scanf("%d", &qtdComandos);
    for(int i = 0; i < qtdComandos; i = i + 1){
        scanf("%s", comando);
        Veiculo removido;
        int houveRemocao = 0;

        if(strcmp(comando, "II") == 0){
            scanf("%d", &id);
            inserirInicio(&lista, veiculos[pesquisarSequencial(veiculos, n, id)]);
        } else if(strcmp(comando, "I*") == 0){
            int posicao;
            scanf("%d %d", &posicao, &id);
            inserir(&lista, veiculos[pesquisarSequencial(veiculos, n, id)], posicao);
        } else if(strcmp(comando, "IF") == 0){
            scanf("%d", &id);
            inserirFim(&lista, veiculos[pesquisarSequencial(veiculos, n, id)]);
        } else if(strcmp(comando, "RI") == 0){
            removido = removerInicio(&lista);
            houveRemocao = 1;
        } else if(strcmp(comando, "R*") == 0){
            int posicao;
            scanf("%d", &posicao);
            removido = remover(&lista, posicao);
            houveRemocao = 1;
        } else if(strcmp(comando, "RF") == 0){
            removido = removerFim(&lista);
            houveRemocao = 1;
        }

        if(houveRemocao) printf("(R)%s %s\n", removido.marca, removido.modelo);
    }

    for(No* atual = lista.inicio; atual != NULL; atual = atual->prox){
        formatVeiculo(atual->dado, buffer);
        printf("%s\n", buffer);
    }

    free(veiculos);
    return 0;
}
