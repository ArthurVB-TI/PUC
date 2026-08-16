#include <stdio.h>
#include <stdlib.h>

#define MAX 100

char* mesclar(char* txt1, char* txt2, int n1, int n2){
    char* retorno = (char*) calloc(n1 + n2 + 1, sizeof(char));
    char letra = '\0';
    int index1 = 0;
    int index2 = 0;
    for(int i = 0; i < n1 + n2; i = i + 1){
        if(i % 2 == 0){
            if(index1 < n1){
                letra = txt1[index1];
                index1 = index1 + 1;
            } else {
                letra = txt2[index2];
                index2 = index2 + 1;
            }
        } else {
            if(index2 < n2){
                letra = txt2[index2];
                index2 = index2 + 1;
            } else {
                letra = txt1[index1];
                index1 = index1 + 1;
            }
        }
        retorno[i] = letra;
    }
    retorno[n1 + n2] = '\0';
    return retorno;
}

int main(){
    setbuf(stdout, NULL);
    char* linha = (char*) calloc(MAX*2 + 2, sizeof(char));
    int indice = 0;
    int index1 = 0;
    int index2 = 0;
    char* txt_ponteiro;
    int* ponteiro;
    while(fgets(linha, MAX*2, stdin) != NULL && linha[0] != '\n' && linha[0] != '\0'){
        if(linha[0] != '\n' && linha[0] != '\0'){
            char* txt1 = (char*) calloc(MAX*2, sizeof(char));
            char* txt2 = (char*) calloc(MAX*2, sizeof(char));

            ponteiro = &index1;
            indice = 0;
            index1 = 0;
            index2 = 0;
            txt_ponteiro = txt1;
            while(linha[indice] != '\n' && linha[indice] != '\0'){
                if(linha[indice] == ' '){
                    ponteiro = &index2;
                    txt_ponteiro = txt2;
                } else {
                    txt_ponteiro[*ponteiro] = linha[indice];
                    *ponteiro = *ponteiro + 1;
                }
                indice = indice + 1;
            }

            char* resultado = mesclar(txt1, txt2, index1, index2);
            printf("%s\n", resultado);

            free(resultado);
            free(txt1);
            free(txt2);
        }
    }
    free(linha);
    return 0;
}