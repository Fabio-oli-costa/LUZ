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

int main(){
    Pilha pilha;
    int menu = 0, valor;

    pilha.inicio= NULL;
    pilha.tam = 0;

    while(menu != 4){
        printf("\n1 - Verificar a Pilha \n2 - Inserir novo na Pilha \n3 - remover da Pilha\n4 - Sair\n");
        scanf("%d", &menu);

        if(menu == 1){
            printf("\nImpressao da pilha, tamanho: %d \n", pilha.tam);
            exibirPilha(&pilha);
        }else if(menu == 2){
            printf("\nDigite o valor do No a ser inserido: ");
            scanf("%d", &valor);
            inserir(&pilha, valor);
        }else if(menu == 3){
            remover(&pilha);
        }else if(menu == 4){
            printf("\nFechando programa...\n");
            break;
        }else
            printf("\nEscolha de 1 a 4 do Menu");
    }

    return 0;
}
