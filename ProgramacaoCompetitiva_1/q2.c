#include <stdio.h>

void solve() {
    int n, red = 0, blue = 0;
    scanf("%d", &n);

    char r[n + 1], b[n + 1];
    scanf("%s %s", r, b);

    for (int i = 0; i < n; i++) {
        if (r[i] > b[i]) red++;
        else if (b[i] > r[i]) blue++;
    }

    if (red > blue) printf("RED\n");
    else if (blue > red) printf("BLUE\n");
    else printf("EQUAL\n");
}

int main() {
    int t;
    if (scanf("%d", &t) == 1) {
        while (t--) solve();
    }
    return 0;
}