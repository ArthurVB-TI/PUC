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

int anagrama(char* texto, int n){
    int retorno = 1;
    int alfabeto[26] = {0};
    int i = 0;
    int v = 0;
    int cont1 = 0, cont2 = 0;

    while(i < n){
        char c = texto[i];
        if(c != ' '){
            if(c >= 'A' && c <= 'Z') c = c + 32;
            if(c >= 'a' && c <= 'z'){
                int indice = c - 'a';
                if(!v){
                    alfabeto[indice]++;
                    cont1++;
                } else {
                    alfabeto[indice]--;
                    cont2++;
                }
            }
        } else v = 1;
        i = i + 1;
    }

    if(cont1 != cont2) retorno = 0;

    for(i = 0; i < 26; i++){
        if(alfabeto[i] != 0) retorno = 0;
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
        printf("%s\n",(anagrama(linha,n) ? "SIM" : "NAO"));
    }

    free(linha);
    return 0;
}
