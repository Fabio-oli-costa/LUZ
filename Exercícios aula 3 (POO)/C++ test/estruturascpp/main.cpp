#include <iostream>
#include "Lista.h"
using namespace std;


int main(){

    /*
    Lista lista;

    lista.insereFim(40);
    lista.insereInicio(20);
    lista.insereInicio(30);
    lista.insereInicio(50);



    if (lista.vazia())
        cout << "\nLista vazia!\n";
    else
        cout << "\nLista contem elementos\n";

    lista.removeInicio();

    lista.exibir();

    lista.~Lista();

    lista.exibir();
    */

    /* PILHA
    Pilha pilha;

    pilha.inserir(20);
    pilha.inserir(10);

        if (pilha.vazia())
        cout << "\nPilha vazia!\n";
    else
        cout << "\nPilha contem elementos\n";

    pilha.inserir(30);
    pilha.inserir(50);
    pilha.remover();
    pilha.exibir();
    */


    Fila fila;

    fila.inserir(20);
    fila.inserir(10);

        if (fila.vazia())
        cout << "\nFila vazia!\n";
    else
        cout << "\Fila contem elementos\n";

    fila.inserir(30);
    fila.inserir(50);
    fila.remover();
    fila.exibir();


    return 0;
}
