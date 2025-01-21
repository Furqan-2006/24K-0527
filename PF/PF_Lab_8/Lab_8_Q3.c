#include <stdio.h>

int main()
{
    int matrix[2][3][3] = {{{1, 4, 2}, {2, 5, 9}, {12, 4, 8}},
                           {{4, 0, 23}, {2, 9, 0}, {3, 1, 1}}};
    int sum;
    for (int i = 0; i < 2; i++)
    {
        sum = 0;
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                sum += matrix[i][j][k];
            }
        }
        printf("Sum is %d\n", sum);
    }

    return 0;
}