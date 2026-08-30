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

void cifra(char* texto, char* retorno, int n, int i){
    if(i < n){
        retorno[i] = (char) (texto[i] + 3);
        cifra(texto,retorno,n,i + 1);
    }
}

int main(){
    char* linha = (char*) calloc(1000,sizeof(char));
    char fim[4] = "FIM";
    int n = 0;

    while(fgets(linha,1000,stdin) != NULL){
        n = tamanho(linha);
        linha[n] = '\0';
        if(comparar(linha,fim) == 0) break;
        char* cifrado = (char*) calloc(n + 1,sizeof(char));
        cifra(linha,cifrado,n,0);
        printf("%s\n",cifrado);
        free(cifrado);
    }

    free(linha);
    return 0;
}
