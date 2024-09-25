#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int numero;
    struct no *prox;
} no;

no *addCabeca(no *plista, int valor)
{
    no *novoNo = (no *)malloc(sizeof(no));
    novoNo->numero = valor;
    novoNo->prox = plista;
    plista = novoNo;
    return plista;
}

no *IncluiCalda(no *pLista, int pValor)
{
    no *pNovoNo, *pAux;
    pNovoNo = (no *)malloc(sizeof(no));
    pNovoNo->numero = pValor;
    pNovoNo->prox = NULL;
    pAux = pLista;
    while (pAux->prox != NULL)
        pAux = pAux->prox;
    pAux->prox = pNovoNo;
    return pLista;
}
void imprimeLista(no *plista)
{
    no *p = plista;
    int a = p->prox->prox;
    //while (p != NULL)
    //{
        printf("%d ", a);
    //}
    //printf("NULL\n");
}

int main()
{
    no *lista = NULL;

    lista = addCabeca(lista, 10);
    lista = addCabeca(lista, 20);
    lista = addCabeca(lista, 30);
    lista = addCabeca(lista, 40);
    lista = IncluiCalda(lista, 50);

    imprimeLista(lista);
}