#include <stdio.h>
#include <stdlib.h>

struct node
{
    int ch;
    int sum;
    int index;
    struct node *left;
    struct node *right;
    struct node *parent;
};

struct node *letter[257];
struct node *keys[257];

void print_code(struct node *leaf)
{
    struct node *par;
    do {par = leaf->parent;
        if (par->left == leaf) printf("0");
        else printf("1");
        leaf = par;
    } while (leaf->parent != NULL);
    printf("\n");
}

int main()
{
    FILE *input = fopen("input.txt", "rb");
   // FILE *output = fopen("output.txt", "wb");

    for (int i = 0; i < 257; i++) {
        letter[i] = (struct node *) malloc(sizeof(struct node));
        letter[i]->ch = letter[i]->index = i;
        letter[i]->sum = 0;
        letter[i]->left = letter[i]->right = NULL;
        letter[i]->parent = NULL; //letter[i];
        keys[i] = letter[i];
    }
        //EOF
        letter[256]->ch = EOF;
        letter[256]->sum = 1;

    char c;
    while ((c = fgetc(input)) != EOF) letter[c]->sum++;
    //for (int i = 0; i < 257; i++, printf("%c %d\n", letter[i]->ch, letter[i]->sum));
    fclose(input);

    char is_taken[257] = {0};


    for (int i = 0; i < 256; i++) {

        //finding two smallest
        struct node *min1, *min2;  //min1 <= min2
        min1 = min2 = NULL;
        //for (int j = 0; is_taken[j]; j++, min1++, min2++);
        for (int j = 0; j < 257; j++) {
            if (!is_taken[j]) {
                if (min1 == NULL) {
                    min1 = letter[j];
                } else {
                    min2 = letter[j];
                    break;
                }
            }
        }
        if (min1->sum > min2->sum) {
            struct node *tmp = min1;
            min1 = min2;
            min2 = min1;
        }
        struct node *watcher;
        if (min1 > min2) watcher = min1 + 1;
        else watcher = min2 + 1;
        while (watcher <= letter[256]) {
            if (!is_taken[watcher->index]) {
                if (watcher->sum <= min1->sum) {
                    min2 = min1;
                    min1 = watcher;
                }
            }
            watcher++;
        }
        //two smallest numbers are found

        //on the place of min1 we put a new_node
        struct node *new_node;
        new_node->ch = -2; //jo -1 ir EOF
        new_node->sum = min1->sum + min2->sum;
        new_node->left = min1;
        new_node->right = min2;
        new_node->parent = NULL;
        new_node->index = min1->index;

        min1->parent = min2->parent = new_node;
        letter[min1->index] = new_node;
        is_taken[min2->index] = 1;
    }

    FILE *in = fopen("input.txt", "rb");
    char ca;
    while ((ca = fgetc(in)) != EOF) {
        print_code(keys[ca]);
    }
    return 0;
}
