#include <stdio.h>

int main()
{
    int num, sum ;
    printf("Enter any number: ");
    scanf("%d", &num);

    while (num < -9 || num > 9)
    {
        sum = 0;
        while (num != 0)
        {
            sum += num % 10;
            num /= 10;
        }
        printf("The sum is: %d\n", sum);
        num = sum;
    }

    printf("The final sum is: %d\n", num);

    return 0;
}
