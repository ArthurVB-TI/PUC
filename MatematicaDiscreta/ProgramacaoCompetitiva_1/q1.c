#include <stdio.h>

/*
    Precisei pesquisar pra conseguir fazer
*/

long long sum_1_to_N(long long N, long long MOD) {
    long long term1 = N % MOD;
    long long term2 = (N + 1) % MOD;
    long long total = (term1 * term2) % MOD;
    
    return (total * 499122177) % MOD;
}

int main() {
    long long A, B, C;
    long long MOD = 998244353;

    if (scanf("%lld %lld %lld", &A, &B, &C) != 3) {
        return 1;
    }

    long long sumA = sum_1_to_N(A, MOD);
    long long sumB = sum_1_to_N(B, MOD);
    long long sumC = sum_1_to_N(C, MOD);

    long long ans = (sumA * sumB % MOD) * sumC % MOD;

    printf("%lld\n", ans);

    return 0;
}
