#include <stdio.h>
#include <stdlib.h>

int comparar(const char *t1, const char *t2){
    while(*t1 && (*t1 == *t2)){
        t1 = t1 + 1;
        t2 = t2 + 1;
    }
    return *(unsigned char *)t1 - *(unsigned char *)t2;
}

int soma(char* texto, int n, int i){
    int retorno = 0;
    if(i < n){
        if(texto[i] >= '0' && texto[i] <= '9') retorno = ((int) (texto[i] - 48)) + soma(texto,n,i+1);
        else retorno = soma(texto,n,i+1);
    }
    return retorno;
}

int main(){
    char* linha = (char*) calloc(100,sizeof(char));
    char fim[5] = "FIM\0";
    int n = 0;

    while(fgets(linha,100,stdin) != NULL && linha[0] != '\n' && linha[0] != '\0' && comparar(linha,fim) != 0){
        n = 0;
        while(linha[n] != '\n' && linha[n] != '\0') n++;
        printf("%d\n",soma(linha,n,0));
    }

    return 1;
}