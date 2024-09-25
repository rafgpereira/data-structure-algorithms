#include <stdio.h>
#include <stdlib.h>

int buscaSequencialDesord(int *V, int n, int chave)
{
    int p, posic = -1;
    for (p = 0; p < n; p++)
    {
        if (chave == V[p])
        {
            posic = p;
            break;
        }
    }
    return posic;
}

int buscaSequencialOrdenada(int *V, int n, int chave, int *iteraS)
{
    int p = 0, posic = -1;
    while (p < n && chave >= V[p])
    {
        (*iteraS)++;
        if (V[p] == chave)
        {
            posic = p;
            break;
        }
        p++;
    }
    return posic;
}

int buscaBinaria(int *V, int n, int chave)
{
    int p, inicio, final, meio;
    inicio = 0;
    final = n - 1;
    while (inicio <= final)
    {
        meio = (inicio + final) / 2;
        if (chave == V[meio])
            return meio;
        if (chave < V[meio])
            final = meio - 1;
        else
            inicio = meio + 1;
    }
    return -1;
}

int main()
{
    int iteraB = 0;
    int iteraS = 0;
    int chave = 12;
    int vector[] = {2, 4, 7, 5, 1, 6, 10, 12, 11, 9, 15, 12};
    int vectorO[] = {1, 2, 3, 4, 5, 6, 7, 8, 12, 12, 14, 15};

    int size = sizeof(vectorO) / sizeof(vectorO[0]);

    int buscaSeqOrd = buscaSequencialOrdenada(vectorO, size, chave, &iteraS);
    int buscaBin = buscaBinaria(vectorO, size, chave, &iteraB);

    printf("Sequencial ordenado: %d, Iteracao: %d\n", buscaSeqOrd, iteraS);

    printf("Binario ordenado: %d, Iteracao: %d", buscaBin, iteraB);
}