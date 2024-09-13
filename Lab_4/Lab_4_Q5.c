#include <stdio.h>

int main()
{
    int cus_ID, unit;
    char cus_name[100];
    float unit_pr, cost, net_cost, sur_ch;

    printf("Enter Customer ID: ");
    scanf("%d", &cus_ID);
    printf("Enter Customer Name: ");
    scanf("%s", &cus_name);
    printf("Enter Units Consumed: ");
    scanf("%d", &unit);

    if (unit >= 1 && unit <= 199)
    {
        unit_pr = 16.20;
        cost = unit * unit_pr;
    }
    else if (unit > 199 && unit < 300)
    {
        unit_pr = 20.10;
        cost = unit * unit_pr;
    }
    else if (unit >= 300 && unit < 500)
    {
        unit_pr = 27.10;
        cost = unit * unit_pr;
    }
    else if (unit >= 500)
    {
        unit_pr = 35.90;
        cost = unit * unit_pr;
    }
    else
    {
        printf("Input correct value! Units must be positive.");
    }
    if (cost > 18000)
    {
        sur_ch = (cost * 15) / 100;
        net_cost = cost + sur_ch;
    }
    else
    {
        net_cost = cost;
    }

    printf("\nCustomer ID: %d ", cus_ID);
    printf("\nCustomer Name: %s ", cus_name);
    printf("\nUnits Consumed: %d", unit);
    printf("\nAmount Charges @Rs. %.2f per unit: %.2f ", unit_pr, cost);
    printf("\nSurcharge Amount: %.2f", sur_ch);
    printf("\nNet Payable Amount by the Customer: %.2f", net_cost);
    return 0;
}