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
    int t = 0;
    int* n;
    
    t = lerQuantidade();
    n = lerQuantidades(t);

    if(1<=t && t<=100){
        for(int i = 0; i < t; i++){
            if(1 <= n[i] && n[i] <= 1000){
                if(n[i] % 3 == 0) printf("Second\n");
                else printf("First\n");
            }
        }
    }

    return 0;
}