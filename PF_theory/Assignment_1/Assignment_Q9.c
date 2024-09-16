#include <stdio.h>
#include <stdlib.h>

int main()
{
    char br_date[12], cr_date[12];
    char br_year[5], cr_year[5], br_month[3], br_day[3], cr_month[3], cr_day[3];
    int invalid = 0;

    printf("Enter Birth Date(DD/MM/YYYY): ");
    scanf("%s", br_date);
    printf("Enter Current Date(DD/MM/YYYY): ");
    scanf("%s", cr_date);

    // storing year from date to year variable
    for (int i = 6; i < 10; i++)
    {
        br_year[i - 6] = br_date[i];
        cr_year[i - 6] = cr_date[i];
    }
    br_year[4] = '\0';
    cr_year[4] = '\0';

    // storing day from date to day variable
    for (int i = 0; i < 2; i++)
    {
        br_day[i] = br_date[i];
        cr_day[i] = cr_date[i];
    }
    br_day[2] = '\0';
    cr_day[2] = '\0';

    // storing month from date to month variable
    for (int i = 3; i < 5; i++)
    {
        br_month[i - 3] = br_date[i];
        cr_month[i - 3] = cr_date[i];
    }
    br_month[2] = '\0';
    cr_month[2] = '\0';

    // changing data type from string to integer using 'atoi()' stands for ASCII TO INTEGER
    int bir_day = atoi(br_day);
    int cur_day = atoi(cr_day);
    int bir_month = atoi(br_month);
    int cur_month = atoi(cr_month);
    int bir_year = atoi(br_year);
    int cur_year = atoi(cr_year);

    // leap year check
    int leap_bir_year = (bir_year % 4 == 0 && (bir_year % 100 != 0 || bir_year % 400 == 0));
    int leap_cur_year = (cur_year % 4 == 0 && (cur_year % 100 != 0 || cur_year % 400 == 0));

    // Validation steps
    if ((bir_month < 1 || bir_month > 12) ||
        (cur_month < 1 || cur_month > 12) ||
        (bir_day < 1 || bir_day > 31) ||
        (cur_day < 1 || cur_day > 31))
    {
        printf("Incorrect date\n");
        return 0;
    }
    else if ((bir_month == 2) || (cur_month == 2))
    {
        if (leap_bir_year && bir_day > 29)
        {
            printf("February in leap year can't have more than 29 days!\n");
            return 0;
        }
        else if (!leap_bir_year && bir_day > 28)
        {
            printf("February in %d can't have more than 28 days!\n", bir_year);
            return 0;
        }

        if (leap_cur_year && cur_day > 29)
        {
            printf("February in %d can't have more than 29 days!\n", cur_year);
            return 0;
        }
        else if (!leap_cur_year && cur_day > 28)
        {
            printf("February in %d can't have more than 28 days!\n", cur_year);
            return 0;
        }
    }
    else if ((bir_month == 4 || bir_month == 6 || bir_month == 9 || bir_month == 11) ||
             (cur_month == 4 || cur_month == 6 || cur_month == 9 || cur_month == 11))
    {
        if (bir_day > 30 || cur_day > 30)
        {
            printf("Incorrect date!\n");
            return 0;
        }
    }

    // calculations

    int age_year = cur_year - bir_year;
    int age_month = cur_month - bir_month;
    int age_day = cur_day - bir_day;

    if (age_day < 0)
    {
        age_month -= 1;
        age_day += 30;
    }

    if (age_month < 0)
    {
        age_year -= 1;
        age_month += 12;
    }

    // Output the results
    printf("Age is %d years, %d months, and %d days.\n", age_year, age_month, age_day);
    return 0;
}
