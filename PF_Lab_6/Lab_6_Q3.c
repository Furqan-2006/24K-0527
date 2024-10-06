#include <stdio.h>
#include <math.h>

int main()
{
    int num, originalNum, isPrime = 1;
    int digit, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    originalNum = num;

    if (num > 9 || num < -9)
    {
        printf("%d is a multiple-digit number.\n", num);

        for (int i = 2; i <= sqrt(abs(num)); i++)
        {
            if (num % i == 0)
            {
                isPrime = 0;
                break;
            }
        }

        while (abs(num) > 0)
        {
            digit = abs(num) % 10;
            sum += digit;
            num /= 10;
        }

        if (isPrime && originalNum > 1)
        {
            printf("%d is a prime number.\n", originalNum);
        }
        else
        {
            printf("%d is a composite number.\n", originalNum);
        }

        printf("The sum of digits of %d is %d.\n", originalNum, sum);
    }
    else
    {
        printf("%d is a single-digit number.\n", num);
    }

    return 0;
}
