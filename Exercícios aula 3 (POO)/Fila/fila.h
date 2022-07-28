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

void inserir(Fila *fila, int ch);

void remover(Fila *fila);

void exibirFila(Fila *fila);
