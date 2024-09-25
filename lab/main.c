#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preenchevet(int numero, int *vet)
{
    for (int i = 0; i < numero; i++)
    {
        vet[i] = rand() % 100;
    }
}

int insercao(int n, int *v)
{
    int count = 0;
    for (int j = 1; j < n; ++j)
    {
        int x = v[j];
        int i;
        for (i = j - 1; i >= 0 && v[i] > x; --i)
        {
            v[i + 1] = v[i]; // COMANDO A SER CONTABILIZADO
            count++;
        }
        v[i + 1] = x;
    }
    return count;
}

int bs(int n, int *vetor)
{
    int c = 0, d, troca, trocou = 1, itera = 0;
    while ((c < (n - 1)) & trocou)
    {
        trocou = 0;
        for (d = 0; d < n - c - 1; d++)
            if (vetor[d] > vetor[d + 1])
            { // COMANDO A SER CONTABILIZADO
                troca = vetor[d];
                vetor[d] = vetor[d + 1];
                vetor[d + 1] = troca;
                trocou = 1;
                itera++;
            }
        c++;
    }
    return itera;
}

void geraarquivo()
{
    FILE *teste, *esforco;
    teste = fopen("testes.txt", "r+");
    esforco = fopen("esforcocomputacional.txt", "w+");

    int numero;
    while (fscanf(teste, "%d\n", &numero) != EOF)
    {
        int *vet = malloc(numero * sizeof(int));
        int *vet2 = malloc(numero * sizeof(int));
        preenchevet(numero, vet);
        for (int i = 0; i < numero; i++)
        {
            vet2[i] = vet[i];
        }

        fprintf(esforco, "%d, %d, %d\n", numero, bs(numero, vet) / numero, insercao(numero, vet2) / numero);

        free(vet);
        free(vet2);
    }
    fclose(teste);
    fclose(esforco);
}

void estatisticas()
{
    FILE *dados = fopen("esforcocomputacional.txt", "r");
    int num, bs, insert;
    fscanf(dados, "%d, %d, %d\n", &num, &bs, &insert);
    int somaBS = bs, somaIN = insert;
    int menorBS = bs, maiorBS = bs, menorIN = insert, maiorIN = insert;
    int itera = 1;
    while (fscanf(dados, "%d, %d, %d\n", &num, &bs, &insert) != EOF)
    {
        somaBS += bs;
        somaIN += insert;
        if (bs > maiorBS)
            maiorBS = bs;
        if (bs < menorBS)
            menorBS = bs;
        if (insert > maiorIN)
            maiorIN = insert;
        if (insert < menorIN)
            menorIN = insert;
        itera++;
    }
    printf("\nMedia BS = %d\nPior BS = %d\nMelhor BS = %d\n\nMedia IN = %d\nPior IN = %d\nMelhor IN = %d\n", somaBS / itera, maiorBS, menorBS, somaIN / itera, maiorIN, menorIN);
    fclose(dados);
}

int main()
{
    srand(time(NULL));

    geraarquivo();
    estatisticas();
}