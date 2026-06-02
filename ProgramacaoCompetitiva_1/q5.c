#include <stdio.h>
#include <stdlib.h>

int lerValor(){
    int retorno = 0;
    scanf("%d",&retorno);
    return retorno;
}

void output(int a, int b, int c){
    printf("%d %d %d\n", a, b, c);
}

int main(){
    const int n = 4;
    int* valores = (int*) malloc(sizeof(int)*n);
    int maior = 0;
    int count = 0;

    int a = 0, b = 0, c = 0;

    for(int i = 0; i < n; i++){
        valores[i] = lerValor();
        if(valores[i] > maior) maior = valores[i];
    }
    for(int i = 0; i < n; i++){
        if(valores[i] != maior){
            count = count + 1;
            switch (count)
            {
                case 1: a = maior - valores[i]; break;
                case 2: b = maior - valores[i]; break;
                case 3: c = maior - valores[i]; break;
                default: break;
            }
        }
    }
    output(a,b,c);
    return 0;
}