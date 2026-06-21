#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct{
    char dados[MAX];
    int inicio;
    int fim;
}FilaChar;

typedef struct{
    int dados[MAX];
    int inicio;
    int fim;
    int qtd;
}FilaInt;

int main(){

    char texto[MAX];

    FilaChar A = {{0},0,-1};

    FilaInt B = {{0},0,0,0};

    printf("Digite uma sequencia: ");
    fgets(texto, MAX, stdin);

    for(int i=0; texto[i] != '\0'; i++){

        if(isalpha(texto[i])){

            A.dados[++A.fim] = texto[i];
        }

        else if(isdigit(texto[i])){

            B.dados[B.fim] = texto[i] - '0';

            B.fim = (B.fim + 1) % MAX;

            B.qtd++;
        }
    }

    printf("\nFila B:\n");

    while(B.qtd > 0){

        printf("%d ", B.dados[B.inicio]);

        B.inicio = (B.inicio + 1) % MAX;

        B.qtd--;
    }

    printf("\n\nFila A:\n");

    while(A.inicio <= A.fim)
        printf("%c ", A.dados[A.inicio++]);

    return 0;
}