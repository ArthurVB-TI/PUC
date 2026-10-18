#include <stdio.h>
#include <math.h>

void triangulos(int n,int l,int index){
    if(index > 0){
        for(int i = 0; i < l; i++){
            for(int j = 1; j <= (((l*2)-1)*n)/(n-index + 1);j++){
                if(j == (l*(index-1))/2 + index + (l - i) || j == (l*(index-1))/2 + index + (l + i)) printf("*");
                else if(i == l - 1 && j >= (l*(index-1))/2+(l - i) + index && j <= (l*(index-1))/2+(l + i) + index) printf("*");
                else printf(" ");
            }
            printf("\n");
        }
        triangulos(n,l,index - 1);
    }
}

int main(){
    int n = 0;
    scanf("%d",&n); getchar( );

    triangulos(pow(2,n)/4,4,pow(2,n)/4);

    return 0;
}