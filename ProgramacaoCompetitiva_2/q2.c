#include <stdio.h>
#include <stdlib.h>

int lerQuantidade(){
    int retorno = 0;
    scanf("%d", &retorno);
    return retorno;
}

int* lerQuantidades(int n){
    int* retorno = (int*) malloc(sizeof(int)*n);
    int valorAtual = 0;

    for(int i = 0; i < n; i++){
        valorAtual = lerQuantidade();
        retorno[i] = valorAtual;
    }

    return retorno;
}

int main()
{
    int n = 0;
    int** valores;

    n = lerQuantidade();
    valores = (int**) malloc(sizeof(int*)*n);
    for(int i = 0; i < n; i++){
        valores[i] = lerQuantidades(2);
    }

    if((1<=n && n<=100)){
        for(int i = 0; i < n; i++){
            if(1 <= valores[i][0] && valores[i][0] <= valores[i][1] && valores[i][1] <= 1000000000){
                printf("%d\n",(valores[i][1] - valores[i][0]));
            } else { break; }
        }
    }

    return 0;
}