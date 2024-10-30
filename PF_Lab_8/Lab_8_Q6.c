#include <stdio.h>

int main()
{
    int matrix[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Enter index %d%d: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nMatrix:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int saddle = 0;
    int saddlePointFound = 0;

    for (int i = 0; i < 3; i++)
    {

        int min = matrix[i][0];
        int col = 0;
        for (int j = 1; j < 3; j++)
        {
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
                col = j;
            }
        }

        int isSaddle = 1;
        for (int k = 0; k < 3; k++)  
        {
            if (matrix[k][col] > min)
            {
                isSaddle = 0;
                break;
            }
        }

        if (isSaddle)
        {
            saddle = min;
            saddlePointFound = 1;
            break; 
        }
    }

    if (saddlePointFound)
    {
        printf("\n\nSaddle Point: %d\n", saddle);
    }
    else
    {
        printf("\n\nNo saddle point found in the matrix.\n");
    }

    return 0;
}
