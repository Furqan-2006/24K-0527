#include <stdio.h>
#include <string.h>

void frequency(char arr[]);

int main()
{
    int max_slo, max_len;
    printf("Enter the number of the slogans: ");
    scanf("%d", &max_slo);
    printf("Enter the max length of the slogans: ");
    scanf("%d", &max_len);

    char slogans[max_slo][max_len];
    for (int i = 0; i < max_slo; i++)
    {
        printf("Enter slogan_%d: ", i + 1);
        fgets(slogans[i], max_len, stdin);
        slogans[i][strcspn(slogans[i], "\n")] = 0; 

    }
    for (int i = 0; i < max_slo; i++)
    {
        printf("For '%s' : ", slogans[i]);
        frequency(slogans[i]);
    }
    
    return 0;
}
void frequency(char arr[]){
    int freq[256] = {0};  
    for (int i = 0; arr[i] != '\0'; i++)
    {
        freq[(int)arr[i]]++;
    }

    for (int i = 0; i < 256; i++)
    {
        if (freq[i] > 0)
        {
            printf("\"'%c': %d\"  ", i, freq[i]);

        }
    }
}
