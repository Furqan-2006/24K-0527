#include <stdio.h>
#include <math.h>

struct point
{
    int x;
    int y;
};

int distance(int x1, int y1, int x2, int y2)
{
    return sqrt((pow(x2, 2) - pow(x1, 2)) + (pow(y2, 2) - pow(y1, 2)));
}
int isPointInRectangle(struct point p, struct point topLeft, struct point bottomRight)
{
    return (p.x >= topLeft.x && p.x <= bottomRight.x &&
            p.y >= bottomRight.y && p.y <= topLeft.y);
}
int main()
{
    struct point p1, p2;
    printf("Enter the coordinates of point 1(x y): ");
    scanf("%d %d", &p1.x, &p1.y);

    printf("Enter the coordinates of point 2(x y): ");
    scanf("%d %d", &p2.x, &p2.y);

    struct point topLeft = {0, 5};
    struct point bottomRight = {10, 0};

    int S = distance(p1.x, p1.y, p2.x, p2.y);
    printf("Distance btw points in 2d plane is %d units.\n", S);

    if (isPointInRectangle(p1, topLeft, bottomRight))
    {
        printf("Point (%d, %d) lies within the rectangle.\n", p1.x, p1.y);
    }
    else
    {
        printf("Point (%d, %d) does not lie within the rectangle.\n", p1.x, p1.y);
    }
    return 0;
}