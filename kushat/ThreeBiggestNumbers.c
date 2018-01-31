#include <stdio.h>

int main() {
    int max1, max2, max3;
    int n;
    scanf("%d", &n);
    max1 = max2 = max3 = n;
    scanf("%d", &n);
    while (n != 0) {
      if (n > max3) {
        if (n > max2) {
            if (n > max1) {
                max1 = n;
            } else {
                max2 = n;
            }
        } else {
            max3 = n;
        }
      }
      scanf("%d", &n);
    }
    printf("\n");
    printf("       the biggest: %4d\n", max1);
    printf("the second biggest: %4d\n", max2);
    printf(" the third biggest: %4d\n", max3);
    return 0;
}
