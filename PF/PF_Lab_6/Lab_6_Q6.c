#include <stdio.h>

int main()
{
    int term1 = 1;
    int term2 = 2;
    int current_term;

    printf("%d ", term1);
    printf("%d ", term2);

    for (int i = 1; i <= 7; i++)
    {
        current_term = term1 * term2;
        term1 = term2;
        term2 = current_term;
        printf("%d,", current_term);
    }

    return 0;
}
