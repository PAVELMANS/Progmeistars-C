#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    char* word = argv[1];
    FILE *input_text = fopen(argv[2], "r");

    char ch;
    char *specimen = malloc(sizeof(word));
    int position = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        specimen[i] = fgetc(input_text);
        position++;
    }
    while ((ch = fgetc(input_text)) != EOF)
    {
        if (!strcmp(specimen, word))
        {
            printf("The word \"%s\" has been found at the position %d\n", word, position);
        }
        position++;
        specimen++;
        specimen[strlen(word) - 1] = ch;
    }
    printf("The search has been finished");

    return 0;
}
