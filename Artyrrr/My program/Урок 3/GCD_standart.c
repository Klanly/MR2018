#include <stdio.h>

int main()
{
    //�������� �������
    int gcd; //grand common divisor -- ���
    int a, b;
    scanf("%d%d", &a, &b);
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    gcd = a;

    printf("gcd = %d\n", gcd);
    return 0;
}
