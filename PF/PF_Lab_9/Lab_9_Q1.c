#include <stdio.h>

int product(int a, int b)
{
    return a * b;
}
int main()
{
    int num1, num2;
    printf("Enter integer 1: ");
    scanf("%d", &num1);
    printf("Enter integer 2: ");
    scanf("%d", &num2);
    int mul = product(num1, num2);
    printf("THe product of %d and %d is %d.", num1, num2, mul);
    return 0;
}