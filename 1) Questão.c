#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Estrutura da Fila
typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
} Fila;

// Inicialização da Fila
void inicializar(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
}

// Verifica se a fila está vazia
int filaVazia(Fila *f) {
    return f->inicio > f->fim;
}

// Verifica se a fila está cheia
int filaCheia(Fila *f) {
    return f->fim == MAX - 1;
}

// Enfileirar elemento
void enfileirar(Fila *f, int valor) {

    if (filaCheia(f)) {
        printf("\nFila cheia! Nao e possivel inserir novos elementos.\n");
        return;
    }

    f->fim++;
    f->dados[f->fim] = valor;

    printf("\nNumero %d enfileirado com sucesso!\n", valor);
}

// Desenfileirar elemento
int desenfileirar(Fila *f) {

    if (filaVazia(f)) {
        return -1;
    }

    int valor = f->dados[f->inicio];
    f->inicio++;

    return valor;
}

int main() {

    Fila fila;
    int opcao;
    int numero;

    inicializar(&fila);

    do {

        printf("===== MENU =====\n");
        printf("1 - Enfileirar numero positivo\n");
        printf("2 - Desenfileirar tudo e mostrar apenas os multiplos de 2\n");
        printf("3 - Encerrar programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:

                printf("\nDigite um numero inteiro positivo: ");
                scanf("%d", &numero);

                if (numero > 0) {
                    enfileirar(&fila, numero);
                } else {
                    printf("\nErro! Digite apenas numeros positivos.\n");
                }

                break;

            case 2: {

                if (filaVazia(&fila)) {
                    printf("\nA fila esta vazia!\n");
                    break;
                }

                int encontrou = 0;

                printf("\nMultiplos de 2 encontrados:\n");

                while (!filaVazia(&fila)) {

                    numero = desenfileirar(&fila);

                    if (numero % 2 == 0) {
                        printf("%d\n", numero);
                        encontrou = 1;
                    }
                }

                if (!encontrou) {
                    printf("Nenhum multiplo de 2 encontrado na fila.\n");
                }

                break;
            }

            case 3:

                printf("\nPrograma encerrado.\n");
                break;

            default:

                printf("\nOpcao invalida!\n");
        }

        if (opcao != 3) {
            printf("\nPressione ENTER para continuar...");
            getchar(); // consome o '\n' do scanf
            getchar(); // aguarda ENTER
        }

    } while (opcao != 3);

    return 0;
}