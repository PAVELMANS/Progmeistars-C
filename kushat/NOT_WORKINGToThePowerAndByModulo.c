#include <stdio.h>

long toPower(int m, int n) {
    long output = m;
    if (n > 0) {
        for (int i = 1; i < n; i++) output *= output;
    } else {
        for (int i = 1; i > n; i--) output /= output;
    }
    return output;
}

int main () {
    long m, n, k;
    printf("test");
    scanf("%d %d %d", &m, &n, &k);
    printf("%10d\n", toPower(m, n) % k);
    return 0;
}
