#include <stdio.h>
#include <math.h>

/*
    Precisei pesquisar uma parte pra conseguir terminar
*/

int is_prime(long long n) {
    if (n < 2) return 0;
    if (n == 2 || n == 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    while (n--) {
        long long x;
        if (scanf("%lld", &x) != 1) continue;
        
        long long root = (long long)round(sqrt(x));
        
        if (root * root == x && is_prime(root)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    
    return 0;
}