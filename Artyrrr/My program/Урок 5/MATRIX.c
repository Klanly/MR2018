#include <stdio.h>

typedef struct sNode{
    int value;
    struct sNode *next;
} tNode;

int main()
{
    //������ ����������� ������ �� ������ �������
    tNode A[10];
    for(int i = 0; i < 9; i++) {
        A[i].next = &A[i+1];
        A[i].value = i;
    }
    A[9].next = NULL;
    tNode *begin = &A[0];

    //����� �� ������ � �������� ��������
    tNode *p = begin;
    while (p != NULL) {
        printf("%d\t", (*p).value);
    }
}
