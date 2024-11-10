#include <stdio.h>
#include <ctype.h>
#include <string.h>

void Lower(char str[15])
{
    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = tolower(str[i]);
    }
}

int compare(char arr[20][15], char str[15])
{
    Lower(str);

    for (int i = 0; i < 20; i++)
    {
        char word[15];
        strcpy(word, arr[i]);
        Lower(word);

        if (strcmp(word, str) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    char input[15];
    char words[20][15] = {
        "Inspire", "Create", "Learn", "Grow", "Dream", "Achieve", "Explore", "Discover",
        "Innovate", "Imagine", "Build", "Connect", "Lead", "Motivate", "Believe",
        "Challenge", "Empower", "Develop", "Inspire", "Transform"};

    printf("Enter a word: ");
    scanf("%s", input);

    if (compare(words, input))
    {
        printf("Found\n");
    }
    else
    {
        printf("Not Found!\n");
    }

    return 0;
}
