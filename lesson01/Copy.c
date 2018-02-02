#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned copy(unsigned n, char start, char len) {
    return (n & (((1 << len) - 1) << start)) >> start;
}

int cmp(unsigned n1, unsigned n2) {
    unsigned total = n1 ^ n2;
    int i;
    for (i = 0; !(total & 1); total >>= 1, i++);
    return i;
}

unsigned hashIt(char *name) {
    FILE *fr;
    fr = fopen(name, rb);
    unsigned sum;
    for ()

}

int main(int argc, char *argv[]) {
    printf("%d", cmp(0xFF, 0x2F));
    //for (int i = 1; i < argc; i++) printf("%d\n",hashIt(argv[1]));
    putchar('\a');
    return 0;
}
