#include <stdio.h>

char bitcount1 (unsigned n);  //  возвращает количество 1-бит
char bitcount2 (unsigned n);  //  в машинной записи n

int main()  {
    unsigned n;
    scanf("%d", &n);
    printf("%d %d %d\n", n, bitcount1(n), bitcount2(n));
    return 0;
}

char bitcount1 (unsigned n)  {
    int count;
    for (count=0; n; n >>= 1)  {
        count += n & 1;
    }
    return count;
}

char bitcount2 (unsigned n)  {
    int count=0;
    for (; n>0; n &= n-1, count++)  {
        //  n & (n-1) - это n c погашенным самым правым 1-битом
    }
    return count;
}

