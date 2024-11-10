#include <stdio.h>

void swapIntegers(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    printf("Swapped value of Num_1 is %d\n", a);
    printf("Swapped value of Num_2 is %d\n", b);
}

int main()
{
    int num1, num2;
    printf("Enter number_1: ");
    scanf("%d", &num1);
    printf("Enter number_2: ");
    scanf("%d", &num2);

    printf("Before Swapping, Num_1 is %d\n", num1);
    printf("Before Swapping, Num_2 is %d\n\n", num2);
    

    swapIntegers(num1, num2);

    return 0;
}
