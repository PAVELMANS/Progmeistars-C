#include <stdio.h>

int sumOfDigits(int n) {
    int sum = 0;
    for (int ten = 1; n / ten > 0 ; ten *= 10)
        sum += (n / ten) % 10;
    return sum;
}

int main() {
    for (int n = 1000; n < 10000; n++)
        if (((n % 10) != 0) && ((n % sumOfDigits(n)) == 0)) printf("%5d", n);
    return 0;
}
