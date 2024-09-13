#include <stdio.h>

int main()
{
    int num_1, num_2, sum, sub, mul;
    float div;
    char operator;

    printf("Enter two operands and an operator.\n");
    printf("Enter Operator: ");
    scanf("%c", &operator);
    printf("Enter num_1: ");
    scanf("%d", &num_1);
    printf("Enter num_2: ");
    scanf("%d", &num_2);

    switch (operator)
    {
    case '+':
        sum = num_1 + num_2;
        printf("num_1 + num_2 is %d", sum);
        break;
    case '-':
        sub = num_1 - num_2;
        printf("num_1 - num_2 is %d", sub);

        break;
    case '*':
        mul = num_1 * num_2;
        printf("num_1 * num_2 is %d", mul);
        break;
    case '/':
        div = num_1 / num_2;
        printf("num_1 / num_2 is %.1f", div);
        break;

    default:
        printf("You have given wrong Inputs! ");
        break;
    }

    return 0;
}
