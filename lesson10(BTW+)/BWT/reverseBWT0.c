#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define block_size 0x4000

char* reverseBWT (char *s, int row);

int main()  {
    char s[block_size] = {0};
    int row;
    char *res;
    scanf("%s\n%i", s, &row); // ��� �������
    res = reverseBWT(s, row);
    printf("%s\n", res);
    free (res);
    return 0;
}

char* reverseBWT (char *s, int row) {
    int length = strlen(s);
    char s2[block_size+1];
    int charinfo[256] = {0};
    int permutation[block_size];
    int i, j, w;
    char *result;

    result = (char *) calloc(block_size+1, sizeof(char));
    result[length-1] = s[row];   // ����� �������� ��������� ������ ����������

    /*  ������� ���������� ������ ����� � ���������� �����  */
    for (i=0; i<length; i++) {
        charinfo[s[i]]++;
    }

    /*  ���������� ������ �������  */
    w=0;
    for (i=0; i<256; i++) {
        for (j=w; j<w+charinfo[i]; j++) {
            s2[j] = i;
        }
        charinfo[i]=w;
        w=j;
    }
    /*   C�������� ������ ������� - � s2  */
    /*   ����� ������� ������� c � ������ �������
         ������ ���������� � charinfo[c]          */

    /*  ������� ������������ ����� ��� �������� �� ���� ������ �����  */
    for (i=0; s[i]; i++){
        permutation [charinfo[s[i]]++]= i;
    }

    /*  �������� ����. s ���������� �������, s2 - ����� ������� */
    for (j=0; j<length-2; j++){
        for (i=0; i<length; i++)  {
            s[i] = s2[i];
        }
        result[j] = s[row];  // ��������� ������
        /* ������������ - �������� ��������� ������� */
        for (i=0; i<length; i++)  {
            s2[i] = s[permutation[i]];
        }
    }

    result[length-2] = s2[row]; // ������������� ������

    return result;
}
