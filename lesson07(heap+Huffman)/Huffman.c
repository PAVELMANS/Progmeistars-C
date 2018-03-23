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

struct node **chars;

int comp(const void *i, const void *j)
{
    return (*(struct node *)i).sum - (*(struct node *)j).sum;
}

void construct()
{
    struct node *root;
    for (int i = 0; i < byte - 1; i++) {
        root->sum = chars[0]->sum + chars[0]->sum;
        root->left = chars[0];
        root->right = chars[1];
        root->parent = NULL;
        root->ch = 0;
        chars[0]->parent = root;
        chars[1]->parent = root;
        chars[1] = root;
        chars[0] = NULL;
        chars++;
        qsort(chars, byte - 1 - i, sizeof(struct node), comp);
    }
}

int main()
{
    FILE *input = fopen("input.txt", "rb");
    FILE *output = fopen("output.txt", "wb");

    struct node *letters[257];
    chars = malloc(sizeof(struct node) * 256);

    for (int i = 0; i < byte; i++) {
        chars[i] = (struct node *) malloc(sizeof(struct node));
        chars[i]->ch = i;
        chars[i]->sum = 0;
        chars[i]->left = NULL;
        chars[i]->right = NULL;
        chars[i]->parent = NULL;
        letters[i] = chars[i];
    }

    char c;
    while ((c = fgetc(input)) != EOF) chars[c]->sum++;
    //sort_chars();
    qsort(chars, byte, sizeof(struct node), comp);

    struct node *root = NULL;
    construct();
    root = chars;

    return 0;
}
