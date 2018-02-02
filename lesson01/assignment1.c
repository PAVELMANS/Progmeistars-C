#include <stdio.h>

int prime (unsigned n)  {
    unsigned d;
    if (n <= 1) return 0;
    for (d=2; d*d <= n; d++)  {
        if (n % d == 0) return 0;
    }
    return 1;
}

void printbin (unsigned n)  {
    unsigned p2 = 1;
    while (p2 <= n)  p2 <<= 1;
    do  {
        p2 >>= 1;
        printf((n & p2)?"1":"0");
    }  while (p2 > 1);
    printf("\n");
}

char numberlength (unsigned n)  {
    int res = 0;
    do  {
        res++;
        n /= 10;
    }  while (n);
    return res;
}

unsigned digitsum (unsigned n)  {
    int res;
    for (res = 0; n; n /= 10)  res += n%10;
    return res;
}

unsigned power1(unsigned m, unsigned n, unsigned base)  {
    int res;
    for (res = 1; n; n--)  {
        res = (res * m) % base;
    }
    return res;
}

unsigned power2(unsigned m, unsigned n, unsigned base)  {
    unsigned res = 1;
    while (n) {
        if (n & 1)  res = res * m % base;
        n >>= 1;
        m *= m;
    }
    return res;
}


int main() {
    printf("%d %d \n", power1(5, 7, 100), power2(5, 7, 100));
    printf("%d %d \n", power1(2, 10, 50), power2(2, 10, 50));

    return 0;
}
