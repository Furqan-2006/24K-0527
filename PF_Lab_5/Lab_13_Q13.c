#include <stdio.h>

int main()
{
    char letter, Eletter, Dletter;

    printf("Enter a letter for encryption: ");
    scanf(" %c", &letter);

    Eletter = (letter ^ 2);

    printf("\nEncrypted letter is: %c", Eletter);

    Dletter = (Eletter ^ 2);
    printf("\nDecrypted letter is: %c", Dletter);

    return 0;
}