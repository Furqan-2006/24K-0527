#include <stdio.h>
#include <string.h>

void reverse(char str[20])
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}
int main()
{

    char words[5][20];
    for (int i = 0; i < 5; i++)
    {
        printf("Enter word_%d: ", i + 1);
        scanf(" %s", words[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        char reversed[20];
        strcpy(reversed, words[i]);
        reverse(reversed);
        if (strcmp(words[i], reversed) == 0)
        {
            printf("Palindrome\n");
        }
        else
        {
            printf("Not Palindrome\n");
        }
    }

    return 0;
}