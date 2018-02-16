#include <stdio.h>

#define S "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

void encode(FILE *f_in, FILE *f_out)
{

}

void decode(FILE *f_in, FILE *f_out)
{

}

int main(int argc, char *argv[])
{
    char mode = *argv[0];
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
