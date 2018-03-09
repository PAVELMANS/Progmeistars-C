#include <stdio.h>
#include <stdlib.h>

struct node {
    int n;
    struct node *left;
    struct node *right;
};

struct node *add(struct node *root, int k);
void print(struct node *root);
struct node *newnode(int k);

int main() {
    int i;
    struct node *tree = NULL;
    do {
        scanf("%d", &i);
        tree = add(tree, i);
    } while (i);
    print(tree);
    return 0;
}

void print(struct node *root)  {
    if (root!=NULL)  {
        print(root->left);
        printf("%d\n", root->n);
        print(root->right);
    }
}

struct node *add(struct node *root, int k)  {
    if (root == NULL) {
        root = newnode(k);
    } else
    if (root->n > k)  {
        root->left = add(root->left, k);
    }  else
    /*if (root->n <= k)*/  {
        root->right = add(root->right, k);
    }
    return root;
}

struct node *newnode(int k)  {
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->n = k;
    p->left = NULL;
    p->right = NULL;
    return p;
};
