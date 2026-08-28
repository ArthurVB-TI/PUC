#include <stdio.h>
#include <stdlib.h>

int comparar(const char *t1, const char *t2){
    while(*t1 && (*t1 == *t2)){
        t1 = t1 + 1;
        t2 = t2 + 1;
    }
    return *(unsigned char *)t1 - *(unsigned char *)t2;
}

char* cifra(char* texto, int n,int i){
    char* retorno = (char*) calloc(n,sizeof(char));
    if(i < n){
        retorno = cifra(texto,n,i + 1);
        retorno[i] = (char)(retorno[i]+3);
        printf("%s",retorno);
    }
    return retorno;
}

int main(){
    char* linha = (char*) calloc(100,sizeof(char));
    char fim[5] = "FIM\n";
    int n = 0;

    while(fgets(linha,100,stdin) != NULL && linha[0] != '\n' && linha[0] != '\0' && comparar(linha,fim) != 0){
        n = 0;
        while(linha[n] != '\n' && linha[n] != '\0') n++;
        printf("%s\n",cifra(linha,n,0));
    }

    free(linha);
    return 0;
}