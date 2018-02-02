#include <stdio.h>
#define KEY 0xA5

void encode (FILE *fr, FILE *fw, char key)  {
    int c;  // именно так, поскольку EOF = -1 Ц не char!
    char prev = key;
    while ((c = getc(fr)) != EOF)  {
        putc(c ^ prev, fw);
        prev = c;
    }
}

void decode (FILE *fr, FILE *fw, char key)  {
    char tmp = key;
    int c;
    while ((c = getc(fr)) != EOF)  {
        c ^= tmp;
        putc(c, fw);
        tmp = c;
    }
}

int main()  {
    FILE *fr;
    FILE *fw;
    fr = fopen("plaintext.dat", "rb");
    fw = fopen("ciphertext.dat", "wb");
    encode (fr, fw, KEY);
    fclose(fr);
    fclose(fw);

    fr = fopen("ciphertext.dat", "rb");
    fw = fopen("plaintext.res", "wb");
    decode (fr, fw, KEY);
    fclose(fr);
    fclose(fw);
    return 0;
}
