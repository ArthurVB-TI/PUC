#include <stdio.h>
#include <stdlib.h>

int lerQuantidade(){
    int retorno = 0;
    scanf("%d", &retorno);
    return retorno;
}

int** lerQuantidades(int n){
    int** retorno = (int**) malloc(sizeof(int*)*n);
    int valorAtual = 0;

    for(int i = 0; i < n; i++){
        retorno[i] = (int*) malloc(sizeof(int)*2);
        scanf("%d",&valorAtual);
        retorno[i][0] = valorAtual;
        scanf("%d",&valorAtual);
        retorno[i][1] = valorAtual;
    }

    return retorno;
}

int main()
{
    int qtde = 0, count = 0;
    int** valores;
    int n = 0, k = 0;

    qtde = lerQuantidade();
    valores = lerQuantidades(qtde);

    for(int i = 0; i < qtde; i++){
        n = valores[i][0];
        k = valores[i][1];
        count = 0;
        if(1<=n && n<=100000000 && 1<=k && k<=n){
            for(int j = 1; j <= k; j++){
                if((n-k+j) % 2 == 1) count++;
            }
            if(count % 2 == 0) printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}