#include <stdio.h>
#include <string.h>
#include <ctype.h>

int ehPalindromo(const char *str) {
    int inicio = 0;
    int fim = strlen(str) - 1;

    while (inicio < fim) {
        
        while (inicio < fim && !isalnum(str[inicio])) {
            inicio++;
        }
        while (inicio < fim && !isalnum(str[fim])) {
            fim--;
        }

        
        if (tolower(str[inicio]) != tolower(str[fim])) {
            return 0; 
        }
        inicio++;
        fim--;
    }
    return 1; 
}

int main() {
    char frase[1000];

    printf("Digite uma palavra: ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0'; 

    if (ehPalindromo(frase)) {
        printf("A palavra e um palindromo.\n");
    } else {
        printf("A palavra nao e um palindromo.\n");
    }

    return 0;
}