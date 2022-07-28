class No {
private:
    int ch;
    No *prox;
public:
    No(int ch); //construtor

    int obterChave();

    No *obterProx();

    void setProx(No *p);
};

class Lista{
private:
    No* inicio;
    No* fim;
public:
    Lista(); //construtor 1
    Lista(int ch); //construtor 2 - sobrecarga
    virtual ~Lista(); //destrutor
    void exibir();
    void mostraFim();//teste
    bool vazia();
    void insereInicio(int ch);
    void insereFim(int ch);
    void removeFim();
    void removeInicio();

};

class Pilha {
public:
    Lista pilha;
    virtual exibir();
    void inserir(int ch);
    void remover();
     bool vazia();
};

class Fila {
public:
    Lista fila;
    void exibir();
    void inserir(int ch);
    void remover();
    bool vazia();
};
