#include <iostream>
using namespace std;

int main()
{
    float weightKG, weightLB;
    cout << "Enter weight in Kg to convert it in Pounds." << endl;
    cout << "Weight(kg): ";
    cin >> weightKG;
    weightLB = weightKG * 2.2;
    printf("Weight(kg): %.2f\n", weightKG);
    printf("Weight(lb): %.2f\n", weightLB);

    return 0;
}