#include <stdio.h>

int isPrime(int num)
{
    if (num <= 1)
    {
        return 0;
    }
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int number;
    printf("Enter a Number: ");
    scanf("%d", &number);
    if (isPrime(number))
    {
        printf("%d is a Prime Number.", number);
    }
    else
    {
        printf("%d is not a Prime Number.", number);
    }
    
    

    return 0;
}