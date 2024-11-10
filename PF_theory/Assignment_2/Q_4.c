#include <stdio.h>
#include <string.h>

void sort(char str[]);
void group(char anagrams[][21], int max, int len);

int main()
{
    int max_len = 20, max_words;
    printf("Words should be of length 20 or less till 0 length.\n");
    printf("Enter the max number of the words: ");
    scanf("%d", &max_words);
    getchar();

    char words[max_words][max_len + 1];
    for (int i = 0; i < max_words; i++)
    {
        printf("Enter word_%d: ", i + 1);
        scanf(" %[^\n]", words[i]);
    }

    group(words, max_words, max_len);

    return 0;
}

void sort(char str[])
{
    int length = strlen(str);
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (str[i] > str[j])
            {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

void group(char anagrams[][21], int max, int len)
{
    char sorted[max][len + 1];
    int printed[max];
    for (int i = 0; i < max; i++)
    {
        printed[i] = 0;
    }

    for (int i = 0; i < max; i++)
    {
        strcpy(sorted[i], anagrams[i]);
        sort(sorted[i]);
    }

    for (int i = 0; i < max; i++)
    {
        if (printed[i])
            continue;

        int isSame = 0;
        printf("The group of '%s' is: ", anagrams[i]);

        for (int j = i; j < max; j++)
        {
            if ((strcmp(sorted[i], sorted[j]) == 0))
            {

                printf(" %s", anagrams[j]);
                printed[j] = 1;
                isSame = 1;
            }
        }
        if (isSame)
        {
            printf("\n");
        }
    }
}