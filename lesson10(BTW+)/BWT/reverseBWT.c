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

    /*  "����������" ������ �������  */
    w=0;
    for (i=0; i<256; i++) {
        j = charinfo[i];
        charinfo[i] = w;
        w += j;
    }
    /*  ����� ������� ������� c � ������ �������
        ������ ���������� � charinfo[c]           */

    /*  ������� ������������ ����� ��� �������� �� ���� ������ �����  */
    for (i=0; i<length; i++){
        permutation [charinfo[s[i]]++]= i;
    }

    /*  �������� ����. */
    j = row;
    for (i=0; i<length-1; i++) {
        j = permutation[j];
        result[i] = s[j];  // ��������� ������
    }

    return result;
}
