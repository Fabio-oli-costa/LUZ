#include "pilha.h"

void inserir(Pilha *pilha, int ch){
    No *novo = (No*)malloc(sizeof(No));
    novo->chave = ch;
    novo->prox = NULL;

    if(pilha->inicio == NULL){
        pilha->inicio = novo;
    }else{
        No *aux = (No*)malloc(sizeof(No));
        aux = pilha->inicio;
        while (aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    pilha->tam++;
}

void remover(Pilha *pilha){
    if(pilha->inicio != NULL){
        No* aux = pilha->inicio;
        No* ant;
        while (aux->prox != NULL){
            ant = aux;
            aux = aux->prox;
        }
        ant->prox = NULL;
        free(aux);
        pilha->tam--;
    }
}

//imprimir a pilha

void exibirPilha(Pilha *pilha){
    if(pilha->inicio != NULL){
        No* aux = pilha->inicio;
        while (aux != NULL){
            printf("%d ", aux->chave);
            aux = aux->prox;
        }
    }
}


