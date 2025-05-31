#include <stdio.h>
#include <string.h>

#define MAX_CONTATOS 100

typedef struct {
    char nome[100];
    char telefone[20];
    char email[100];
} Contato;

void adicionarContato(Contato contatos[], int *n) {
    if (*n >= MAX_CONTATOS) {
        printf("Agenda cheia!\n");
        return;
    }

    printf("Nome: ");
    getchar();
    fgets(contatos[*n].nome, 100, stdin);
    contatos[*n].nome[strcspn(contatos[*n].nome, "\n")] = '\0';

    printf("Telefone: ");
    fgets(contatos[*n].telefone, 20, stdin);
    contatos[*n].telefone[strcspn(contatos[*n].telefone, "\n")] = '\0';

    printf("Email: ");
    fgets(contatos[*n].email, 100, stdin);
    contatos[*n].email[strcspn(contatos[*n].email, "\n")] = '\0';

    (*n)++;
    printf("Contato adicionado com sucesso!\n");
}

void buscarContato(Contato contatos[], int n) {
    char nomeBusca[100];
    int encontrado = 0;

    printf("Digite o nome do contato para buscar: ");
    getchar(); 
    fgets(nomeBusca, 100, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    for (int i = 0; i < n; i++) {
        if (strcmp(contatos[i].nome, nomeBusca) == 0) {
            printf("\nContato encontrado:\n");
            printf("Nome: %s\n", contatos[i].nome);
            printf("Telefone: %s\n", contatos[i].telefone);
            printf("Email: %s\n", contatos[i].email);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Contato \"%s\" nao encontrado.\n", nomeBusca);
    }
}

void exibirContatos(Contato contatos[], int n) {
    if (n == 0) {
        printf("Nenhum contato cadastrado.\n");
        return;
    }

    printf("\nLista de Contatos:\n");
    for (int i = 0; i < n; i++) {
        printf("Nome: %s | Telefone: %s | Email: %s\n",
               contatos[i].nome, contatos[i].telefone, contatos[i].email);
    }
}

int main() {
    Contato contatos[MAX_CONTATOS];
    int n = 0;
    int opcao;

    do {
        printf("\nMenu da Agenda:\n");
        printf("1 - Adicionar Contato\n");
        printf("2 - Buscar Contato por Nome\n");
        printf("3 - Exibir Todos os Contatos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarContato(contatos, &n);
                break;
            case 2:
                buscarContato(contatos, n);
                break;
            case 3:
                exibirContatos(contatos, n);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcaoo invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}