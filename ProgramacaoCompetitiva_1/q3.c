#include <stdio.h>

double myPow(double x, int n) {
    return (n > 0 ? myPow(x,n-1) * x : (n < 0 ? 1 / myPow(x,(-n)) : 1.0));
}