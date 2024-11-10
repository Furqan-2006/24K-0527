#include <stdio.h>
#include <string.h>

int main()
{
    char des[20], src[20];
    int n;
    printf("Enter a destination string: ");
    scanf(" %[^\n]", des);

    printf("Enter a source string: ");
    scanf(" %[^\n]", src);

    printf("Enter an integer: ");
    scanf("%d", &n);
    strncat(des, src, n);
    printf("The new concatenated string is %s", des);

    return 0;
}