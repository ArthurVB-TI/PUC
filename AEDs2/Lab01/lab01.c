#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int comparar(const char *t1, const char *t2){
    while(*t1 && (*t1 == *t2)){
        t1 = t1 + 1;
        t2 = t2 + 1;
    }
    return *(unsigned char *)t1 - *(unsigned char *)t2;
}

int countMaiuscula(char* texto, int n){
    int retorno = 0;
    for(int i = 0; i < n; i = i + 1){
        if(texto[i] >= 'A' && texto[i] <= 'Z') retorno = retorno + 1;
    }
    return retorno;
}

int main(){
    char* linha = (char*) calloc(MAX,sizeof(char));
    int n = 0;
    char fim[5] = "FIM\n";

    while(fgets(linha,MAX,stdin) != NULL && linha[0] != '\n' && comparar(linha,fim)){
        n = 0;
        while(linha[n] != '\n') n = n + 1;
        printf("%d\n",countMaiuscula(linha,n));
    }
    return 0;
}