#include <stdio.h>

void resolucao() {
    int n;
    if (scanf("%d", &n) != 1) return;
    
    if (n % 3 == 0) {
        printf("Second\n");
    } else {
        printf("First\n");
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