#include <stdio.h>

int numlength(unsigned n) {
    int length = 0;
    int ten = 1;
    while ((n / ten) > 0) {
        length++;
        ten *= 10;
    }
    return length;
}

int main() {
    unsigned n;
    scanf("%d", &n);
    printf("%d", numlength(n));
    return 0;
}
