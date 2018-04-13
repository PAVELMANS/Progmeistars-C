#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define block_size 0x4000

typedef struct {
    char s[block_size];
    int row;
} BWTcode_t;

BWTcode_t *BWT (char *s);

int main()  {
    int i;
    BWTcode_t *r;
    char s[block_size] = {0};
    scanf("%s", s); // ��� �������
    r = BWT(s);
    printf("%s\n%i\n", r->s, r->row);
    free (r);
    return 0;
}

BWTcode_t *BWT (char *s)  {
    int length = strlen(s);
    BWTcode_t *result;
    int h; // ��������������� (������ ��� �����) �������� ������
    int pos[block_size];
        // ������� ������: pos[i] - ����� ����� A[i] � H-�������
        // A[i] - �����, ������������ � s[i], i=0..length-1
    int bucket[block_size];
        // bucket[i] - � ����� �� ������� ����� �������� ����� A[i]
    int start[block_size];
        // start[k] - � ������ �� ������� ����� ���������� k-� �����
    int nbucket;
        // ����� ���������� ����� (���������� ����� - 1)
    int chars[256] = {0};
       // c������ �������� - ������������ ��� �������������
       // ������ pos �������� ���� � 1-�������
    int tmp[block_size];
    int i, j, k;
    /*  ��������� ������ chars  */
    for (i=0; i<length; i++)  chars[s[i]]++;
    /*  ������ chars[i] ������ ���������� �������� #i � ����� s  */

    for (i=1; i<256; i++)  chars[i] += chars[i-1];
    /*  � ������ chars[i] ������ ���������� ����� ����������
        �����, ������������� �� ������ #i, � 1-�������  */

    /*  ��������� ������ pos �������� ���� � 1-�������;  */
    /*  ��������� �� ������� 1-����� ������ ������       */
    for (i=0; i<length; i++)  pos[--chars[s[i]]] = i;
    /*  ������ chars ��� ������ �� �����  */

    /*  �����������  ������ �����  */
    nbucket = 0;         // �������� � 0-�� �����
    bucket[pos[0]] = 0;  // ����� ������ � 1-������� ����� ����� � ����� #0,
    start[0] = 0;        // ������� ���������� � ����������� �����
    for (i=1; i<length; i++)  {
        if (s[pos[i]]!=s[pos[i-1]])  {
            nbucket++;
            start[nbucket] = i;
        }
        bucket[pos[i]] = nbucket;
    }
    h = 1;
    /*  ������������� ���������. ��� ���������
        ����������� � ������������ c 1-��������  */

    while ((h<length) && (nbucket+1 < length))  {
    /*  ������ pos �������������  h-���������� - ��������� � 2h-����������  */

        /*  � ������� tmp �������� ����� pos  */
        for (i=0; i<length; i++)  {
            j = pos[i]-h;
            if (j<0)  j += length;
            /*  ����� A[j] ���� ����������� � ������ ������ �����  */
            tmp[start[bucket[j]]++] = j;
        }
        for (i=0; i<length; i++)  {
            pos[i] = tmp[i];
        }


        /*  ������������� ������������� �� ����� - ������ � 2h-�������  */
        /*  ��� �������� ����� ���� ���������� ������ tmp  */
        nbucket = 0;         // �������� � 0-�� �����
        tmp[pos[0]] = 0;  // ����� ������ � 1-������� ����� ����� � ����� #0,
        start[0] = 0;        // ������� ���������� � ����������� �����
        for (i=1; i<length; i++)  {
            if (bucket[pos[i]] != bucket[pos[i-1]])  {
            /*  ������� ����� � ������ (� h-�������)
                ����� �� � ��� �����, ��� � ����������  */
               start[++nbucket] = i;
            }
            else {
            /*  ������� ����� ������ (� h-�������) �����
                � ��� �� �����, ��� � ����������, ...  */
                j = pos[i-1] + h;
                if (j>=length) j -= length;
                k = pos[i] + h;
                if (k>=length) k -= length;
                if (bucket[j] != bucket[k])  {
                /* ... � �� h-������������� ������ � ������ �����  */
                   start[++nbucket] = i;
                }
            }
            tmp[pos[i]] = nbucket;
        }

        /*  ��������� ������ bucket  */
        for (i=0 ; i<length; i++)  {
            bucket[i] = tmp[i];
        }
        /*  ��������� � ���������� ����: ������ pos ������������� 2h-����������  */
        h *= 2;

    }
    /*  �������� ���������  */
   result = (BWTcode_t *) malloc( sizeof(BWTcode_t));
   for (i=0; i<length; i++)  {
        if (pos[i] == 0)  {
           result->s[i] = s[length-1];
           result->row = i;
        }
        else  {
           result->s[i] = s[pos[i]-1];
        }
    }
    result->s[length] = 0;

    return result;
}
