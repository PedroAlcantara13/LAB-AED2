#include <stdio.h>
#include <stdbool.h>

int main() {
    int A[5], B[5];
    int i, j;

    printf("Digite 5 numeros inteiros para o vetor A:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &A[i]);
    }
    printf("Digite 5 numeros inteiros para o vetor B:\n"); 
    for (i = 0; i < 5; i++) {
        scanf("%d", &B[i]);
    }

    printf("\nElementos iguais em A e B:\n");
    bool found;
    for (i = 0; i < 5; i++) {
        found = false;
        for (j = 0; j < 5; j++) {
            if (A[i] == B[j]) {
                found = true;
                break;
            }
        }
        if (found) {
            printf("%d ", A[i]);
        }
    }

    return 0;
}