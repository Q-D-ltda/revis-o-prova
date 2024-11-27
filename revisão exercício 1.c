#include <stdio.h>
#include <string.h>

#define MAX_LIVROS 15

typedef struct {
    int i;
    char Titulo[100];
    char Autor[100];
    int AnoPublicacao;
} Livro;

void cadastrarLivros(Livro bibliotecaLivros[], int *numLivros) {
    if (*numLivros >= MAX_LIVROS) {
        printf("Limite de livros atingido!\n");
        return;
    }

    printf("Digite o titulo do livro: ");
    scanf(" %[^\n]", bibliotecaLivros[*numLivros].Titulo);
    printf("Digite o autor do livro: ");
    scanf(" %[^\n]", bibliotecaLivros[*numLivros].Autor);
    printf("Digite o ano de publicacao: ");
    scanf("%d", &bibliotecaLivros[*numLivros].AnoPublicacao);

    (*numLivros)++;
}

void buscarLivroPorAno(Livro bibliotecaLivros[], int numLivros, int ano) {
    int i, encontrou = 0; 
    for (i = 0; i < numLivros; i++) {
        if (bibliotecaLivros[i].AnoPublicacao == ano) {
            printf("Titulo: %s, Autor: %s, Ano: %d\n", bibliotecaLivros[i].Titulo, bibliotecaLivros[i].Autor, bibliotecaLivros[i].AnoPublicacao);
            encontrou = 1;
        }
    }
    if (!encontrou) {
        printf("Nenhum livro encontrado para o ano %d.\n", ano);
    }
}

void exibirTodosLivros(Livro bibliotecaLivros[], int numLivros) {
    int i;  
    for (i = 0; i < numLivros; i++) {
        printf("Titulo: %s, Autor: %s, Ano: %d\n", bibliotecaLivros[i].Titulo, bibliotecaLivros[i].Autor, bibliotecaLivros[i].AnoPublicacao);
    }
}

int main() {
    Livro bibliotecaLivros[MAX_LIVROS];
    int numLivros = 0;
    int opcao, ano;

    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar livro\n");
        printf("2. Buscar livros por ano\n");
        printf("3. Exibir todos os livros\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarLivros(bibliotecaLivros, &numLivros);
                break;
            case 2:
                printf("Digite o ano de publicacao para buscar: ");
                scanf("%d", &ano);
                buscarLivroPorAno(bibliotecaLivros, numLivros, ano);
                break;
            case 3:
                exibirTodosLivros(bibliotecaLivros, numLivros);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção invalida!\n");
        }
    } while(opcao != 4);

    return 0;
}


