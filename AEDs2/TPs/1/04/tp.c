#include <stdio.h>
#include <stdlib.h>

int comparar(const char *t1, const char *t2){
    while(*t1 && (*t1 == *t2)){
        t1 = t1 + 1;
        t2 = t2 + 1;
    }
    return *(unsigned char *)t1 - *(unsigned char *)t2;
}

int tamanho(char* texto){
    int n = 0;
    while(texto[n] != '\n' && texto[n] != '\0') n = n + 1;
    return n;
}

char* inverter(char* texto, int n){
    char* retorno = (char*) calloc(n + 1,sizeof(char));
    for(int i = 0; i < n; i = i + 1){
        retorno[i] = texto[(n-1) - i];
    }
    return retorno;
}

int main(){
    char* linha = (char*) calloc(1000,sizeof(char));
    char fim[4] = "FIM";
    int n = 0;

    while(fgets(linha,1000,stdin) != NULL){
        n = tamanho(linha);
        linha[n] = '\0';
        if(comparar(linha,fim) == 0) break;
        char* invertido = inverter(linha,n);
        printf("%s\n",invertido);
        free(invertido);
    }

    free(linha);
    return 0;
}
