#include <stdio.h>

int main()
{
    // While loop is best suited for getting user input.
    int num, sum = 0;
    while (1)
    {
        printf("\nEnter a number(0 to exit): ");
        scanf("%d", &num);
        if (num == 0)
        {
            break;
        }
        sum += num;
        printf("Current sum is %d.\n", sum);
    }
    printf("Exiting loop...");
    return 0;
}