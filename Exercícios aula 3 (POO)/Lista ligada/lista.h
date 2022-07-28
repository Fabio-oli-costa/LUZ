#include <stdio.h>
#include <stdlib.h>

typedef struct{ // Classe
    struct No *prox;
    int chave;
}No;

typedef struct{ // Classe
    No *inicio; // Composição
    No *fim;
    int tam;
}Lista;

Lista *criaLista();

No *criaNo(int ch);

void inserirInicio(Lista *lista, int ch);

void inserirFim(Lista *lista, int ch);

void removerInicio(Lista *lista);
void removerFim(Lista *lista);

//imprimir a lista

void exibirLista(Lista *lista);
