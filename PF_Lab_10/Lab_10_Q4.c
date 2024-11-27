#include <stdio.h>
#include <string.h>

#define MAX_CARS 100

typedef struct
{
    char make[20];
    char model[20];
    int year;
    double price;
    double mileage;
} Car;

Car cars[MAX_CARS];

int carCount = 0;

void addCar()
{
    if (carCount < MAX_CARS)
    {
        printf("Enter make: ");
        scanf("%19s", cars[carCount].make);
        printf("Enter model: ");
        scanf("%19s", cars[carCount].model);
        printf("Enter year: ");
        scanf("%d", &cars[carCount].year);
        printf("Enter price: ");
        scanf("%lf", &cars[carCount].price);
        printf("Enter mileage: ");
        scanf("%lf", &cars[carCount].mileage);
        carCount++;
    }
    else
    {
        printf("\nDealership inventory is full!\n");
    }
}

void listCars()
{
    printf("\nAvailable Cars:\n");
    for (int i = 0; i < carCount; i++)
    {
        printf("%s %s (%d) - $%.2f, %.2f miles\n",
               cars[i].make, cars[i].model, cars[i].year,
               cars[i].price, cars[i].mileage);
    }
}

void searchCar()
{
    char Sinput[20];
    printf("\nEnter make or model to search: ");
    scanf("%19s", Sinput);

    printf("Search results for '%s':\n", Sinput);
    int found = 0;
    for (int i = 0; i < carCount; i++)
    {
        if (strcmp(cars[i].make, Sinput) == 0 || strcmp(cars[i].model, Sinput) == 0)
        {
            printf("%s %s (%d) - $%.2f, %.2f miles\n",
                   cars[i].make, cars[i].model, cars[i].year,
                   cars[i].price, cars[i].mileage);
            found = 1;
        }
    }
    if (!found)
    {
        printf("\nNo cars found matching '%s'.\n", Sinput);
    }
}

int main()
{
    int choice;
    do
    {
        printf("\nCar Dealership Menu:\n");
        printf("1. Add a Car\n");
        printf("2. List All Cars\n");
        printf("3. Search by Make or Model\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addCar();
            break;
        case 2:
            listCars();
            break;
        case 3:
            searchCar();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
