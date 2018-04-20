#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *input_file = fopen("alisa-v-strane-chudes.txt", "rb");
    char *text;

    fseek(input_file, 0, SEEK_END);
    long input_file_size = ftell(input_file);
    rewind(input_file);
    text = malloc((input_file_size + 1) * (sizeof(char)));
    fread(text, sizeof(char), input_file_size, input_file);
    fclose(input_file);
    text[input_file_size] = '\0';

    int num;
    scanf("type in number of letters: %d", &num);
    char word[num];
    scanf("type in the word: %s", word);

    //let us start searching
    time_t t;
    srand((unsigned) time(&t));



    return 0;
}
