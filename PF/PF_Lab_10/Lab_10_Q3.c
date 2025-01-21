#include <stdio.h>

#define MAX_TEMP_C 200

int checkTemp(float temp)
{
    static int count = 0;
    if (temp > MAX_TEMP_C)
    {
        printf("Temperature %.2f exceeded the limit.\n", temp);
        count++;
    }
    else
    {
        printf("Temperature %.2f is within the limit.\n", temp);
    }
    return count;
}

int main()
{
    float temp_C[] = {255, 31.2, 299, 50.0, 21.7, 199.9};
    int size = sizeof(temp_C) / sizeof(temp_C[0]);
    int C;
    for (int i = 0; i < size; i++)
    {
        C = checkTemp(temp_C[i]);
    }
    printf("\nNumber of Times temperature exceeded the limit: %d", C);
    return 0;
}