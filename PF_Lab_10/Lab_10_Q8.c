#include <stdio.h>

int linearSearch(int arr[], int size, int target, int index) {
    if (index == size) return -1; 
    if (arr[index] == target) return index; 
    return linearSearch(arr, size, target, index + 1); 
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int result = linearSearch(arr, size, target, 0);
    if (result != -1)
        printf("Target %d found at index %d\n", target, result);
    else
        printf("Target %d not found\n", target);
    return 0;
}
