#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 100

typedef struct {
    char nome[TAM_NOME];
    int matricula;
    float media;
} Aluno;

int main() {
    int n, i;
    printf("Digite o numero de alunos: ");
    scanf("%d", &n);
    Aluno *alunos = (Aluno *)malloc(n * sizeof(Aluno));
    if (alunos == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf(" %[^\n]", alunos[i].nome);
        printf("Digite a matricula do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].matricula);
        printf("Digite a media do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].media);
    }

    printf("\nLista de Alunos aprovados:\n");
    for (i = 0; i < n; i++) {
        if (alunos[i].media >= 7.0) {
            printf("Nome: %s, Matricula: %d, Media: %.2f\n", alunos[i].nome, alunos[i].matricula, alunos[i].media);
        }
    }

    free(alunos);
    return 0;
}

