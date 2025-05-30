#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100

typedef struct {
    char nome[100];
    int codigo;
    int quantidade;
    float preco;
} Produto;

void cadastrarProduto(Produto produtos[], int *n) {
    if (*n >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\n");
        return;
    }

    printf("Cadastro do Produto %d\n", *n + 1);
    printf("Nome: ");
    getchar(); // limpar buffer
    fgets(produtos[*n].nome, 100, stdin);
    produtos[*n].nome[strcspn(produtos[*n].nome, "\n")] = '\0'; // remove \n

    printf("Codigo: ");
    scanf("%d", &produtos[*n].codigo);

    printf("Quantidade: ");
    scanf("%d", &produtos[*n].quantidade);

    printf("Preco: ");
    scanf("%f", &produtos[*n].preco);

    (*n)++;
    printf("Produto cadastrado com sucesso!\n");
}

void buscarProduto(Produto produtos[], int n) {
    int cod, i;
    printf("Digite o codigo do produto para buscar: ");
    scanf("%d", &cod);

    for (i = 0; i < n; i++) {
        if (produtos[i].codigo == cod) {
            printf("\nProduto encontrado:\n");
            printf("Nome: %s\n", produtos[i].nome);
            printf("Codigo: %d\n", produtos[i].codigo);
            printf("Quantidade: %d\n", produtos[i].quantidade);
            printf("Preco: R$ %.2f\n", produtos[i].preco);
            return;
        }
    }

    printf("Produto com código %d não encontrado.\n", cod);
}

void listarProdutos(Produto produtos[], int n) {
    if (n == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("\nLista de Produtos:\n");
    for (int i = 0; i < n; i++) {
        printf("Nome: %s | Codigo: %d | Quantidade: %d | Preco: R$ %.2f\n",
               produtos[i].nome, produtos[i].codigo,
               produtos[i].quantidade, produtos[i].preco);
    }
}

int main() {
    Produto produtos[MAX_PRODUTOS];
    int n = 0;
    int opcao;

    do {
        printf("\nMenu Estoque:\n");
        printf("1 - Cadastrar Produto\n");
        printf("2 - Buscar Produto\n");
        printf("3 - Listar Produtos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto(produtos, &n);
                break;
            case 2:
                buscarProduto(produtos, n);
                break;
            case 3:
                listarProdutos(produtos, n);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}