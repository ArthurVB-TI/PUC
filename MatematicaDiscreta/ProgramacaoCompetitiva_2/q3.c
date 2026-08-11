#include <stdio.h>

void resolucao() {
    long long n, k;
    if (scanf("%lld %lld", &n, &k) != 2) return;
    
    long long start = n - k + 1;
    long long count = 0;
    
    if (start % 2 != 0) {
        count = (k + 1) / 2;
    } else {
        count = k / 2;
    }
    
    if (count % 2 == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        resolucao();
    }
    return 0;
}