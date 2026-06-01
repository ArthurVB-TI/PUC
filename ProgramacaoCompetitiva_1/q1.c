#include <stdio.h>

int main(){
    int a, b, c, cout = 0; 
    bool found = false;
    const int valorProcurado = 998244353;
    scanf("%d %d %d", &a, &b, &c);
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            for(int k = 1; k <= c; k++){
                count = count + (i*j*k);
                if(count >= valorProcurado){
                    found = true;
                }
            }
        }
    }
    printf("\n%d\n", count);
    return 0;
}