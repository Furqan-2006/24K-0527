#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void puzzle(char arr[6][5]);
void print_arr(char arr[6][5]);
int search(char arr[6][5], char str[]);

int main()
{
    char word_puz[6][5];

    puzzle(word_puz);

    word_puz[5][0] = '0';
    word_puz[5][1] = '5';
    word_puz[5][2] = '2';
    word_puz[5][3] = '7';

    print_arr(word_puz);

    char word[6] = "";
    int score = 0;

    printf("You can make word from top to bottom and right to left only!\n");
    printf("word cannot be longer than 5 letters (e.g. dizzy).\n");
    printf("Write 'END' to exit.\n");
    while (1)
    {
        printf("Enter a word: ");
        scanf(" %s", word);
        if (strlen(word) < 2)
        {
            printf("Word should be of 2 letters or greater.\n");
            continue;
        }

        if (strcmp(word, "END") == 0)
        {
            printf("\nExiting...");
            break;
        }
        if (search(word_puz, word))
        {
            printf("Word Found!\n");
            printf("Score: %d\n", ++score);
        }
        else
        {
            printf("Word Not Found!\n");
            printf("Score: %d\n", score);
        }
    }

    return 0;
}

void puzzle(char arr[6][5])
{
    srand(time(NULL));

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr[i][j] = 'A' + (rand() % 26);
        }
    }
}

void print_arr(char arr[6][5])
{
    printf(" ---------------------\n");
    for (int i = 0; i < 6; i++)
    {
        printf("| ");
        for (int j = 0; j < 5; j++)
        {
            printf(" %c  ", arr[i][j]);
        }
        printf("|\n");
    }
    printf(" ---------------------\n");
}

int search(char arr[6][5], char str[])
{
    int len = strlen(str);

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j <= 5 - len; j++)
        {
            int found = 1;
            for (int k = 0; k < len; k++)
            {
                if (arr[i][j + k] != toupper(str[k]))
                {
                    found = 0;
                    break;
                }
            }
            if (found)
                return 1;
        }
    }

    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i <= 6 - len; i++)
        {
            int found = 1;
            for (int k = 0; k < len; k++)
            {
                if (arr[i + k][j] != toupper(str[k]))
                {
                    found = 0;
                    break;
                }
            }
            if (found)
                return 1;
        }
    }

    return 0;
}