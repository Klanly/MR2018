#include <stdio.h>

/*����� ������� �� ����� 1000 �����, ��������� ����� - ����.
�������� ������� � ����� �������
*/

const max_array_size = 1000;

int main()
{
    int A[max_array_size];
    int A_size = 0; //���������� ������� �������� ���������

    //��������� �������� � ����������
    int x;
    scanf("%d", &x);
    while (x != 0) {
        A[A_size] = x;
        A_size++;
        scanf("%d", &x);
    }

    //��������� ������� ������ � ����
    for(int i = 0; i < A_size/2; i++) {
        int tmp = A[i];
        A[i] = A[A_size-1-i];
        A[A_size-1-i] = tmp;
    }

    //����� ������� �� �����
    for(int i = 0; i < A_size/2; i++) {
        printf("%d", A[i]);
    }
    printf("\n");

    //����������� ����� �����
    x = A[0];
    for(int i = 0; i < A_size; i++) {
            A[i] = A[i+1];
    A[A_size-1] = x;

    //����� ������� �� �����
    for(int i = 0; i < A_size; i++) {
        printf("%d", A[i]);
    }
    printf("\n");

    //�������� �������� �� �������
    printf("Enter element index to remove:");
    scanf("%d", &x);
    if (x >= 0 && x < A_size) {
        A[i] = A[i+1];
    }
    A_size--; //��������� ����� ������
}
//����� ������� �� �����
    for(int i = 0; i < A_size; i++) {
        printf("%d", A[i]);
    }
    printf("\n");

    //������� �������� � �������� �������
    printf("Enter index of element to insert:");
    scanf("%d", &x);
    if (x >= 0 && x <= A_size)
        for(int i = A_size; i > x; i--)
        A[i] = A[i-1];
    A[x] = 777;
    A_size++;

//����� ������� �� �����
for(int i = 0; i < A_size; i++) {
    printf("%d ", A[i]);
    }
printf("\n");
    return 0;
}
