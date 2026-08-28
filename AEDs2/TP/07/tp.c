#include <stdio.h>
#include <stdlib.h>

int comparar(const char *t1, const char *t2){
    while(*t1 && (*t1 == *t2)){
        t1 = t1 + 1;
        t2 = t2 + 1;
    }
    return *(unsigned char *)t1 - *(unsigned char *)t2;
}

int maiorTamanho(char* texto, int n){
    int retorno = 0;
    int count = 0;
    int v = 0;
    for(int i = 0; i < n; i = i + 1){
        v = 1;
        count = 0;
        for(int j = i; v && j < n; j = j + 1){
            for(int k = i; v && k < j; k = k + 1){
                if(texto[j] == texto[k]) v = 0;
            }
            count = count + v;
        }
        if(count > retorno) retorno = count;
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
        printf("%d\n",maiorTamanho(linha,n));
    }

    free(linha);
    return 0;
}
