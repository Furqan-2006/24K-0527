#include <stdio.h>

void printArr(int arr[], int size, int index)
{
    if (index == size)
    {
        return;
    }
    printf("%d ", arr[index]);
    printArr(arr, size, index + 1);
}

int main()
{
    int arr[] = {123, 231, 33, 024, 5, 56, 86};
    int size = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, size, 0);

    return 0;
}