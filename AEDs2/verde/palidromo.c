#include <stdio.h>
#include <stdlib.h>

// Pedi ajuda da IA pra me ajudar a montar essa função
// Const para não alterar os valores (so para ler)
int comparar(const char *t1, const char *t2){
    // enquanto não chegar no /0 ele continua executando
    while(*t1 && (*t1 == *t2)){
        t1 = t1 + 1;
        t2 = t2 + 1;
    }

    // se ambos chegarem no /0, return 0
    return *(unsigned char *)t1 - *(unsigned char *)t2;
}

int main(){
    int MAX = 1000;
    char fim[5] = "FIM\n";
    char* linha = (char*) malloc(sizeof(char)*MAX);
    int v = 0;
    int n = 0;

    while(fgets(linha,MAX,stdin) != NULL && linha[0] != '\n' && comparar(linha,fim)){
        while(linha[n] != '\n') n = n + 1;
        v = 1;
        for(int i = 0; i <= n/2; i = i + 1){
            if(linha[i] != linha[n-i-1]) v = 0;
            printf("%c %c\n", linha[i], linha[n-i-1]);
        }
        if(v) printf("SIM\n");
        else printf("NAO\n");
    }

    return 0;
}