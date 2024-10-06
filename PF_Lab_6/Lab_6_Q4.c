#include <stdio.h>

int main()
{
    int n, first = 0, second = 1 ,next;

    printf("6 terms of Fibonacci Series : ");

    for (int i = 0; i < 6; i++)
    {

        next = first + second;
        first = second;
        second = next;

        printf("%d ", next);
    }

    printf("\n");

    return 0;
}
