#include <stdio.h>
#include <stdlib.h>

typedef struct _arvore
{
    int info;
    struct _arvore *esq;
    struct _arvore *dir;
} Arvore;

Arvore *cria_arv_vazia()
{
    return NULL;
}

Arvore *inserir(Arvore *a, int v)
{
    if (a == NULL)
    {
        a = (Arvore *)malloc(sizeof(Arvore));
        a->info = v;
        a->esq = NULL;
        a->dir = NULL;
    }
    else if (v < a->info)
    {
        a->esq = inserir(a->esq, v);
    }
    else
    {
        a->dir = inserir(a->dir, v);
    }
    // printf("Valor da raiz: %d Valor NO esquerda: %d Valor NO direita: %d\n", a->info, a->esq ? a->esq->info : 0, a->dir ? a->dir->info : 0);
    return a;
}

void pre_ordem(Arvore *arv)
{
    if (arv != NULL)
    {
        printf("%d, ", arv->info);
        pre_ordem(arv->esq);
        pre_ordem(arv->dir);
    }
}

void in_ordem(Arvore *arv)
{
    if (arv != NULL)
    {
        in_ordem(arv->esq);
        printf("%d, ", arv->info);
        in_ordem(arv->dir);
    }
}

void pos_ordem(Arvore *arv)
{
    if (arv != NULL)
    {
        pos_ordem(arv->esq);
        pos_ordem(arv->dir);
        printf("%d, ", arv->info);
    }
}

int buscar(Arvore *a, int v)
{
    if (a == NULL)
    {
        return 0;
    }
    else if (v < a->info)
    {
        return buscar(a->esq, v);
    }
    else if (v > a->info)
    {
        return buscar(a->dir, v);
    }
    else
    {
        return 1;
    }
}


Arvore *Remover(Arvore *a, int v)
{
    if (a == NULL)
    {
        return NULL;
    }
    else
    {
        if (a->info > v)
        {
            a->esq = Remover(a->esq, v);
        }
        else if (a->info < v)
        {
            a->dir = Remover(a->dir, v);
        }
        else
        {
            if ((a->esq == NULL) && (a->dir == NULL))
            {
                free(a);
                a = NULL;
            }
            else if (a->dir == NULL)
            {
                Arvore *tmp = a;
                a = a->esq;
                free(tmp);
            }
            else if (a->esq == NULL)
            {
                Arvore *tmp = a;
                a = a->dir;
                free(tmp);
            }
            else
            {
                Arvore *tmp = a->esq;
                while (tmp->dir != NULL)
                {
                    tmp = tmp->dir;
                }
                a->info = tmp->info;
                tmp->info = v;
                a->esq = Remover(a->esq, v);
            }
        }
    }
    return a;
}

int main()
{

    Arvore *a = cria_arv_vazia();

    inserir(a, 50);
    printf("Valor da raiz: %d Valor NO esquerda: %d Valor NO direita: %d\n", a->info, a->esq ? a->esq->info : 0, a->dir ? a->dir->info : 0);

    inserir(a, 30);
    printf("Valor da raiz: %d Valor NO esquerda: %d Valor NO direita: %d\n", a->info, a->esq ? a->esq->info : 0, a->dir ? a->dir->info : 0);

    inserir(a, 90);
    printf("Valor da raiz: %d Valor NO esquerda: %d Valor NO direita: %d\n", a->info, a->esq ? a->esq->info : 0, a->dir ? a->dir->info : 0);

    inserir(a, 20);
    printf("Valor da raiz: %d Valor NO esquerda: %d Valor NO direita: %d\n", a->info, a->esq ? a->esq->info : 0, a->dir ? a->dir->info : 0);

    inserir(a, 40);
    printf("Valor da raiz: %d Valor NO esquerda: %d Valor NO direita: %d\n", a->info, a->esq ? a->esq->info : 0, a->dir ? a->dir->info : 0);

    inserir(a, 95);
    printf("Valor da raiz: %d Valor NO esquerda: %d Valor NO direita: %d\n", a->info, a->esq ? a->esq->info : 0, a->dir ? a->dir->info : 0);

    // a = inserir(a, 10);
    // a = inserir(a, 35);
    // a = inserir(a, 45);

    in_ordem(a);
    return 0;
}