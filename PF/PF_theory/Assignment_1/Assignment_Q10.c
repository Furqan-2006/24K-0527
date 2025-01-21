#include <stdio.h>

int main()
{
    char string[100] ; // set max size of string to 100
    printf("Enter a number: ");
    scanf("%s", &string);

    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == '0' && string[i - 1] == '9')
        {
            i ++;
        }
        printf("%c", string[i]);
    }

    return 0;
}