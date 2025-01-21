#include <stdio.h>

int main()
{
    int age;
    printf("Enter age: ");
    scanf("%d", &age);
    if (age >= 0)
    {
        if (age <= 12)
        {
            printf("You are a Child.");
        }
        else if (age > 12 && age <= 19)
        {
            printf("You are a Teenager.");
        }
        else if (age > 19 && age <= 64)
        {
            printf("You are an Adult.");
        }
        else
        {
            if (age > 64)
            {
                printf("You are an Senior.");
            }
        }
    }
    else
    {
        printf("You are not born yet. \nEnter age Greater or equals to zero.");
    }
    return 0;
}