#include <stdio.h>

int main() {
    int numeros[10];
    int i, j;

    printf("Digite 10 numeros inteiros:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &numeros[i]);
    }

    printf("\nFrequencia de Numeros Diferentes:\n");
    for (i = 0; i < 10; i++) {
        int frequencia = 1;
        if (numeros[i] != -1) {
            for (j = i + 1; j < 10; j++) {
                if (numeros[i] == numeros[j]) {
                    frequencia++;
                    numeros[j] = -1;
                }
            }
            printf("Numero %d: %d vezes\n", numeros[i], frequencia);
        }
    }

    return 0;
}