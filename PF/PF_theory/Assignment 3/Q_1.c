#include <stdio.h>
#include <string.h>

struct Employee
{
    int employeeCode;
    char employeeName[100];
    int dateOfJoining;
};

struct Date
{
    int day;
    int month;
    int year;
};

void setDetails(struct Employee *emp)
{
    printf("Enter employee code: ");
    scanf("%d", &emp->employeeCode);
    getchar(); 
    printf("Enter employee name: ");
    fgets(emp->employeeName, 100, stdin);
    emp->employeeName[strcspn(emp->employeeName, "\n")] = '\0';
    printf("Enter year of joining: ");
    scanf("%d", &emp->dateOfJoining);
}

void Tenure(struct Employee employees[], int size)
{
    struct Date currentDate;
    int count = 0;
    printf("Enter the current year: ");
    scanf("%d", &currentDate.year);
    for (int i = 0; i < size; i++)
    {
        int tenure = currentDate.year - employees[i].dateOfJoining;
        if (tenure > 3)
        {
            printf("Employee Code: %d\n", employees[i].employeeCode);
            printf("Employee Name: %s\n", employees[i].employeeName);
            printf("Year of Joining: %d\n", employees[i].dateOfJoining);
            printf("Tenure: %d years\n\n", tenure);
            count++;
        }
    }
    printf("Total employees with tenure greater than 3 years: %d\n", count);
}

int main()
{
    struct Employee employees[4];
    for (int i = 0; i < 4; i++)
    {
        printf("Enter details for employee %d:\n", i + 1);
        setDetails(&employees[i]);
    }
    Tenure(employees, 4);
    return 0;
}
