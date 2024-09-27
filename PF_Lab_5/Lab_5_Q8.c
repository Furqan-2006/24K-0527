#include <stdio.h>

int main()
{
    int num, i = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    while (num)
    {
        if (num & 1)
        {
            i++;
        }
        num = num >> 1;
    }
    printf("Number of 1s in the binary representation is: %d\n", count);

    return 0;
}
