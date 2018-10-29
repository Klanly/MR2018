#include <stdio.h>

typedef struct {
    int values[100];
    unsigned int N;
} array_t;

/* ��������� N,
� ����� N ����� (�� �� ������ 100), ������� ��������� � ������*/
array_t create_array()
{
    array_t A;
    printf("Numer: ");
    scanf("%d", &A.N);
    //��������� ������ � ���������� ���
    //����������������� � ��������� � �������� ����������
    for(int i = 0; i < A.N; i++)
        scanf("%d", &A.values[i]);
    return A;
}

//������ ������, ���������� ��� �������� �� 1
void modify_array(array_t *);

//������� ��� �������� � ������� A
void print_array(const array_t *A);

int main()
{
    array_t A = create_array();
    modify_array(&A);
    print_array(&A);

    return 0;
}

//������ ������, ������� ��� �������� � �������
void modify_array(array_t *A)
{
    for(int i = 0; i < A->N; i++)
        A->values[i] *= A->values[i]; //���������� � �������
}

//������� ��� �������� � ������� A
void print_array(const array_t *A)
{
    for(int i = 0; i < A->N; i++)
        printf("%d ", A->values[i]);
    printf("\n");
}
