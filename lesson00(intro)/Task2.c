#include <stdio.h>;

int prime(unsigned int n) {
    for (int x = 2; x < n; x++) {
        if (!n % x) {
            return 0;
        }
    }
    return 1;
}

int main() {
    unsigned int n;
    scanf("%d", &n);
    printf("%s\n", prime(n) ? "prime" : "non-prime");
    return 0;
}
