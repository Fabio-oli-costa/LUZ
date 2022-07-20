#include "lista.h"

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

