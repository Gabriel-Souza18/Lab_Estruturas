#include <stdio.h>
#include <math.h>

int raizes(float A, float B, float C, float *X1, float *X2) {
    float delta = B * B - 4 * A * C;

    if (delta > 0) {
        *X1 = (-B + sqrt(delta)) / (2 * A);
        *X2 = (-B - sqrt(delta)) / (2 * A);
        return 2; // Duas raízes reais e distintas
    } else if (delta == 0) {
        *X1 = -B / (2 * A);
        *X2 = *X1;
        return 1; // Uma única raiz real
    } else {
        return 0; // Nenhuma raiz real
    }
}

int main() {
    float A = 1.0; 
    float B = -3.0; 
    float C = 2.0;
    float X1, X2;

    int num_raizes = raizes(A, B, C, &X1, &X2);

    if (num_raizes == 2) {
        printf("Duas raizes reais e distintas:\nX1 = %.2f\nX2 = %.2f\n", X1,X2);
    } else if (num_raizes == 1) {
        printf("Uma unica raiz real:\n");
        printf("X = %.2f\n", X1);
    } else {
        printf("Nenhuma raiz real.\n");
    }

    return 0;
}
