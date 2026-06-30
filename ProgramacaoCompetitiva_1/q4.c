#include <stdio.h>

/*
    Precisei pesquisar pra conseguir fazer essa questão
*/

int miller_rabin(unsigned long long n) {
    if (n < 2) return 0;
    if (n == 2 || n == 3) return 1;
    if (n % 2 == 0) return 0;

    unsigned long long d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }

    unsigned long long bases[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    
    for (int i = 0; i < 12; i++) {
        unsigned long long a = bases[i];
        if (n <= a) break;

        unsigned long long x = 1;
        unsigned long long base = a % n;
        unsigned long long exp = d;
        while (exp > 0) {
            if (exp & 1) x = ((__int128)x * base) % n;
            base = ((__int128)base * base) % n;
            exp >>= 1;
        }

        if (x == 1 || x == n - 1) continue;

        int composite = 1;
        for (int r = 1; r < s; r++) {
            x = ((__int128)x * x) % n;
            if (x == n - 1) {
                composite = 0;
                break;
            }
        }
        if (composite) return 0;
    }
    return 1;
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        unsigned long long n;
        if (scanf("%llu", &n) == 1) {
            printf(miller_rabin(n) ? "YES\n" : "NO\n");
        }
    }
    return 0;
}