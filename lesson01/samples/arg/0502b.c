#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int count;

    if (argc<2) {
        printf("Call format:\n");
        printf("%s start_number [display] \n", argv[0]);
        exit(1);
    }

    int disp = (argc==3) && !strcmp(argv[2], "display") ;

    for ( count = atoi(argv[1]); count; count--)  {
        if (disp) printf ("%d\n", count);
    }
    putchar('\a');  /* beep */
    printf("The end.\n");
    return 0;
}
