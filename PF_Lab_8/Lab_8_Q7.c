#include <stdio.h>

int main()
{
    int matrix_1[3][3] = {
        {2, 1, 4},
        {4, 4, 1},
        {3, 4, 6}};
    int matrix_2[3][3] = {
        {1, 5, 0},
        {4, 9, 2},
        {2, 1, 3}};

    int Rmatrix[3][3] = {0};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                Rmatrix[i][j] += (matrix_1[i][k] * matrix_2[k][j]);
            }
        }
    }
    printf("Resultant Matrix is:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d", Rmatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}