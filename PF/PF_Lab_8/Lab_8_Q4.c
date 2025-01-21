#include <stdio.h>

int main()
{
    int range;
    printf("Enter the range: ");
    scanf("%d", &range);

    for (int i = 2; i <= range; i++)
    {
        int prime = 1;
        for (int j = 2; j <= (i / 2); j++)
        {
            if (i % j == 0)
            {
                prime = 0;
            }
        }
        if (prime == 1)
        {
            printf("%d ", i);
        }
    }

    return 0;
}