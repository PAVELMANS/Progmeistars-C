#include <stdio.h>

long flength (char *filename);
long countlines (char *filename);
long countletters (char *filename);
void countletters26 (char *filename, int counters[]);

int main (int argc, char *argv[])  {
    printf ("Size of \"%s\"  = %li bytes.\n", argv[1], flength(argv[1]));
    printf ("\"%s\"  contains %li lines.\n", argv[1], countlines(argv[1]));
    printf ("\"%s\"  contains %li letters.\n", argv[1], countletters(argv[1]));
    int c[26];
    countletters26(argv[1], c);
    char i;
    for (i = 'a'; i<='z'; i++)  {
        printf("%4c %6d\n", i, c[i-'a']);
    }
    return 0;
}

long flength (char *filename)  {
    FILE *f;
    long count;
    f = fopen (filename, "rb");
    for (count=0; fgetc(f) != EOF; count++);
    fclose(f);
    return count;
}

long countlines (char *filename)  {
    FILE *f;
    long count = 0;
    int c;
    f = fopen (filename, "rb");
    for (c=0; (c = fgetc(f)) != EOF; c++)  {
        if (c == '\n')  count++;
    }
    fclose(f);
    return count+1;
}

long countletters (char *filename)  {
    FILE *f;
    long count = 0;
    int c;
    f = fopen (filename, "rb");
    for (c=0; (c = fgetc(f)) != EOF; c++)  {
        if ((c >= 'A') && (c<='Z'))  c += 'a'-'A';
        if ((c >= 'a') && (c<='z'))  count++;
    }
    fclose(f);
    return count+1;
}

void countletters26 (char *filename, int counters[])  {
    FILE *f;
    f = fopen (filename, "rb");
    int i, c;
    for (i = 0; i < 26; i++)  counters[i] = 0;
    for (c=0; (c = fgetc(f)) != EOF; c++)  {
        if ((c >= 'A') && (c<='Z'))  c += 'a'-'A';
        if ((c >= 'a') && (c<='z'))  (counters[c-'a'])++;
    }
    fclose(f);
}
