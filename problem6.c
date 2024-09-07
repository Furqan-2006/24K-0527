#include <stdio.h>

int main()
{
    int x1, x2, y1, y2;
    printf("Input x co-ordinates of point_1: ");
    scanf("%f", &x1);
    printf("Input y co-ordinates of point_1: ");
    scanf("%f", &y1);
    printf("Input x co-ordinates of  point_2: ");
    scanf("%f", &x2);
    printf("Input y co-ordinates of  point_2: ");
    scanf("%f", &y2);
    float slope = (y2 - y1) / (x2 - x1);

    printf("Slope is %.3f", slope);

    return 0;
}
