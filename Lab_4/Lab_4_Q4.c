#include <stdio.h>

int main()
{
    int discount;
    float disc_amount, up_price, tot_amount;
    printf("Enter the total price amount of items bought: ");
    scanf("%f", &tot_amount);

    if (tot_amount >= 500 && tot_amount <= 2000)
    {
        discount = 5;
        disc_amount = (tot_amount * discount) / 100;
        up_price = tot_amount - disc_amount;
        printf("Actual Amount is Rs.%.2f\n", tot_amount);
        printf("Discounted Amount is Rs.%.2f\n", up_price);
        printf("You saved Rs.%.2f\n", disc_amount);
    }
    else if (tot_amount > 2000 && tot_amount <= 4000)
    {
        discount = 10;
        disc_amount = (tot_amount * discount) / 100;
        up_price = tot_amount - disc_amount;
        printf("Actual Amount is Rs.%.2f\n", tot_amount);
        printf("Discounted Amount is Rs.%.2f\n", up_price);
        printf("You saved Rs.%.2f\n", disc_amount);
    }
    else if (tot_amount > 4000 && tot_amount <= 6000)
    {
        discount = 20;
        disc_amount = (tot_amount * discount) / 100;
        up_price = tot_amount - disc_amount;
        printf("Actual Amount is Rs.%.2f\n", tot_amount);
        printf("Discounted Amount is Rs.%.2f\n", up_price);
        printf("You saved Rs.%.2f\n", disc_amount);
    }

    else if (tot_amount > 6000)
    {
        discount = 35;
        disc_amount = (tot_amount * discount) / 100;
        up_price = tot_amount - disc_amount;
        printf("Actual Amount is Rs.%.2f\n", tot_amount);
        printf("Discounted Amount is Rs.%.2f\n", up_price);
        printf("You saved Rs.%.2f\n", disc_amount);
    }
    else
    {
        discount = 0;
        disc_amount = (tot_amount * discount) / 100;
        up_price = tot_amount - disc_amount;
        printf("Actual Amount is Rs.%.2f\n", tot_amount);
        printf("You saved Rs.%.2f\n", disc_amount);
        printf("No Discount on amount less than 500.");
    }

    return 0;
}
