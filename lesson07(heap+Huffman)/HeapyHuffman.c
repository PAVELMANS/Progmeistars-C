#include <stdio.h>
#include <stdlib.h>

#define SIZE 258

struct node
{
    int ch;
    int sum;
    struct node *left;
    struct node *right;
    struct node *parent;
};

void shift_down(struct node *letters[], int shifting, int last)
{
    unsigned min_child = 2 * shifting;
    letters[0] = letters[shifting];
    while (min_child <= last)
    {
        if ((min_child < last) && (letters[min_child + 1]->sum < letters[min_child]->sum)) min_child++;
        if (letters[0]->sum > letters[min_child]->sum)
        {
            letters[shifting] = letters[min_child];
            shifting = min_child;
            min_child <<= 1;
        } else break;
    }
    letters[shifting] = letters[0];
}

void heapify(struct node *letters[])
{
    for (int i = (257 / 2); i >= 1; i--)
    {
        shift_down(letters, i, 257);
    }
}

int climb_up(struct node *letter)
{

}

int main()
{
    FILE *input = fopen("input.txt", "rb");

    struct node *letters[258];
    struct node *keys[258];
    for (int i = 1; i < 258; i++)
    {
        letters[i] = (struct node *) malloc(sizeof(struct node));
        letters[i]->ch = i-1;
        letters[i]->sum = 0;
        letters[i]->left = letters[i]->right = letters[i]->parent = NULL;
        keys[i] = letters[i];
    }
        //EOF
        letters[257]->ch = EOF;
        letters[257]->sum = 1;

    char c;
    while ((c = getc(input)) != EOF) letters[c+1]->sum++;
    fclose(input);

    heapify(letters);
    int size = 257;
    while (!letters[1]->sum) // eliminating symbols which have not been detected in the text
    {
        letters[1] = letters[size--];
        shift_down(letters, 1, size);
    }

    // starting building up the tree
    do
    {
        struct node *new_node = (struct node *) malloc(sizeof(struct node));

        int min_child = 2;
        if (letters[2]->sum > letters[3]->sum) min_child++;
        new_node->ch = -2;
        new_node->sum = letters[1]->sum + letters[min_child]->sum;
        new_node->parent = NULL;
        new_node->left = letters[1];
        new_node->right = letters[min_child];

        letters[1]->parent = new_node;
        letters[min_child]->parent = new_node;

        letters[min_child] = new_node;
        shift_down(letters, min_child, size);
        letters[1] = letters[size--];
        shift_down(letters, 1, size);
    } while (size-1);

    FILE *input_text = fopen("input.txt", "rb");
    FILE *output_text = fopen("output.txt", "wb");
    char ch; int count = 0; char code = 0;
    do
    {
        ch = getc(input_text);

        struct node *letter = keys[ch];
        while (letter->parent)
        {
            if (letter->parent->right == letter) code = (1 << count) | code;
            count ++;
            if (count > 7)
            {
                fprintf(output_text, "%c", code);
                code = 0;
                count = 0;
            }
            letter = letter->parent;
        }

    } while (ch != EOF);

    fclose(input_text);
    fclose(output_text);

    FILE *decoding_input = fopen("output.txt", "rb");
    FILE *output_decoded = fopen("output_decoded.txt", "wb");

    do {
        ch = fgetc(decoding_input);

    }


    return 0;
}
