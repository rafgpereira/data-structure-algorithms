/*
-------RESUMO PROVA 2 EDA-------

-> COMPLEXIDADE

 Principais complexidades em ordem de tempo (menor -> maior):

 - O(1) -> constante: iterações comuns, atribuição, if, loop com tamanho conhecido...
 - O(log N) -> logarítmica: algoritmos com divisões, busca binária...
 - O(N) -> linear: loops com tamanho N, percorrer dados de tamanho N.
 - O(N log N) -> algoritmos que combinam partes lineares com logarítmicas, merge sort...
 - O(N^2) -> quadrática: algorítmos lineares aninhados, loops acoplados...
 - O(2^N) -> exponencial: algoritmos que a cada passo os passos dobram.
 - O(N!) -> fatorial: permutações, combinações, buscas completas.

 Passos para analisar complexidade:
    1 -> Analisar e contar a complexidade de cada estrutura
    2 -> Ignorar as constantes
    3 -> Considerar apenas o termo de maior grau (expoente)

-> ALGORITMOS DE BUSCA

 - Busca Sequencial Desordenada
    Complexidade: O(N)
*/
int BuscaSequencialDesordenada(int *V, int n, int chave)
{
    int p, posic = -1;
    for (p = 0; p < n; p++)
    {
        if (chave == V[p])
        {
            posic = p;
            break; // O break faz com que se retorne o índice primeiro elemento encontrado, sem ele, retorna-se o último.
        }
    }
    return posic;
}
/*
 - Busca Sequencial Ordenada
    Complexidade: O(N)
*/
int BuscaSequencialOrdenada(int *V, int n, int chave)
{
    int p = 0, posic = -1;
    while (p < n && chave >= V[p])
    {
        if (V[p] == chave)
        {
            posic = p;
            break;
        }
        p++;
    }
    return posic;
}
/*
 - Busca Binária (Ordenada)
    Complexidade: O(log N)
*/
int BuscaBinaria(int *V, int n, int chave)
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
/*
-> MÉTODOS DE ORDENAÇÃO

 - Selection Sort
    Complexidade: O(N^2)
    Procura o menor elemento no vetor e o coloca no começo.
    Loops aninhados.

 - Quick Sort
    Complexidade: O(N log N) ou O(N^2) - pior
    Escolhe um pivô e ordena os subvetores a partir dele.
    Recursivo.

 - Insertion Sort
    Complexidade: O(N) melhor ou O(N^2) pior
    Percorre o vetor comparando um par e volta verificando e trocando.
    Loops aninhados.

 - Bubble Sort
    Complexidade: O(N) melhor ou O(N^2) pior
    Compara elemento a elemento e troca
    Loops aninhados.

 - Merge Sort
    Complexidade: O(N log N)
    Quebra o vetor e depois o intercala ordenado.
    Recursivo.

-> LISTAS

 - Lista encadeada
    Estrutura de dados que aramzena um valor e o endereço do próximo valor, é dinâmica e pode ser incrementada e decrementada no início, meio e fim.
    Percorrer: complexidade O(N)

 - Lista duplamente encadeada
    Os elementos armazenam o endereço do anterior e do próximo, possibilitando percorre-la de trás para frente.
    Reduz complexidade para para remover último elemento: O(1)

 - Lista circular
    Pode ser simples ou duplamente encadeada, o primeiro elemento refere-se ao último e/ou vice-versa. Não tem início e fim.

-> PILHA

    Estrutura da qual só se pode adicionar ou remover elementos no topo, para alcançar o mais de baixo, devem ser retirados todos os de cima.
    Operações elementares: esvazia, empilha, desempilha, consulta 1º elemento.

-> FILA

    Não permite acesso aleatório aos elementos. Para incluir, é feito um enfileiramento de um dos lados, e para excluir é feito um desenfileiramento do outro lado.
    Operações elementares: esvazia, enfileira, desenfileira, consulta 1º elemento.
    Pode-se implementar utilizando vetores circulares ou listas.

*/

// Treinando algoritmos de busca

int BuscaSequencialDesord(int *V, int tam, int chave)
{
    int pos = -1;
    for (int i = 0; i < tam; i++)
    {
        if (V[i] == chave)
        {
            pos = i;
            break;
        }
    }
    return pos;
}
// 2 6 8    5
int BuscaSequencialOrd(int *V, int tam, int chave)
{
    int pos = -1, i = 0;
    while (i < tam && V[i] <= chave)
    {
        if (chave == V[i])
        {

            pos = i;
            break;
        }
        i++;
    }
    return pos;
}

int buscaBinaria(int *V, int tam, int chave){
    int inicio = 0;
    int final = tam-1;
    int meio;
    int pos = -1;
    while(inicio <= final){
        meio = (inicio + final) /2;
        if(chave == V[meio]){
            pos = meio;
            break;
        } 
        if(chave < V[meio]){
            final = meio - 1;
        }
        else{
            inicio = meio + 1;
        }
    }
    return pos;
}