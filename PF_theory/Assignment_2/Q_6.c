#include <stdio.h>

int canWin(int num);

int main()
{
    printf("A player can pick 1-4(both inclusive) matchsticks at a time.\n");
    int N, sticks;
    printf("Enter the total number of the matchsticks: ");
    scanf("%d", &N);
    if (canWin(N) == -1)
    {
        printf("Player 'A' cannot win the game.");
    }
    else
    {
        sticks = canWin(N);
        printf("Player 'A' can win if he picks '%d' sticks in first turn, he/she can win.", sticks);
    }

    return 0;
}

int canWin(int num)
{
    if (num % 5 == 0)
    {
        return -1;
    }
    else
    {
        if (num % 5 == 1)
        {
            return 1;
        }
        else if (num % 5 == 2)
        {
            return 2;
        }
        else if (num % 5 == 3)
        {
            return 3;
        }
        else if (num % 5 == 4)
        {
            return 4;
        }
    }
}