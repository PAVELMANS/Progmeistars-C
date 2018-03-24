#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *input = fopen("input.txt", "rb");
    FILE *output = fopen("output.txt", "wb");

    int statistics[256] = {0};
    char c;
    while ((c = fgetc(input)) != EOF)

    return 0;
}
