#include <iostream>
#include "Lista.h"
using namespace std;

//NO
No::No(int ch){ //construtor
    this->ch = ch;
    this->prox = nullptr;
};


int No::obterChave(){
    return ch;
};

No* No::obterProx(){
    return prox;
};

void No::setProx(No *p){
    prox = p;
};

//LISTA
Lista::Lista(){
   inicio = nullptr;
   fim = nullptr;
};

Lista::Lista(int ch){
   inicio = new No(ch);
   fim = inicio;
};

Lista::~Lista(){
    while(!vazia()){
        No* aux = inicio;
        inicio = inicio->obterProx();
        delete aux;
    }
};

bool Lista::vazia(){
    return (inicio == nullptr);
};

void Lista::exibir(){
    cout << "\nImprimindo a Elementos...\n";
    No* i = inicio;

    if(vazia())
        cout << "\nEstrutura Vazia!!\n";
    else{
        while(i){ //correndo a lista
            cout << i->obterChave() << endl;
            i = i->obterProx();
        }
    }

};

void Lista::mostraFim(){ //teste
    cout << fim;
};

void Lista::insereInicio(int ch){
    No* novo = new No(ch);
    if(vazia()){
        inicio = novo;
        fim = novo;
    }else{
        novo->setProx(inicio);
        inicio = novo;
    }
};

void Lista::insereFim(int ch){
    No* novo = new No(ch);
    if(vazia()){
        inicio = novo;
        fim = novo;
    }else{
        fim->setProx(novo);
        fim = novo;
    }
};

void Lista::removeFim(){
   if(!vazia()) {
       if(inicio->obterProx() == nullptr)
            inicio = nullptr;
        else if(inicio->obterProx()->obterProx() == nullptr)
            inicio->setProx(nullptr);
        else{
            No* aux = inicio;
            No* ant;

            while(aux->obterProx()){
                ant = aux;
                aux = aux->obterProx();
            }
            ant->setProx(nullptr);
            delete aux;
            fim = ant;
        }
   }
};

void Lista::removeInicio(){
    if(!vazia()) {
        No* aux = inicio;
        inicio = aux->obterProx();
        delete aux;
    };
};

// PILHA
Pilha::exibir(){
    pilha.exibir();
};

void Pilha::inserir(int ch){
    pilha.insereFim(ch);
}
void Pilha::remover(){
    pilha.removeFim();
};
bool Pilha::vazia(){
    pilha.vazia();
};


//FILA
void Fila::exibir(){
    fila.exibir();
};
void Fila::inserir(int ch){
    fila.insereFim(ch);
}
void Fila::remover(){
    fila.removeInicio();
};
bool Fila::vazia(){
    fila.vazia();
};

