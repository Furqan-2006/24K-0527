#include <stdio.h>

float operations(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return (float)a * b;
        break;
    case '/':
        if (b == 0)
        {
            printf("Error: division by zero.\n");
            return 0;
        }

        return (float)a / b;
        break;
    default:
        printf("Invalid Input!");
        break;
    }
    return 0;
}
int main()
{
    int num1, num2;
    char symbol;
    printf("Enter number_1: ");
    scanf("%d", &num1);
    printf("Enter number_2: ");
    scanf("%d", &num2);
    printf("Enter operation Symbol: ");
    scanf(" %c", &symbol);
    if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
    {
        printf("%d %c %d is equals to %.2f", num1, symbol, num2, operations(num1, num2, symbol));
    }
    else
    {
        printf("Invalid Operation!");
    }

    return 0;
}