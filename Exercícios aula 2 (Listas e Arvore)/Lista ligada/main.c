#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct{ // Classe
    struct No *prox;
    int chave;
}No;

typedef struct{ // Classe
    No *inicio; // Composição
    No *fim;
    int tam;
}Lista;

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

void inserirInicio(Lista *lista, int ch){
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

    if(lista->inicio == NULL){
        lista->inicio = novo;
        lista->fim = novo;
    }else{
        lista->fim->prox = novo;
    }
    lista->tam++;
}

void removerInicio(Lista *lista){
    if(lista->inicio != NULL){
        No* aux = lista->inicio;
        lista->inicio = aux->prox;
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

int main(){
    //Lista lista;
    int menu = 0, valor;
    Lista *lista1 = criaLista();

    //lista.inicio = NULL;
    //lista.tam = 0;

    while(menu != 6){
        printf("\n1 - Verificar a Lista \n2 - Inserir novo No no inicio da Lista \n3 - Inserir novo No no final da Lista \n4 - Remover do inicio\n5 - Remover do final\n6 - Sair\n");
        scanf("%d", &menu);

        if(menu == 1){ // não funciona depois do 4 por algum motivo;
            printf("\nImpressao da lista, tamanho: %d \n", lista1->tam); // era &lista1.tam e dps &lista1->tam
            exibirLista(&*lista1);
        }else if(menu == 2){
            printf("\nDigite o valor do No a ser inserido no inicio: ");
            scanf("%d", &valor);
            inserirInicio(&*lista1, valor);
        }else if(menu == 3){
            printf("\nDigite o valor do No a ser inserido no final: ");
            scanf("%d", &valor);
            inserirFim(&*lista1, valor);
        }else if(menu == 4){
            removerInicio(&*lista1);
        }else if(menu == 5){
            removerFim(&*lista1);
        }else if(menu == 6){
            printf("\nFechando programa...\n");
            break;
        }else
            printf("\nEscolha de 1 a 6 do Menu");
    }
    return 0;
}
