#include <stdio.h>

double pou(double value,int n){
    return (n > 0 ? pou(value,n-1) * value : 1.0);
}

int main(){
    double value = 0;
    int n = 0;
    if(scanf("%lf %d", &value, &n) == 2){
        printf("%lf\n", pou(value, n));
    }
    return 0;
}