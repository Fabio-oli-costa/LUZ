#include "fila.h"

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
