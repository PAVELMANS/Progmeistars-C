#include <stdio.h>

unsigned snoob(unsigned x);  // вычисляет следующее число, в машинной
   // записи которого столько же 1-бит, сколько и в машинной записи x
void printset (unsigned mask); // печатает номера 1-битов в mask.
  // Как обычно, биты нумеруются от младшего к старшим, начиная с 0.

int main()  {
    char n, k;
    scanf("%d", &k);
    scanf("%d", &n);
    unsigned comb, last;
    for (comb = (1<<k) - 1, last  = comb <<(n-k); comb <= last;
                                             comb = snoob(comb)) {
        printset (comb);
    }
    return 0;
}

void printset (unsigned mask) {
    char i;
    for (i = 0; mask; i++, mask >>= 1)  {
        if (mask & 1) printf("%4d", i);
    }
    printf("\n");
}

unsigned snoob(unsigned x)  {           // x = uuu0 1111 0000
    unsigned smallest,  ripple,  ones;
    smallest = x &  -x,                 //     0000 0001 0000
    ripple   = x + smallest;            //     uuu1 0000 0000
    ones     = x ^ ripple;              //     0001 1111 0000
    ones     = (ones >> 2) / smallest;  //     0000 0000 0111
    return  ripple | ones;              //     uuu1 0000 0111
}
