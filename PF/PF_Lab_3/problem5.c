#include <stdio.h>

int main()
{
    int principle, period;
    float rate, interest;
    printf("Enter Principle amount between Rs.100 - Rs.1,000,000: ");
    scanf("%d", &principle);
    printf("Enter time limit between 1 - 10 years: ");
    scanf("%d", &period);
    printf("Enter Rate of Interest between 5%% - 10%% : ");
    scanf("%f", &rate);
    interest = (principle * rate * period) / 100;
    if ((principle >= 100 && principle <= 1000000) && (period >= 1 && period <= 10) && (rate >= 5 && rate <= 10))
    {
        printf("\nThe Simple Interest is %.2f.", interest);
    }
    else
    {
        printf("Invalid Input! Values must be in Limits.");
    }

    return 0;
}