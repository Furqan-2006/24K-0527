#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define TOTAL_ITEMS 3
#define TOTAL_LIVES 3

void genGrid(char arr[SIZE][SIZE]);
void printGrid(char arr[SIZE][SIZE]);
int movePlayer(char arr[SIZE][SIZE], int *player_x, int *player_y, char direction);

int main()
{
    char grid[SIZE][SIZE];
    int player_x, player_y;
    char move;
    int itemsCollected = 0;
    int lives = TOTAL_LIVES;

    genGrid(grid);
    printGrid(grid);

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (grid[i][j] == 'P')
            {
                player_x = i;
                player_y = j;
                break;
            }
        }
    }

    printf("Collect all Items (I) to win. Avoid Obstacles (X)!\n");
    printf("Controls: W(up), A(left), S(down), D(right). Press 'Q' to Quit.\n");

    while (1)
    {
        printf("Items collected: %d/%d | Lives: %d/%d\n", itemsCollected, TOTAL_ITEMS, lives, TOTAL_LIVES);
        printf("Enter move: ");
        scanf(" %c", &move);

        if (move == 'Q' || move == 'q')
        {
            printf("Exiting the game.\n");
            break;
        }

        int result = movePlayer(grid, &player_x, &player_y, move);

        system("cls");
        printGrid(grid);

        if (result == 1)
        {
            printf("\033[32mYou collected an item!\033[0m\n");
            itemsCollected++;
        }
        else if (result == -1)
        {
            printf("\033[31mYou hit an obstacle!\033[0m\n");
            lives--;
            if (lives <= 0)
            {
                printf("\033[31mGame over! Ran out of lives.\033[0m\n");
                break;
            }
        }

        if (itemsCollected == TOTAL_ITEMS)
        {
            printf("\033[32mYOU WON! \033[0m\n");
            break;
        }
    }
    return 0;
}

void genGrid(char arr[SIZE][SIZE])
{

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            arr[i][j] = ' ';
        }
    }

    srand(time(NULL));

    int obstacles = 0;
    int maxObstacles = SIZE;
    while (obstacles < maxObstacles)
    {
        int obsRow = rand() % SIZE;
        int obsCol = rand() % SIZE;
        if (arr[obsRow][obsCol] == ' ')
        {
            arr[obsRow][obsCol] = 'X';
            obstacles++;
        }
    }

    int items = 0;
    while (items < TOTAL_ITEMS)
    {
        int itemRow = rand() % SIZE;
        int itemCol = rand() % SIZE;
        if (arr[itemRow][itemCol] == ' ')
        {
            arr[itemRow][itemCol] = 'I';
            items++;
        }
    }

    int playerRow, playerCol;
    do
    {
        playerRow = rand() % SIZE;
        playerCol = rand() % SIZE;
    } while (arr[playerRow][playerCol] != ' ');
    arr[playerRow][playerCol] = 'P';
}

void printGrid(char arr[SIZE][SIZE])
{
    printf(" \033[35m--------------------- \033[0m\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("\033[35m| \033[0m ");
        for (int j = 0; j < SIZE; j++)
        {
            if (arr[i][j] == 'P')
            {
                printf("\033[33m %c \033[0m ", arr[i][j]);
            }
            else if (arr[i][j] == 'X')
            {
                printf("\033[31m %c \033[0m ", arr[i][j]);
            }
            else if (arr[i][j] == 'I')
            {
                printf("\033[32m %c \033[0m ", arr[i][j]);
            }
            else
            {
                printf(" %c  ", arr[i][j]);
            }
        }
        printf("\033[35m| \033[0m\n");
    }
    printf(" \033[35m--------------------- \033[0m\n");
}

int movePlayer(char arr[SIZE][SIZE], int *player_x, int *player_y, char direction)
{
    int new_x = *player_x;
    int new_y = *player_y;

    switch (direction)
    {
    case 'W':
    case 'w':
        new_x--;
        break;
    case 'A':
    case 'a':
        new_y--;
        break;
    case 'S':
    case 's':
        new_x++;
        break;
    case 'D':
    case 'd':
        new_y++;
        break;
    default:
        printf("Invalid move! Use W, A, S, D.\n");
        return 0;
    }

    if (new_x < 0 || new_x >= SIZE || new_y < 0 || new_y >= SIZE)
    {
        printf("You cannot move outside the grid!\n");
        return 0;
    }

    if (arr[new_x][new_y] == 'X')
    {
        printf("Hit an obstacle!\n");
        return -1;
    }

    if (arr[new_x][new_y] == 'I')
    {
        arr[new_x][new_y] = 'P';
        arr[*player_x][*player_y] = ' ';
        *player_x = new_x;
        *player_y = new_y;
        return 1;
    }

    arr[new_x][new_y] = 'P';
    arr[*player_x][*player_y] = ' ';
    *player_x = new_x;
    *player_y = new_y;
    return 0;
}