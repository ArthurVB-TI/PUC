#include <stdio.h>

int main(){
    int a, b, c, count = 0, found = 0;
    const int valorProcurado = 998244353;
    scanf("%d %d %d", &a, &b, &c);
    for(int i = 1; i <= a && !found; i++){
        for(int j = 1; j <= b && !found; j++){
            for(int k = 1; k <= c && !found; k++){
                count = count + (i*j*k);
                if(count >= valorProcurado){
                    found = 1;
                }
            }
        }
    }
    printf("\n%d\n", count);
    return 0;
}