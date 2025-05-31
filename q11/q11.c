#include <stdio.h>


int buscaBinaria(int vetor[], int tamanho, int alvo) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (vetor[meio] == alvo) {
            return meio; 
        } else if (vetor[meio] < alvo) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1;
}

int main() {
    int vetor[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int alvo;

    printf("Digite o numero a ser buscado: ");
    scanf("%d", &alvo);

    int posicao = buscaBinaria(vetor, tamanho, alvo);

    if (posicao != -1) {
        printf("Numero %d encontrado na posicao %d.\n", alvo, posicao);
    } else {
        printf("NNumero %d nao encontrado no vetor.\n", alvo);
    }

    return 0;
}