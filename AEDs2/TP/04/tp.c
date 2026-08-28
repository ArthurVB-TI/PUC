#include <stdio.h>
#include <stdlib.h>

int comparar(const char *t1, const char *t2){
    while(*t1 && (*t1 == *t2)){
        t1 = t1 + 1;
        t2 = t2 + 1;
    }
    return *(unsigned char *)t1 - *(unsigned char *)t2;
}

char* inverter(char* texto,int n){
    char* retorno = (char*) calloc(n,sizeof(char));
    for(int i = 0; i < (n+1)/2; i = i + 1){
        retorno[i] = texto[(n-1) - i];
        retorno[(n-1) - i] = texto[i];
    };
    return retorno;
}

int main(){
    char* linha = (char*) calloc(100,sizeof(char));
    char fim[5] = "FIM\0";
    int n = 0;

    while(fgets(linha,100,stdin) != NULL && linha[0] != '\n' && linha[0] != '\0' && comparar(linha,fim) != 0){
        n = 0;
        while(linha[n] != '\n' && linha[n] != '\0') n++;
        printf("%s\n",inverter(linha,n));
    }

    return 1;
}