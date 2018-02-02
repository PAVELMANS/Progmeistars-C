#include <stdio.h>

char bitcount1 (unsigned n);  //  ���������� ���������� 1-���
char bitcount2 (unsigned n);  //  � �������� ������ n

int main()  {
    unsigned n;
    scanf("%d", &n);
    printf("%d %d %d\n", n, bitcount1(n), bitcount2(n));
    return 0;
}

char bitcount1 (unsigned n)  {
    int count;
    for (count=0; n; n >>= 1)  {
        count += n & 1;
    }
    return count;
}

char bitcount2 (unsigned n)  {
    int count=0;
    for (; n>0; n &= n-1, count++)  {
        //  n & (n-1) - ��� n c ���������� ����� ������ 1-�����
    }
    return count;
}

