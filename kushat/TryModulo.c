#include <stdio.h>

long power(int m, int n) {
    long result = m;
    if (n > 0) {
        for (int i = 1; i < n; i++) {
            result *= m;
        }
    } else {
        for (int i = 1; i > n; i--) {
            result /= m;
        }
    }
    return result;
}

int main() {
    long m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    printf("%6d", power(m, n) % k);
    return 0;
}
