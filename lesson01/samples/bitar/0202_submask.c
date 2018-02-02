#include <stdio.h>

void printmask (unsigned m);
void enum_submasks (unsigned mask);

int main()  {
    unsigned mask;
    scanf("%d", &mask);
    enum_submasks (mask);
    return 0;
}

void printmask (unsigned mask) {
// �������� ������ 1-����� � mask
// ��� ������, ���� ���������� �� �������� � �������, ������� � 0.
    char i;
    for (i = 0; mask; i++, mask >>= 1) {
        if (mask&1) printf("%4d", i);
    }
    printf("\n");
}

void enum_submasks (unsigned mask) {
//  m ��������������� ��������� �������� ���� �����, � ������� 1-����
//  ����� ������ �� ��� ������, �� ������� 1-���� ������� � mask.
//  ����� ���������� � ������� �������� �� mask �� 0.
//  ����� ������, �������� ��� ������������ ���������, ��������� mask.
    unsigned m = mask;
    do {
        printf("%8u", m);
        printmask(m);
        m = (m-1) & mask;
    }
    while (m);
    printf("%8u", m);
}
