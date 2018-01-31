#include <stdio.h>

void makeItBinary(int n) {
    long two = 1;
    long ten = 1;
    long result = 0;
    while (two < n) {
        two *= 2;
        ten *= 10;
    }
    for (; two > 0; two /= 2) {
        if (n >= two) {
            result += 1 * ten;
            n -= two;
        }
        ten /= 10;
    }
    printf("%d", result);
}

int main() {
    int n;
    scanf("%d", &n);
    makeItBinary(n);
    return 0;
}
