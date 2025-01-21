#include <stdio.h>
#define M_TO_KM 0.001

double convertToKm(double meters) {
    static int count = 0;
    count++;
    printf("Conversion function called %d times\n", count);
    return meters * M_TO_KM;
}

int main() {
    double meters = 1500;
    printf("%.2f meters is %.2f kilometers\n", meters, convertToKm(meters));
    printf("%.2f meters is %.2f kilometers\n", meters, convertToKm(meters));
    return 0;
}
