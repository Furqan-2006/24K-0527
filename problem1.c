#include <stdio.h>
int main()
{
    int testInteger = 3000000000;
    printf("Number is %d\n", testInteger);


    // As "int" is a 32bit datatype so it gives error in answer. We need to change the data type for this value i.e "long long int(%lld)" or "unsigned int(%u)"
    
    long long int testInteger_2 = 3000000000;
    printf("Number is %lld\n", testInteger_2);


    unsigned int testInteger_3 = 3000000000;
    printf("Number is %u\n", testInteger_3);
    return 0;
}
