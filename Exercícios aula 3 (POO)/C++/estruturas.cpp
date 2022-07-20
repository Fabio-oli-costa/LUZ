#include <iostream>
using namespace std;

class No{
public:
    int chave;
    No* prox;
};

class Estrutura{
private:
    int tam = 0;

public:
    No *inicio = nullptr;

      void aumentaTam(){
        tam = tam +1;
    }
    void diminuiTam(){
        tam = tam -1;
    }
    void mostraTam(){
        cout << tam;
    }

    //Insere a partir do fim
    void inserir(int ch){
        No * novo = new No();
        novo->chave = ch;
        novo->prox = nullptr;

        if(inicio == nullptr){
            inicio = novo;
        }else{
            No * aux = new No();
            aux = inicio;
            while (aux->prox != nullptr){
                aux = aux->prox;
            }
            aux->prox = novo; 
        }
        aumentaTam();
    }

    
    void exibir(){
        if(inicio != nullptr){
            No* aux = inicio;
            while (aux != nullptr){
                cout <<aux->chave <<"  ";
                aux = aux->prox;
            }
        }
    }
};

class Pilha : public Estrutura {
public:
    
    // Pilha remove a partir do fim
    void remover(){
        if(inicio != nullptr){
            if(inicio->prox == nullptr){
                free(inicio);
                inicio = nullptr;
            }else{
                No* aux = inicio;
                No* ant; 
                while (aux->prox != nullptr){
                    ant = aux;
                    aux = aux->prox;
                }
                ant->prox = nullptr;
                free(aux);
            }
            diminuiTam();
        }else
            cout << "\nLista vazia, impossivel remover itens\n";
    }
};

class Fila : public Estrutura {
public:
    //Fila remove a partir do inicio
    void remover(){
        if(inicio != nullptr){
            if(inicio->prox == nullptr){
                free(inicio);
                inicio = nullptr;
            }else{
                No *aux = inicio->prox;
                free(inicio);
                inicio = aux;
            }
            diminuiTam();
        }else
            cout << "\nLista vazia, impossivel remover itens\n";
    }
};

class Lista : public Estrutura {
public:
    void inserirInicio(int ch){
        No * novo = new No();
        novo->chave = ch;
        novo->prox = inicio;
        inicio = novo;
        aumentaTam();
    }
    void removerInicio(){
        if(inicio != nullptr){
            if(inicio->prox == nullptr){
                free(inicio);
                inicio = nullptr;
            }else{
                No *aux = inicio->prox;
                free(inicio);
                inicio = aux;
            }
            diminuiTam();
        }else
            printf("\nLista vazia, impossivel remover itens\n");
    }
    void removerFim(){
    if(inicio != nullptr){
        if(inicio->prox == nullptr){
            free(inicio);
            inicio = nullptr;
        }else{
            No* aux = inicio;
            No* ant;
             while (aux->prox != nullptr){
                ant = aux;
                aux = aux->prox;
            }
            ant->prox = nullptr;
            free(aux);
        }
        diminuiTam();
    }else
        cout << "\nLista vazia, impossivel remover itens\n";
}

    Lista();
    ~Lista();
};

Lista::Lista()
{
}

Lista::~Lista()
{
}

int main(){
    Lista lista;
    Pilha pilha;
    Fila fila;

    //LISTA

    lista.inserirInicio(10);
    lista.inserirInicio(3);
    lista.inserirInicio(6);

    lista.inserir(15);

    lista.removerInicio();
    lista.removerFim(); 

    lista.exibir();

    //PILHA

    pilha.inserir(2);
    pilha.inserir(3);
    pilha.inserir(1);
    pilha.remover();

    cout << "\n";
    pilha.exibir();

    //FILA

    fila.inserir(7);
    fila.inserir(50);
    fila.inserir(200);
    fila.inserir(150);
    fila.remover();

    cout << "\n";
    fila.exibir();
    cout << "\n";
    cout << "tamanho da lista: "; lista.mostraTam();
    cout << "\n";
    cout << "tamanho da lista: "; pilha.mostraTam();
    cout << "\n";
    cout << "tamanho da lista: "; fila.mostraTam();

    return 0;
}