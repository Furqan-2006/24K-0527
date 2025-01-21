#include <stdio.h>
#include <string.h>

void compress(char str[]);

int main()
{
    int max_len, max_words;
    printf("Enter the max number of words: ");
    scanf("%d", &max_words);
    printf("Enter the max length of the words: ");
    scanf("%d", &max_len);

    char words[max_words][max_len + 1];

    getchar(); 

    for (int i = 0; i < max_words; i++)
    {
        printf("Enter word_%d: ", i + 1);
        fgets(words[i], max_len + 1, stdin);   
        words[i][strcspn(words[i], "\n")] = 0; 
    }

    for (int i = 0; i < max_words; i++)
    {
        printf("Compressed word is: ");
        compress(words[i]);
        printf("\n");
    }

    return 0;
}

void compress(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != str[i + 1])
        {
            printf("%c", str[i]);
        }
    }
}
