#include <stdio.h>

int main()
{
    float tax, taxRate, grossSal, netSal; // Sal = Salary
    printf("Enter Tax Rate: ");
    scanf("%f", &taxRate);

    printf("Enter Basic/Gross salary: ");
    scanf("%f", &grossSal);

    tax = grossSal * taxRate / 100;
    netSal = grossSal - tax;

    printf("Payable Tax is %.2f", tax);
    printf("\nNet Salary is %.2f", netSal);

    return 0;
}