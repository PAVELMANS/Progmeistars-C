#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randinit(int *a, int len)
{
    for (int i = 0;i < len; i++, a++) *a = rand();
}

void printarr(int *a, int len)
{
    for (int i = 0; i < len; i++, a++) printf("%d ", *a);
    printf("\n");
}

int compare(int *a, int *b, int len)
{
    for (int i = 0; i < len; i++, a++, b++) {
        if (*a < *b) return -1;
        else if (*a > *b) return 1;
    }
    return 0;
}

void shift(int *a, int delta, int len)
{
    for (int i = 0; i < len; i++, a++) *a += delta;
}

void swap(int *a, int *b) {
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

void merge_sort(int *left, int *right)
{
    if (right - left > 1) {
        int *mid;
        mid = left + (right - left) / 2;
        merge_sort(left, mid);
        merge_sort(mid+1, right);
    }
    for (int i = 0; i < right - left; i++) swap((left+i) , (right+i));
}

int main()
{
    time_t a;
    time(&a);
    srand(a);

    int size = 4;
    int *c = (int *) calloc(sizeof(int), size);
    randinit(c, size);
    printarr(c, size);
    merge_sort(c, c + (size - 1));
    printarr(c, size);
    return 0;
}
