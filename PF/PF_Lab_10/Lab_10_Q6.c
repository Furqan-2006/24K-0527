#include <stdio.h>
#include <string.h>

struct TravelPackage
{
    char packageName[50];
    char destination[50];
    int duration;
    double cost;
    int seatsAvailable;
} ;

struct TravelPackage packages[100];
int packageCount = 0;

void addPackage()
{
    printf("Enter package name: ");
    scanf("%s", packages[packageCount].packageName);
    printf("Enter destination: ");
    scanf("%s", packages[packageCount].destination);
    printf("Enter duration (in days): ");
    scanf("%d", &packages[packageCount].duration);
    printf("Enter cost: ");
    scanf("%lf", &packages[packageCount].cost);
    printf("Enter number of seats available: ");
    scanf("%d", &packages[packageCount].seatsAvailable);
    packageCount++;
}

void displayPackages()
{
    printf("Available Packages:\n");
    for (int i = 0; i < packageCount; i++)
    {
        printf("%s to %s (%d days) - $%.2f, %d seats available\n",
               packages[i].packageName, packages[i].destination,
               packages[i].duration, packages[i].cost, packages[i].seatsAvailable);
    }
}

int main()
{
    addPackage();
    displayPackages();
    return 0;
}
