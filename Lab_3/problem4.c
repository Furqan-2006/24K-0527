#include <stdio.h>

int main()
{
    int S = 1207, pr_1 = 118, pr_2 = 123; // S is distance btw A and B and car travelled 2*1207 in whole trip.
    int totPrice = pr_1 + pr_2;
    float fuelAvg;
    printf("Enter the car's fuel average: ");
    scanf("%f", &fuelAvg);
    float fuelConsumed = (2 * S) / fuelAvg;
    float totCost = fuelConsumed * totPrice;
    if (fuelAvg < 0){
        printf("Invalid input! Enter Positive Value. ");
    }
    else{
        printf("Fuel Consumed is %.2f litres.", fuelConsumed);
        printf("\nFuel Cost is %.2f litres.", totCost);
        
    }

    return 0;
}