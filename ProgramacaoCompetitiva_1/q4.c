#include <stdio.h>

int main(){
    int number = 0; int isPrimo = 1;
    if(scanf("%d", &number)){
        for(int i = 2; i < number && isPrimo; i++){
            if(number % i == 0) isPrimo = 0;
        }
        printf("%s\n", isPrimo ? "sim" : "nao");
    }
    return 0;
}