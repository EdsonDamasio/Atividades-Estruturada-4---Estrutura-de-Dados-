#include <stdio.h>

#define MAX 100

typedef struct {
	int dados[MAX];
	int inicio;
	int fim;
	int qtd;
} FilaCircular;

void inicializar(FilaCircular *f) {

	f->inicio = 0;
	f->fim = 0;
	f->qtd = 0;
}

void enfileirar(FilaCircular *f, int valor) {

	if(f->qtd < MAX) {

		f->dados[f->fim] = valor;

		f->fim = (f->fim + 1) % MAX;

		f->qtd++;
	}
}

int desenfileirar(FilaCircular *f) {

	int valor = f->dados[f->inicio];

	f->inicio = (f->inicio + 1) % MAX;

	f->qtd--;

	return valor;
}

int main() {

	FilaCircular fila;

	inicializar(&fila);

	int op, valor;

	do {
		printf("===== MENU =====\n");
		printf("\n1-Enfileirar");
		printf("\n2-Desenfileirar e mostrar dobro");
		printf("\n3-Desenfileirar tudo");
		printf("\n4-Sair\n");

		scanf("%d",&op);

		switch(op) {

		case 1:

			scanf("%d",&valor);

			if(valor != 0)
				enfileirar(&fila, valor);

			break;

		case 2:

			if(fila.qtd > 0) {

				valor = desenfileirar(&fila);

				printf("Dobro = %d\n", valor * 2);
			}

			break;

		case 3:

			while(fila.qtd > 0)
				printf("%d ", desenfileirar(&fila));

			printf("\n");

			break;
		}

	} while(op != 4);

	return 0;
}