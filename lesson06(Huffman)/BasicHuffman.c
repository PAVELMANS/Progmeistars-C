#include <stdio.h>
#include <stdlib.h>

int strlen(char *s)
{
    char *a = s;
    int i;
    for ( i = 0; *a != EOF; a++, i++);
    return i;
}

int main()
{
    char *code[257];
    FILE *codes = fopen("code.txt", "rb");

    for (int i = 0; i < 257; i++) {
        code[i] = malloc(200);
        fscanf(codes, "%s\n", code[i]);
    }

    FILE *input = fopen("input.txt", "rb");
    FILE *output = fopen("output.txt", "w");


    char *c;
    char w;
    while (!feof(input)) {
        fread(c, sizeof(char), 1, input);
        fputs(code[*c], output);
    }
    fputs(code[256], output);

    return 0;
}
