#include <stdio.h>

void hr_histo(int arr[], int size);
void vr_histo(int arr[], int size);
int largest(int arr[], int size);
void printArr(int arr[], int size);

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the positive integers to make a histogram.\n");
    int num[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter integer_%d: ", i + 1);
        scanf("%d", &num[i]);
    }
    // Printing the histogram
    hr_histo(num, size);
    printf("\n");
    vr_histo(num, size);
    printf("------------\n");
    printArr(num, size);

    return 0;
}
void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", arr[i]);
    }
}
void hr_histo(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %d | ", arr[i]);
        for (int j = 0; j < arr[i]; j++)
        {
            printf(" *");
        }
        printf("\n");
    }
}

void vr_histo(int arr[], int size)
{
    int large = largest(arr, size);
    for (int i = large; i > 0; i--)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[j] >= i)
            {
                printf(" * ");
            }
            else
            {
                printf("   ");
            }
        }
        printf("\n");
    }
}

int largest(int arr[], int size)
{
    int largest = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    return largest;
}