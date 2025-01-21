#include <stdio.h>

int main()
{
    int odd;
    printf("Enter an odd number: ");
    scanf(" %d", &odd);

    for (int i = odd; i >= 1; i -= 2)
    {
        for (int j = i; j >= 1; j -= 2)
        {

            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}