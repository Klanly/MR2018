#include <stdio.h>
#define MAX_STACK_SIZE 1000

int A[MAX_STACK_SIZE];
int top = 0; //������� ������������� �����

void push(int x)
{

}

int pop()
{
   return 0;
}

//return 1 ���� ���� ����
int isEmpty()
{
    return 1;
}

//return 1 ���� ���� ����� ����������
int isFull()
{
    return 0;
}

int main()
{
    int x;
    scanf("%d", &x);
    while (x != 0) {
        push(x);
        scanf("%d", &x);
    }

    while (!isEmpty()) {
        printf("%d", pop());
    }

    return 0;
}
