#include <stdio.h>;

void binary(int n) {
    int result = 0;
    int two = 1;
    //int degree 0;
    while (two <= n) {
        two *= 2;
    }
    printf("%d\n", two);
    do {
        two /= 2;
        if (n >= two) {
            printf("1");
            n = n - two;
        } else {
            printf("0");
        }
        //two /= 2;
    } while (two != 1);


}

int main() {
    int n;
    scanf("&d", &n);
    binary(n);
    return 0;
}
