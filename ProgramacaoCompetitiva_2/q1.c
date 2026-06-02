#include <stdio.h>
#include <stdlib.h>

int lerQuantidade(){
    int retorno = 0;
    scanf("%d", &retorno);
    return retorno;
}

int* lerQuantidades(int n){
    int* retorno = (int*) malloc(n * sizeof(int));
    int valorAtual = 0;

    for(int i = 0; i < n; i++){
        scanf("%d", &valorAtual);
        retorno[i] = valorAtual;
    }

    return retorno;
}

int main()
{
    int n = 0;
    int* valores;
    int v = 1;
    int count = 0;

    n = lerQuantidade();
    valores = lerQuantidades(n);
    
    if(1<=n && n<=100000){
        for(int i = 0; i < n && v; i++){
            if(!(1<=valores[i] && valores[i]<=1000000000000)) v = 0;
            for(int j = 1; j <= valores[i] && v; j++){
                if(valores[i]%j == 0) count++;
            }
            if(count == 3) printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}