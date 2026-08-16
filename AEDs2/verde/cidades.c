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
    char* linha = (char*) malloc(sizeof(char)*100);
    char fim[5] = "FIM\n";
    int count = 0;

    while(fgets(linha,100,stdin) != NULL && linha[0] != '\n' && comparar(linha, fim)){
        count = 0;

        while(linha[count] != '\n') count = count + 1;

        printf("%d\n",count);
    }
    return 0;
}