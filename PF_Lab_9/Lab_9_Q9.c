#include <stdio.h>
#include <string.h>

void reverse(char str[])
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
    int size;
    printf("Enter the size of the string: ");
    scanf("%d", &size);
    getchar();

    char string[size];
    printf("Enter the string: ");
    fgets(string, size + 1, stdin);

    int len = strlen(string);
    if (len > 0 && string[len - 1] == '\n')
    {
        string[len - 1] = '\0';
    }

    char reversed[size];
    strcpy(reversed, string);
    reverse(reversed);

    printf("The reversed word is %s", reversed);

    return 0;
}