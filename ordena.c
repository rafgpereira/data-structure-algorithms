#include <stdio.h>
#include <stdlib.h>

// SELECTION SORT ------------------------

// Percorre toda a lista, identifica o índice do menor numero, e o troca com o elemento da primeira posição, e assim faz respectivamente, avançando as posições do array.

// Complexidade: O(N^2) sempre.

int iteraSelection = 0;
int smallerIndex(int vet[], int tam, int ini)
{
    int min = ini, j;
    for (j = ini + 1; j < tam; j++) // Começa na próxima posição depois do início
    {
        iteraSelection++;
        if (vet[min] > vet[j]) // Verifica se o elemento é menor que o menor atual
            min = j;
    }
    return min; // Retorna o indice do menor elemento encontrado.
}

void selectionSort(int vet[], int tam)
{
    int i, min, aux;
    for (i = 0; i < tam; i++) // Percorre todo o vetor
    {
        min = smallerIndex(vet, tam, i); // Pega o índice do menor elemento a partir da posicao i (evita loop infinito)
        aux = vet[i];                    // Pega o elemento na posição I e aramenza para fazer a troca com o elemento da posição min
        vet[i] = vet[min];
        vet[min] = aux;
    }
}
// -----------------------------------
// QUICK SORT ------------------------

// Complexidade: O(N log N) no melhor caso ou O(N^2) nos piores casos raros
int iteraQuick = 0;
int iteraSepara = 0;
int separa(int v[], int p, int r) // Recebe indice de inicio p e final r
{
    iteraSepara++;
    int c = v[r];               // Escolha do PIVO: aqui, o último elemento do vetor
    int t, j = p;               // J recebe a posição inicial
    for (int k = p; k < r; ++k) // Percorre do início até o final
    {
        if (v[k] <= c) // Analisa se o elemento da iteração atual é menor ou igual ao o PIVO
        {
            t = v[j], v[j] = v[k], v[k] = t; // Se for, trocamos o elemento j com o da iteração atual
            ++j;                             // Incrementa J, para que ele vá para o próximo elemento após o inicial
        }
    }
    t = v[j], v[j] = v[r], v[r] = t; // Por fim, o ultimo elemento é trocado com o j.
    /*
        printf("\nVez separa: %d", iteraSepara);
        printf("\nVez quick: %d", iteraQuick);
        printf("\nP atual: %d\nR atual: %d\nJ atual: %d\nVetor atual: ", p, r, j);
        for (int i = 0; i < 6; i++)
        {
            printf("%d ", v[i]);
        }
    */
    return j;
}

void quicksort(int v[], int p, int r) // Recebe o indice inicial p e indice final r
{
    iteraQuick++;
    if (p < r) // Verifica se o inicio é antes do fim
    {
        int j = separa(v, p, r);
        quicksort(v, p, j - 1);
        quicksort(v, j + 1, r);
    }
}
//----------------------------------------
// INSERTION SORT ------------------------

// Complexidade: O(N) melhor caso, O(N^2) pior caso
int iteraInsertion = 0;
void insertionSort(int list[], int n)
{
    int i, j;
    int next;
    for (i = 1; i < n; i++) // Começa uma posição apos o inicio e vai ate o final
    {
        next = list[i];                                // Armazena o elemento I em next
        for (j = i - 1; j >= 0 && next < list[j]; j--) // Percorre o vetor do começo, desde que j seja maior igual a 0 E next menor que o item J, e decresce J
        {
            iteraInsertion++;
            list[j + 1] = list[j]; // J + 1 recebe J
        }
        list[j + 1] = next; // J+1 recebe next no final
        iteraInsertion++;
    }
}
//---------------------------------------
// BUBBLE SORT --------------------------
// Complexidade: Melhor caso O(N) pior caso O(N^2)
int iteraBubble = 0;
void bubbleSort(int vet[], int tam)
{
    int i, j, temp;
    for (i = tam - 1; i > 0; i--) // Percorre o vetor do fim para o começo
    {
        for (j = 0; j < i; j++) // Percorre o vetor do começo para o fim
        {
            iteraBubble++;
            if (vet[j] > vet[j + 1]) // Analisa se o termo posterior é menor que o atual em J
            {
                temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp; // Troca o posterior com o J atual
            }
        }
    }
}
//------------------------------------------
// MERGE SORT ------------------------------
// Complex: Sempre O(N log N)
int iteraMerge = 0;
void intercala(int p, int q, int r, int v[])
{
    printf("\nP intercala: %d - Q intercala: %d - R intercala: %d\n", p, q, r);

    int *w;
    w = malloc((r - p) * sizeof(int));
    int i = p, j = q;
    int k = 0;
    while (i < q && j < r)
    {
        if (v[i] <= v[j])
            w[k++] = v[i++];
        else
            w[k++] = v[j++];
    }
    while (i < q)
    {
        w[k++] = v[i++];
    }
    while (j < r)
    {
        w[k++] = v[j++];
    }
    for (i = p; i < r; ++i)
        v[i] = w[i - p];
    free(w);
}

void mergesort(int p, int r, int v[])
{
    iteraMerge++;
    printf("Itera %d: P atual: %d - R atual: %d - ", iteraMerge, p, r);
    if (p < r - 1)
    {
        int q = (p + r) / 2;
        printf("Q atual: %d\n", q);
        mergesort(p, q, v);
        mergesort(q, r, v);
        intercala(p, q, r, v);
    } else {
        printf(" - QUEBROU\n");
    }
}
//------------------------------------------

// REPLICANDO SELECTION SORT - COMPLEX: O(N^2)

int calculamin(int v[], int tam, int inicio)
{
    int menor = inicio;
    for (int i = inicio + 1; i < tam; i++)
    {
        if (v[i] < v[menor])
        {
            menor = i;
        }
    }
    return menor;
}

void selectionRafael(int v[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        int min = calculamin(v, tam, i);
        int aux = v[i];
        v[i] = v[min];
        v[min] = aux;
    }
}

int main()
{

    // int vetor1[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int vetor2[] = {0,1,2,3,4,5,6,7,8,9,10};
    // int vetor3[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    // int vetor4[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    // int vetor5[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    /*
    printf("DESORDENADO:");
    for (int i = 0; i < 10; i++)
    {
        printf(" %d", vetor1[i]);
    }
    */
    mergesort(0, 11, vetor2);
    printf("\n\nMERGE SORT (%d):", iteraMerge);
    for (int i = 0; i < 11; i++)
    {
        printf(" %d,", vetor2[i]);
    }

    // quicksort(vetor2, 0, 5);

    /*
    printf("\n\nQUICK SORT (%d):", iteraQuick);
    for (int i = 0; i < 6; i++)
    {
        printf(" %d", vetor2[i]);
    }
    selectionRafael(vetor1, 10);
    insertionSort(vetor3, 10);
    bubbleSort(vetor4, 10);

    printf("\n\nSELECTION SORT (%d):", iteraSelection);
    for (int i = 0; i < 10; i++)
    {
        printf(" %d,", vetor1[i]);
    }
    printf("\n\nINSERTION SORT (%d):", iteraInsertion);
    for (int i = 0; i < 10; i++)
    {
        printf(" %d,", vetor3[i]);
    }
    printf("\n\nBUBBLE (%d):", iteraBubble);
    for (int i = 0; i < 10; i++)
    {
        printf(" %d,", vetor4[i]);
    }
    */
}