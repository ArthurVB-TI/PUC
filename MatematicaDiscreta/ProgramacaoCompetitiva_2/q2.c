#include <stdio.h>

/*
    Acertei a logica, mas precisei da IA pra corrigir alguns erros (foi mal)
*/

void solve() {
    long long l, r;
    scanf("%lld %lld", &l, &r);
    if (l == 1 && r == 1) {
        printf("1\n");
    } else {
        printf("%lld\n", r - l);
    }
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        solve();
    }
    return 0;
}