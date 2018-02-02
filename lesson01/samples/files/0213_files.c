#include <stdio.h>

void copy1 (char *infile, char *outfile);
void copy2 (char *infile, char *outfile);
int compare (char *file1, char *file2);


int main(int argc, char *argv[])  {
    copy1 ( argv[1], argv[2]);
    printf ("%s\n", compare (argv[1], argv[2]) ? "OK":"Error");
    remove (argv[2]);

    copy2 ( argv[1], argv[2]);
    printf ("%s\n", compare (argv[1], argv[2]) ? "OK":"Error");
    remove (argv[2]);
    return 0;
}

void copy1 (char *infile, char *outfile)  {
    FILE *fin, *fout;
    fin = fopen (infile, "rb");
    fout = fopen (outfile, "wb");
    int c;
    while ( (c = fgetc(fin)) != EOF)  {
        fprintf(fout, "%c", c);
    }
    fclose(fin);
    fclose(fout);
}

void copy2 (char *infile, char *outfile)  {
    FILE *fin, *fout;
    fin = fopen (infile, "rb");
    fout = fopen (outfile, "wb");
    int c;
    for ( c = fgetc(fin); c != EOF; c = fgetc(fin) )  {
        fprintf(fout, "%c", c);
    }
    fclose(fin);
    fclose(fout);
}


int compare (char *file1, char *file2)  {
    FILE *f1, *f2;
    f1 = fopen (file1, "rb");
    f2 = fopen (file2, "rb");
    int c1, c2;
    do  {
        c1 = fgetc(f1);
        c2 = fgetc(f2);
    }  while  ((c1 == c2) && (c1 != EOF));
    fclose(f1);
    fclose(f2);
    return (c1 == c2);
}
