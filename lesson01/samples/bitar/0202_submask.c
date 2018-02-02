#include <stdio.h>

void printmask (unsigned m);
void enum_submasks (unsigned mask);

int main()  {
    unsigned mask;
    scanf("%d", &mask);
    enum_submasks (mask);
    return 0;
}

void printmask (unsigned mask) {
// ѕечатает номера 1-битов в mask
//  ак обычно, биты нумеруютс€ от младшего к старшим, начина€ с 0.
    char i;
    for (i = 0; mask; i++, mask >>= 1) {
        if (mask&1) printf("%4d", i);
    }
    printf("\n");
}

void enum_submasks (unsigned mask) {
//  m последовательно принимает значени€ всех чисел, у которых 1-биты
//  сто€т только на тех местах, на которых 1-биты имеютс€ в mask.
//  „исла перебираем в пор€дке убывани€ от mask до 0.
//  »наче говор€, печатаем все подмножества множества, заданного mask.
    unsigned m = mask;
    do {
        printf("%8u", m);
        printmask(m);
        m = (m-1) & mask;
    }
    while (m);
    printf("%8u", m);
}
