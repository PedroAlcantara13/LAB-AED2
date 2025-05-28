#include <stdio.h>

int inverterNumero(int n) {
    int invertido = 0;

    while (n > 0) {
        invertido = invertido * 10 + n % 10;
        n /= 10;
    }

    return invertido;
}

int main() {
    int numero;
    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    int numeroInvertido = inverterNumero(numero);
    printf("Numero original: %d\n", numero);
    printf("Numero invertido: %d\n", numeroInvertido);
    return 0;
}