#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACIDADE 5

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

typedef struct{
    Veiculo dados[CAPACIDADE];
    int inicio;
    int quantidade;
} Fila;

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

void initFila(Fila* f){
    f->inicio = 0;
    f->quantidade = 0;
}

Veiculo desenfileirar(Fila* f){
    Veiculo retorno = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % CAPACIDADE;
    f->quantidade = f->quantidade - 1;
    return retorno;
}

int enfileirar(Fila* f, Veiculo v, Veiculo* removidoAuto){
    int houveRemocao = 0;
    int posInsercao;

    if(f->quantidade == CAPACIDADE){
        *removidoAuto = desenfileirar(f);
        houveRemocao = 1;
    }
    posInsercao = (f->inicio + f->quantidade) % CAPACIDADE;
    f->dados[posInsercao] = v;
    f->quantidade = f->quantidade + 1;

    return houveRemocao;
}

int main(){
    int n;
    Veiculo* veiculos = lerCsv("/tmp/veiculos.csv", &n);
    Fila fila;
    Veiculo removidoAuto;
    int id;
    int qtdComandos;
    char comando[8];
    char buffer[256];

    initFila(&fila);

    while(scanf("%d", &id) == 1 && id != -1){
        int pos = pesquisarSequencial(veiculos, n, id);
        if(pos != -1){
            if(enfileirar(&fila, veiculos[pos], &removidoAuto)){
                printf("(R)%s %s\n", removidoAuto.marca, removidoAuto.modelo);
            }
        }
    }

    scanf("%d", &qtdComandos);
    for(int i = 0; i < qtdComandos; i = i + 1){
        scanf("%s", comando);
        if(strcmp(comando, "I") == 0){
            scanf("%d", &id);
            int pos = pesquisarSequencial(veiculos, n, id);
            if(pos != -1){
                if(enfileirar(&fila, veiculos[pos], &removidoAuto)){
                    printf("(R)%s %s\n", removidoAuto.marca, removidoAuto.modelo);
                }
            }
        } else if(strcmp(comando, "R") == 0){
            Veiculo removido = desenfileirar(&fila);
            printf("(R)%s %s\n", removido.marca, removido.modelo);
        }
    }

    for(int i = 0; i < fila.quantidade; i = i + 1){
        int pos = (fila.inicio + i) % CAPACIDADE;
        formatVeiculo(fila.dados[pos], buffer);
        printf("%s\n", buffer);
    }

    free(veiculos);
    return 0;
}
