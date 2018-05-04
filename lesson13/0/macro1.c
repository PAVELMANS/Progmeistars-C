#include <stdio.h>

void proc() {
    #define a 3
    #define b a
    printf("%i\n", b);  //3
    #define a 4
    printf("%i\n", b);  //4
}

int main() {
    #define a 1
    #define b a
    printf("%i\n", b);  //1
    proc();
    printf("%i\n", b);  //1
    #undef a
    #define a 2
    printf("%i\n", b);  //2
    return 0;
}
