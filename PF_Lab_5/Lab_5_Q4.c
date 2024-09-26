#include <stdio.h>

int main()
{
    int age;
    char ctzsp; // ctzsp == citizenship
    printf("Enter age: ");
    scanf("%d", &age);
    printf("Enter Your Nationality ('P' for Pakistani): ");
    scanf(" %c", &ctzsp);
    if (ctzsp == 'P')
    {
        if (age >= 18)
        {
            printf("You can vote.");
        }
        else
        {
            printf("You cannot vote. Age must be greater than 18.");
        }
    }
    else
    {
        printf("Nationality must be Pakistani if you want to Vote.");
    }

    return 0;
}