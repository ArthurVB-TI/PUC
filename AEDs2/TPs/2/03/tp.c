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

int compararSemCase(const char* a, const char* b){
    int i = 0;
    while(a[i] != '\0' && b[i] != '\0'){
        char ca = a[i];
        char cb = b[i];
        if(ca >= 'A' && ca <= 'Z') ca = ca + 32;
        if(cb >= 'A' && cb <= 'Z') cb = cb + 32;
        if(ca != cb) return ca - cb;
        i = i + 1;
    }
    return a[i] - b[i];
}

void selecao(Veiculo* v, int n){
    for(int i = 0; i < n - 1; i = i + 1){
        int menor = i;
        for(int j = i + 1; j < n; j = j + 1){
            if(compararSemCase(v[j].modelo, v[menor].modelo) < 0) menor = j;
        }
        if(menor != i){
            Veiculo temp = v[i];
            v[i] = v[menor];
            v[menor] = temp;
        }
    }
}

int main(){
    int n;
    Veiculo* veiculos = lerCsv("/tmp/veiculos.csv", &n);
    Veiculo selecionados[600];
    int m = 0;
    int id;
    char buffer[256];

    while(scanf("%d", &id) == 1 && id != -1){
        int pos = pesquisarSequencial(veiculos, n, id);
        if(pos != -1){
            selecionados[m] = veiculos[pos];
            m = m + 1;
        }
    }

    selecao(selecionados, m);
    for(int i = 0; i < m; i = i + 1){
        formatVeiculo(selecionados[i], buffer);
        printf("%s\n", buffer);
    }

    free(veiculos);
    return 0;
}
