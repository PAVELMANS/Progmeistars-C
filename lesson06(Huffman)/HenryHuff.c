#include <stdio.h>
#include <stdlib.h>
#define max 255
struct node {
    char iter,symbol,plus;
    struct node *left;
    struct node *right;
    struct node *parent;
};
struct node *newnode(char s, char i)  {
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->iter = i;
    p->symbol = s;
    p->left = NULL;
    p->right = NULL;
    p->parent = NULL;
    p->plus = -1;
    return p;
};
int main() {
    FILE *in,*out;

    in =  fopen("input.txt", "r");;
    out = fopen("output.txt", "wb");
    int iteration[255] = {0};
    //reading input file to find symbol repetitions
    char read;
    while ((read = fgetc(in)) != EOF ) printf("%c",read);
        iteration[(char)read]++;
    //Leave only symbols which have more than 0 repetitions
    struct node *pointer_arr[256] = {NULL};
    char length = 0;
    for (int i = 0; i < 256; i++) {
        printf("%d %d\n", i, iteration[i]);
        if (iteration[i]) {
            pointer_arr[length] = newnode(i,iteration[i]);
            length++;
        }
    }

//while ((read = fgetc(in)) != EOF ) iteration[(char)read]++;
    unsigned char min1,min2,tmp1,tmp2;
    struct node *root_list[256] = {NULL} ,*mem = NULL;;

    while (length > 1) {

        // Find 2 minimums in iter in pointer_arr[] (min1 < min2)

        min1 = max, min2 = max, tmp1 = 1, tmp2 = 1;
        for(int i = 0 ; i < length ; i++ ) {
           if (pointer_arr[i]->iter < min1) {
               min2 = min1;
               min1 = read;
               tmp1 = i;
           } else if (pointer_arr[i]->iter < min2) {
               min2 = read;
               tmp2 = i;
           }
        }

        //Which number we will add to code path
        pointer_arr[tmp2]->plus = 1; //for right one
        pointer_arr[tmp2]->plus = 0; //for left one

        // Add root path to root_list / if the symbol's code is not 0

       if  (pointer_arr[tmp1]->symbol) root_list[pointer_arr[tmp1]->symbol] = pointer_arr[tmp1];
       if  (pointer_arr[tmp2]->symbol) root_list[pointer_arr[tmp2]->symbol] = pointer_arr[tmp2];

       // Making Huffman tree

       mem = pointer_arr[tmp1];
       pointer_arr[tmp1] = newnode(0 , pointer_arr[tmp1]->iter + pointer_arr[tmp2]->iter); //no symbol

       mem->parent = pointer_arr[tmp1];
       pointer_arr[tmp2]->parent = pointer_arr[tmp1];

       pointer_arr[tmp1]->left = mem;
       pointer_arr[tmp1]->right = pointer_arr[tmp2];
       pointer_arr[tmp2] = pointer_arr[length];
       length--;

    }

    // Saving last created tree in while cycle

    struct node * tree  = pointer_arr[tmp1];

    //Reopen file

    fclose(in);
    in = fopen("input.txt", "rb");
    //in = freopen("input.txt", "rb", stdout);
    //compressing file using root_list

    char code = 0,shift = 7;
    while ((read = fgetc(in)) != EOF ) {
        mem = root_list[read];
        //Finding path of symbol,going up to parent
            while ((mem->parent != NULL) && ( mem->plus != -1 )) {
                code |= (mem->plus << shift);
                mem = mem->parent;
                shift--;
            }
          //printing in  output file
            if (shift < 0) {
                shift = 7;                code = 0;                fprintf(out,"%c",code);
            }

        }
    //Add EOF to the end of compressed text
    fprintf(out,"%c",code);
    fclose(in);    fclose(out);
    return 0;
}
