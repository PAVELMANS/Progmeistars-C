#include <stdio.h>

unsigned char base_ch[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void encode(FILE *f_in, FILE *f_out)
{
    int ch[3];
    char code[4];
    do {
        for (int i = 0; i < 3; i++) {
          ch[i] = getc(f_in);
          if (ch[i] == EOF) {
                return;
          }
        }
        code[0] = ch[0] >> 2;
        code[1] = ((ch[0] & 0x03) << 4) | (ch[1] >> 4);
        code[2] = ((ch[1] & 0x0F) << 2) | (ch[2] >> 6);
        code[3] = ch[2] & 0x3F;
        char encripted[3];
        for (int i = 0; i < 4; i++) fprintf(f_out, "%c", base_ch[code[i]]);
    } while (1);
}

void decode(FILE *f_in, FILE *f_out)
{

}

int main(int argc, char *argv[])
{
    char mode = *argv[1];
    //char inFil[] = *argv[2];
    //char outFil[] = *argv[3];
    FILE *inFile = fopen(argv[2], "rb");
    FILE *outFile = fopen(argv[3], "wb");

    switch (mode)
    {
        case 'e':
            encode(inFile, outFile);
            break;
        case 'd':
            decode(inFile, outFile);
            break;
    }
    fclose(inFile);
    fclose(outFile);
}
