#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct No *esquerda, *direita;
} No;

typedef struct
{
    No *raiz;
} ArvoreBin;

ArvoreBin *criaArvore()
{
    ArvoreBin *arvore = (ArvoreBin*)malloc(sizeof(ArvoreBin));
    arvore->raiz = NULL;
    return  arvore;
}

No *criaNo(int ch)
{
    No *novoNo = (No*)malloc(sizeof(No));
    novoNo->chave = ch;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

void inserirEsquerda(No *no, int ch)
{
    if(ch != no->chave)
    {
        if(ch < no->chave)
        {
            if(no->esquerda == NULL)
            {
                No *novo = criaNo(ch);
                no->esquerda = novo;
            }
            else
            {
                inserirEsquerda(no->esquerda, ch);
            }
        }
        else
        {
            if(no->direita == NULL)
            {
                No *novo = criaNo(ch);
                no->direita = novo;
            }
            else
            {
                inserirDireita(no->direita, ch);
            }
        }
    }
    else
    {
        printf("\nNegado, elemento ja existente");
    }
}

void inserirDireita(No *no, int ch)
{
    if(ch != no->chave)
    {
        if(ch > no->chave)
        {
            if(no->direita == NULL)
            {
                No *novo = criaNo(ch);
                no->direita = novo;
            }
            else
            {
                inserirDireita(no->direita, ch);
            }
        }
        else
        {
            if(no->esquerda == NULL)
            {
                No *novo = criaNo(ch);
                no->esquerda = novo;
            }
            else
            {
                inserirEsquerda(no->esquerda, ch);
            }
        }
    }
    else
    {
        printf("\nNegado, elemento ja existente");
    }
}

void inserirNo(ArvoreBin *arvore, int ch) // ver o bug da raiz
{
    if(arvore->raiz == NULL)
    {
        No *novo = criaNo(ch);
        arvore->raiz = novo;
    }
    else
    {
        if(ch != arvore->raiz->chave)
        {
            if(ch < arvore->raiz->chave)
            {
                if(arvore->raiz->esquerda == NULL)
                {
                    No *novo = criaNo(ch);
                    arvore->raiz->esquerda = novo;
                }
                else
                {
                    inserirEsquerda(arvore->raiz->esquerda, ch);
                }
            }
            else
            {
                if(arvore->raiz->direita == NULL)
                {
                    No *novo = criaNo(ch);
                    arvore->raiz->direita = novo;
                }
                else
                {
                    inserirDireita(arvore->raiz->direita, ch);
                }
            }
        }
        else
        {
            printf("\nNegado, elemento ja existente");
        }
    }
}


No *excluiNo(No *raiz, int ch)
{
    if(raiz == NULL)
    {
        printf("Valor nao encontrado!\n");
        return NULL;
    }
    else     // procura o nó a remover
    {
        if(raiz->chave == ch)
        {
            // remove nós folhas
            if(raiz->esquerda == NULL && raiz->direita == NULL)
            {
                free(raiz);
                printf("Elemento folha removido: %d !\n", ch);
                return NULL;
            }
            else
            {
                // remover nós com 2 filhos
                if(raiz->esquerda != NULL && raiz->direita != NULL)
                {
                    No *aux = raiz->esquerda;
                    while(aux->direita != NULL)
                        aux = aux->direita;
                    raiz->chave = aux->chave;
                    aux->chave = ch;
                    printf("Elemento trocado: %d !\n", ch);
                    raiz->esquerda = excluiNo(raiz->esquerda, ch);
                    return raiz;
                }
                else
                {
                    // remover nós com 1 filho
                    No *aux;
                    if(raiz->esquerda != NULL)
                        aux = raiz->esquerda;
                    else
                        aux = raiz->direita;
                    free(raiz);
                    printf("Elemento com 1 filho removido: %d !\n", ch);
                    return aux;
                }
            }
        }
        else
        {
            if(ch < raiz->chave)
                raiz->esquerda = excluiNo(raiz->esquerda, ch);
            else
                raiz->direita = excluiNo(raiz->direita, ch);
            return raiz;
        }
    }
}

No *buscaNarvore(No *raiz, int ch) // talvez raiz seja trocado por arvore->raiz
{
    if(raiz != NULL )
    {
        if(ch == raiz->chave)
        {
            return raiz;
        }
        else if(ch < raiz->chave)
        {
            return buscaNarvore(raiz->esquerda, ch);
        }
        else
        {
            return buscaNarvore(raiz->direita, ch);
        }
    }
    return NULL;
}

void imprmiOrdem(No *raiz)
{
    if(raiz != NULL)
    {
        imprmiOrdem(raiz->esquerda);
        printf("%d ", raiz->chave);
        imprmiOrdem(raiz->direita);
    }
}

void imprimiPreOrdem(No *raiz)
{
    if(raiz != NULL)
    {
        printf("%d ", raiz->chave);
        imprimiPreOrdem(raiz->esquerda);
        imprimiPreOrdem(raiz->direita);
    }
}

void imprimiPosOrdem(No *raiz)
{
    if(raiz != NULL)
    {
        imprimiPosOrdem(raiz->esquerda);
        imprimiPosOrdem(raiz->direita);
        printf("%d ", raiz->chave);
    }
}

void deletaNos(No *no)
{
    if(no != NULL){
        deletaArvore(no->esquerda);
        delataArvore(no->direita);
        free(no);
    }
}
void deletaArvore(ArvoreBin *arvore){
    deletaNos(arvore->raiz);
    free(arvore);
}


int main()
{
    int menu, chave;
    int res = NULL;
    No *busca = NULL;
    char nomeArvore[20];
    ArvoreBin *arvore1 = criaArvore();

    do
    {
        printf("\n1 - Inserir no na arvore\n2 - Imprimir arvore em ordem\n3 - Imprimir arvore em pre-ordem\n4 - Imprimir arvore em pos-ordem\n5 - Buscar na arvore\n6 - Excluir no\n7 - Deletar arvore\n8 - Sair\n");
        scanf("%d", &menu);

        switch(menu)
        {
        case 1:
            printf("Digite o valor da chave: ");
            scanf("%d", &chave);
            inserirNo(arvore1, chave);
            break;
        case 2:
            printf("\nImperssao da arvore binaria:\n");
            imprmiOrdem(arvore1->raiz);
            break;
        case 3:
            printf("\nArvore binaria em pre-ordem:\n");
            imprimiPreOrdem(arvore1->raiz);
            break;
        case 4:
            printf("\nArvore binaria em pos-ordem:\n");
            imprimiPosOrdem(arvore1->raiz);
            break;
        case 5:
            printf("\nQual chave deseja buscar? ");
            scanf("%d", &chave);
            busca = buscaNarvore(arvore1->raiz, chave);
            if(busca)
                printf("\n\tResultado da busca: %d\n", busca->chave);
            else
                printf("\n\tValor nao encontrado\n");
            break;
        case 6:
            printf("Digite uma chave a ser removida: ");
            scanf("%d", &chave);
            excluiNo(arvore1->raiz, chave);
            break;
        case 7:
            printf("Deseja mesmo deletar a arvore ?\n1 - Sim\n2 - Nao\n");
            scanf("%d", &res);
            if(res == 1)
            {
                deletaArvore(arvore1);
                printf("\nArvore deletada. Fechando o programa...\n");
                break;
                printf("\n gostaria de criar outra arvora?\n");
                scanf("%d ", &res);
                if(res == 1){
                    printf("\n qual o nome da arvore ?\n");
                    scanf("")
                }
            }
            else if(res == 2)
            {
                printf("\nA arvore nao foi deleta.\n");
                break;
            }
        case 8:
            printf("\nSaindo do programa...\n");
            break;
        default:
            printf("\nOpção Invalida...\n");
        }
    }
    while(menu != 8);
    return 0;
}
