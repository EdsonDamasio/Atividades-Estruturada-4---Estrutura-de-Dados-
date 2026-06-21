#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct {
    char dados[MAX];
    int inicio;
    int fim;
} Fila;

typedef struct {
    char dados[MAX];
    int topo;
} Pilha;

void inicializarFila(Fila *f){
    f->inicio = 0;
    f->fim = -1;
}

void inicializarPilha(Pilha *p){
    p->topo = -1;
}

void enfileirar(Fila *f, char c){
    f->dados[++f->fim] = c;
}

char desenfileirar(Fila *f){
    return f->dados[f->inicio++];
}

void push(Pilha *p, char c){
    p->dados[++p->topo] = c;
}

char pop(Pilha *p){
    return p->dados[p->topo--];
}

int main(){

    char texto[MAX];

    Fila fila;
    Pilha pilha;

    inicializarFila(&fila);
    inicializarPilha(&pilha);

    printf("Digite uma sequencia: ");
    fgets(texto, MAX, stdin);

    for(int i=0; texto[i] != '\0'; i++)
        enfileirar(&fila, texto[i]);

    while(fila.inicio <= fila.fim){

        char c = desenfileirar(&fila);

        if(isalpha(c))
            c = tolower(c);

        push(&pilha, c);
    }

    printf("\nResultado:\n");

    while(pilha.topo != -1)
        printf("%c", pop(&pilha));

    return 0;
}