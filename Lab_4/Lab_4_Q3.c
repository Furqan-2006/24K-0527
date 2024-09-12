#include <stdio.h>

int main()
{
    char character;
    printf("Enter any character: ");
    scanf("%c", &character);
    if (character >= 65 && character <= 90)
    {
        printf("This is a Capital Alphabet.");
    }
    else if (character >= 48 && character <= 57)
    {
        printf("This is a number.");
    }
    else if (character >= 33 && character <= 47 || character >= 58 && character <= 64 || character >= 91 && character <= 96 || character >= 123 && character <= 126)
    {
        printf("This is a Special Character.");
    }
    else if (character >= 97 && character <= 122)
    {
        printf("This is a Small Alphabet.");
    }

    return 0;
}