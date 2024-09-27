#include <stdio.h>

int main()
{
    int num, sum;
    printf("Enter any number: ");
    scanf("%d", &num);

    while (num < -9 || num > 9)
    {

        while (num != 0)
        {
            sum += num % 10;
            num /= 10;
        }
        num = sum;
    }

    printf("The final number is: %d\n", num);

    return 0;
}
