#include <stdio.h>
#include <string.h>

int BinaryToDecimal(int number);
int DecimalToBinary(int number);
void DecimalToHexadecimal(int number);
int HexadecimalToDecimal(char hexNumber[]);
void BinaryToHexadecimal(int number);
int HexadecimalToBinary(char hexNumber[]);

int main()
{
    int num, srNo;
    char hexNum[32];
    printf("- - - - - Number Conversion System - - - - -");
    printf("\nSelect one of the following:\n");
    printf("1. Binary To Decimal\n");
    printf("2. Decimal To Binary\n");
    printf("3. Decimal To Hexadecimal\n");
    printf("4. Hexadecimal To Decimal\n");
    printf("5. Binary To Hexadecimal\n");
    printf("6. Hexadecimal To Binary\n");
    printf("7. Exit\n");

    printf("Enter the selection: ");
    scanf("%d", &srNo);
    if (srNo == 4 || srNo == 6)
    {
        printf("Enter the hexadecimal number: ");
        scanf(" %s", hexNum);
    }
    else
    {
        if (srNo == 1 || srNo == 5)
        {
            printf("Enter the binary number: ");
            scanf("%d", &num);
        }
        else
        {
            printf("Enter the decimal number: ");
            scanf("%d", &num);
        }
    }

    switch (srNo)
    {
    case 1:
        printf("Decimal: %d ", BinaryToDecimal(num));
        break;
    case 2:
        printf("Binary: %d", DecimalToBinary(num));
        break;
    case 3:
        printf("Hexadecimal: ");
        DecimalToHexadecimal(num);
        break;
    case 4:
        printf("Decimal: %d", HexadecimalToDecimal(hexNum));
        break;
    case 5:
        printf("Hexadecimal: ");
        BinaryToHexadecimal(num);
        break;
    case 6:
        printf("Binary: %d ", HexadecimalToBinary(hexNum));
        break;
    case 7:
        printf("Exiting the program...");
        break;
    default:
        printf("Invalid selection!");
        break;
    }
    return 0;
}

int BinaryToDecimal(int number)
{
    int dec = 0;
    int bin = 1;
    while (number > 0)
    {
        int lastDigit = number % 10;
        number /= 10;

        if (lastDigit == 1)
        {
            dec += bin;
        }
        bin *= 2;
    }
    return dec;
}

int DecimalToBinary(int number)
{
    int bin = 0;
    int post = 1;
    while (number > 0)
    {
        int R = number % 2;
        bin += (R * post);
        number /= 2;
        post *= 10;
    }
    return bin;
}

void DecimalToHexadecimal(int number)
{
    char hex[32];
    int post = 0;
    while (number > 0)
    {
        int R = number % 16;
        if (R < 10)
        {
            hex[post] = '0' + R;
            post++;
        }
        else
        {
            hex[post] = 'A' + (R - 10);
            post++;
        }
        number /= 16;
    }
    for (int i = (post - 1); i >= 0; i--)
    {
        printf("%c", hex[i]);
    }
    printf("\n");
}

int HexadecimalToDecimal(char hexNumber[])
{
    int dec = 0;
    int len = strlen(hexNumber);

    for (int i = 0; i < len; i++)
    {
        char digit = hexNumber[i];
        int num;

        if (digit >= '0' && digit <= '9')
        {
            num = digit - '0';
        }
        else if (digit >= 'A' && digit <= 'F')
        {
            num = digit - 'A';
        }
        else if (digit >= 'a' && digit <= 'f')
        {
            num = digit - 'a';
        }
        else
        {
            printf("Invalid Entry!");
            return 0;
        }
        dec = dec * 16 + num;
    }
    return dec;
}

void BinaryToHexadecimal(int number)
{
    int dec = BinaryToDecimal(number);
    DecimalToHexadecimal(dec);
}

int HexadecimalToBinary(char hexNumber[])
{
    int dec = HexadecimalToDecimal(hexNumber);

    return DecimalToBinary(dec);
}