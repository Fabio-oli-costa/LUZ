#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct{
    struct No *prox;
    int chave;
}No;

typedef struct{
    No * inicio;
    int tam;
}Fila;

void inserir(Fila *fila, int ch){
    No * novo = (No*)malloc(sizeof(No));
    novo->chave = ch;
    novo->prox = fila->inicio;
    fila->inicio = novo;
    fila->tam++;
}

void remover(Fila *fila){
    if(fila->inicio != NULL){
        No* aux = fila->inicio;
        No* ant;
        while (aux->prox != NULL){
            ant = aux;
            aux = aux->prox;
        }
        ant->prox = NULL;
        free(aux);
        fila->tam--;
    }
}

//imprimir a Fila

void exibirFila(Fila *fila){
    if(fila->inicio != NULL){
        No* aux = fila->inicio;
        while (aux != NULL){
            printf("%d ", aux->chave);
            aux = aux->prox;
        }
    }
}

int main(){
    Fila fila;
    int menu = 0, valor;

    fila.inicio= NULL;
    fila.tam = 0;

    while(menu != 4){
        printf("\n1 - Verificar a Fila \n2 - Inserir novo na Fila \n3 - remover da Fila \n4 - Sair\n");
        scanf("%d", &menu);

        if(menu == 1){
            printf("\nImpressao da Fila, tamanho: %d \n", fila.tam);
            exibirFila(&fila);
        }else if(menu == 2){
            printf("\nDigite o valor do No a ser inserido: ");
            scanf("%d", &valor);
            inserir(&fila, valor);
        }else if(menu == 3){
            remover(&fila);
        }else if(menu == 4){
            printf("\nFechando programa...\n");
            break;
        }else
            printf("\nEscolha de 1 a 4 do Menu");
    }

    return 0;
}
