#include <stdio.h>

int main()
{
    int age, cr_score;
    float income;
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter your income: Rs. ");
    scanf("%f", &income);
    printf("Enter your credit score(0 - 1000): ");
    scanf("%d", &cr_score);
    if ((cr_score < 0 || cr_score > 1000) || (age < 0) || (income < 0))
    {
        printf("\nInvalid Inputs!");
        return 0;
    }

    if (age >= 20 && cr_score >= 650)
    {
        if (income >= 10000)
        {
            printf("\nYou are eligible for loan.");
        }
        else
        {
            printf("\nSorry! You are not eligible.");
        }
    }
    else
    {
        printf("\nSorry! You are not eligible.");
        printf("\nEither age or credit score do not met the requirement for loan application.");
        printf("\nAge must be greater than 19 and credit score must be greater than 649.");
    }

    return 0;
}