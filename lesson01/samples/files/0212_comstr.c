#include <stdio.h>

int main(int argc, char *argv[])  {
    int i;
    printf("%s\n", argv[0]);
    printf("%i\n", argc);
    for ( i = 1;  i < argc; i++)  {
        printf("%s%s", argv[i], (i < argc-1) ? "  ":"\n");
    }
    return 0;
}
