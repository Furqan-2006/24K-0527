#include <stdio.h>

int main()
{
    int num_1, num_2;
    printf("Enter Num_1: ");
    scanf("%d", &num_1);
    printf("Enter Num_2: ");
    scanf("%d", &num_2);
    (num_1 > num_2) ? printf("Num_1 is greater than Num_2") : ((num_2 > num_1) ? printf("Num_2 is greater than Num_1") : printf("Num_1 is equals to Num_2"));
    return 0;
}