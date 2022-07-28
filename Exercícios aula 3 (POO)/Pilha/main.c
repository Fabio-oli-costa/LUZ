#include "pilha.h"


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
