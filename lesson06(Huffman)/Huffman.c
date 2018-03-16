#include <stdio.h>
#include <stdlib.h>

const char byte = 256;

struct node
{
    char ch;
    int sum;
    struct node *left;
    struct node *right;
    struct node *parent;
};

struct node *chars[byte];
struct node *b[byte];

void sort(int low, int high)
{
    int mid;

    if(low < high) {
        mid = (low + high) / 2;
        sort(low, mid);
        sort(mid+1, high);
        merging(low, mid, high);
    } else {
        return;
    }
}

void merging(int low, int mid, int high)
{

    int l1, l2, i;
    for (l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
        if(chars[l1]->sum <= chars[l2]->sum)
            b[i] = chars[l1++];
        else
            b[i] = chars[l2++];
    }

    while(l1 <= mid)
        b[i++] = chars[l1++];

    while(l2 <= high)
        b[i++] = chars[l2++];

    for(i = low; i <= high; i++)
        chars[i] = b[i];

}

void sort_chars()
{
    sort(0, byte-1);
}

void construct(struct node *root)
{

}

int main()
{
    FILE *input = fopen("input.txt", "rb");
    FILE *output = fopen("output.txt", "wb");

    for (int i = 0; i < byte; i++) {
        chars[i] = (struct node *) malloc(sizeof(struct node));
        chars[i]->ch = i;
        chars[i]->sum = 0;
        chars[i]->left = NULL;
        chars[i]->right = NULL;
        chars[i]->parent = NULL;
    }

    char c;
    while ((c = fgetc(input)) != EOF) chars[c]->sum++;
    sort_chars();

    struct node *root = NULL;
    construct(root);

    return 0;
}
