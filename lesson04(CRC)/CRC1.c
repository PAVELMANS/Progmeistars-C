#include <stdio.h>

void xor(int *n, int mask) {

}

int main(int argc, char *argv[])
{
    FILE *in_file = fopen(argv[1], "rb");
    int mask = (int) argv[2];
    char c[5] = {0};

    for (int i = 0; i < 5; i++) {
        c[i] = getc(in_file);
    }
    do {
        int b = 1 << 7;
        for (int i = 0; i < 8; i++) {
            if (b & c[0])
            {
                int n = (c[4] >> (7 - i)) + (c[3] << i) + (c[2] << (8 + i)) + (c[1] << (16 + i)) + (c[0] << (24 + i));
                xor(&n, mask);

            }
            b >>= 1;
        }
        for (int i = 0; i < 4; c[i] = c[i+1], i++);
        c[4] = getc(in_file);
    } while (c[4] != EOF);

    fclose(in_file);
    return 0;
}
