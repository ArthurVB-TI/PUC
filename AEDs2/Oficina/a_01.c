#include <stdio.h>

int main(){
    int n = 0;
    scanf("%d",&n); getchar( );

    for(int i = 0; i < n; i++){
        for(int j = 1; j <= (n*2) - 1; j++){
            if(j >= n - i && j <= n + i) printf("*");
            else printf(" ");
        }
        printf("\n");
    }

    return 0;
}