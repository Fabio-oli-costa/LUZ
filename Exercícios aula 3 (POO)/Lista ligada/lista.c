#include "lista.h"

Lista *criaLista(){ // Método contrutor
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;

    return lista;
}

No *criaNo(int ch){ //
    No *novo = (No*)malloc(sizeof(No));
    novo->prox = NULL;
    novo->chave = ch;

    return novo;
}

void inserirInicio(Lista *lista, int ch){ // métodos da classe
   if(lista == NULL){
      No *novo = criaNo(ch);
      novo->prox = lista->inicio;
      lista->inicio = novo;
      lista->fim = lista->inicio;
   }else if(lista != NULL){
      No *novo = criaNo(ch);
      novo->prox = lista->inicio;
      lista->fim = lista->inicio;
      lista->inicio = novo;
   }
   lista->tam++;
}

void inserirFim(Lista *lista, int ch){
    No *novo = criaNo(ch);
    novo->prox = NULL;

    if(lista->inicio == NULL){
        lista->inicio = novo;
        lista->fim = novo;
    }else{
        lista->fim->prox = novo;
        novo->prox = NULL;
    }
    lista->tam++;
}

void removerInicio(Lista *lista){
    if(lista->inicio != NULL){
        No* aux = lista->inicio->prox;
        lista->inicio->prox = aux->prox;
        free(aux);
        lista->tam--;
    }
}

void removerFim(Lista *lista){
    if(lista->inicio != NULL){
        No* aux = lista->inicio;
        No* ant;
        while (aux->prox != NULL){
            ant = aux;
            aux = aux->prox;
        }
        ant->prox = NULL;
        free(aux);
        lista->tam--;
    }
}

//imprimir a lista

void exibirLista(Lista *lista){
    if(lista->inicio != NULL){
        No* aux = lista->inicio;
        while (aux != NULL){
            printf("%d ", aux->chave);
            aux = aux->prox;
        }
    }
}
