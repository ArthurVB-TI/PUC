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

int vogal(char c){
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int consoante(char c){
    return (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) && !vogal(c));
}

int digito(char c){
    return (c >= '0' && c <= '9');
}

int x1(char* texto, int n, int i){
    int retorno = 1;
    if(i < n){
        if(!vogal(texto[i])) retorno = 0;
        else retorno = x1(texto,n,i + 1);
    }
    return retorno;
}

int x2(char* texto, int n, int i){
    int retorno = 1;
    if(i < n){
        if(!consoante(texto[i])) retorno = 0;
        else retorno = x2(texto,n,i + 1);
    }
    return retorno;
}

int x3(char* texto, int n, int i){
    int retorno = 1;
    if(i < n){
        if(!digito(texto[i])) retorno = 0;
        else retorno = x3(texto,n,i + 1);
    }
    return retorno;
}

int x4(char* texto, int n, int i, int separadores, int digitos){
    int retorno = 0;
    if(i < n){
        if(digito(texto[i])) retorno = x4(texto,n,i + 1,separadores,digitos + 1);
        else if(texto[i] == '.' || texto[i] == ',') retorno = x4(texto,n,i + 1,separadores + 1,digitos);
    } else if(separadores <= 1 && digitos > 0) retorno = 1;
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
        printf("%s %s %s %s\n",
            ((n > 0 && x1(linha,n,0)) ? "SIM" : "NAO"),
            ((n > 0 && x2(linha,n,0)) ? "SIM" : "NAO"),
            ((n > 0 && x3(linha,n,0)) ? "SIM" : "NAO"),
            ((n > 0 && x4(linha,n,0,0,0)) ? "SIM" : "NAO"));
    }

    free(linha);
    return 0;
}
