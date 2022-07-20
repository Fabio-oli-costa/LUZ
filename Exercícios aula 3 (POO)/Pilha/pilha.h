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
}Pilha;


void inserir(Pilha *pilha, int ch);

void remover(Pilha *pilha);

void exibirPilha(Pilha *pilha);
