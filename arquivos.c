#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arquivo;

    // FGETC - pega um caractere, retorna ele e avança posição do ponteiro para o próximo.
    arquivo = fopen("fgetc.txt", "r");

    char letra = fgetc(arquivo);
    printf("\nFGETC: %c", letra);

    while (!feof(arquivo))
    {
        letra = fgetc(arquivo);
        printf("%c", letra);
    }
    fclose(arquivo);

    // FPUTC - escreve caractere no arquivo e avança posição do ponteiro para o próximo.
    arquivo = fopen("fputc.txt", "w");

    char frase[] = "o alok esta entregando TUDO hoje";

    for (int i = 0; frase[i] != '\0'; i++)
    {
        fputc(frase[i], arquivo);
    };

    fclose(arquivo);

    // FGETS - lê string do arquivo, armazena a string, retorna 0 quando sucesso e avança o ponteiro para o final da string.
    arquivo = fopen("fgets.txt", "r");

    char string1[26];
    char string2[25];

    //    armaz   tam   origem
    fgets(string1, 26, arquivo);
    fgets(string2, 25, arquivo);

    printf("\n\nFGETS: \n---1: %s \n---2: %s", string1, string2);

    fclose(arquivo);

    // FPUTS - escreve strings no arquivo, retorna EOF quando erro, e numero positivo se sucesso. Avança o ponteiro para o final da string.
    arquivo = fopen("fputs.txt", "w");

    char frase2[] = "o joao lucas eh torto";
    fputs(frase2, arquivo);
    fputs(" --deslocamento do ponteiro", arquivo);

    fclose(arquivo);

    // FSCANF - lê diferentes tipos de dados em arquivos, não move o ponteiro.
    arquivo = fopen("fscanf.txt", "r");

    char nome[10];
    int idade;
    float peso;

    fscanf(arquivo, "%s %d %f", nome, &idade, &peso);

    printf("\n\nFSCANF: \n-Nome: %s \n-Idade: %d \n-Peso: %f", nome, idade, peso);
    fclose(arquivo);

    // FPRINTF - escreve diferentes tipos de dados em arquivos, não move o ponteiro.
    arquivo = fopen("fprintf.txt", "w");

    char nome2[] = "Daniel";
    int idade2 = 20;
    double peso2 = 62.1;

    fprintf(arquivo, "%s tem %d anos e pesa %f quilos.", nome2, idade2, peso2);
    fclose(arquivo);

    // REWIND, FSEEK - deslocam o ponteiro no arquivo. // FTELL - retorna posição do ponteiro // FEOF - retorna true no fim do arquivo, não move ponteiro.

    arquivo = fopen("fseek.txt", "w");

    fputs("(primera frase)", arquivo);

    // Deslocar ponteiro com FSEEK
    fseek(arquivo, -6, SEEK_END); // move -6 posições a partir do final do arquivo
    // SEEK_END - a partir do final
    // SEEK_CUR - a partir da posição atual
    // SEEK_SET - a partir do começo
    // REWIND - move pro início
    fputs(" -segunda frase- ", arquivo);

    printf("\n\nFTELL: posicao do ponteiro eh %ld", ftell(arquivo));
    fclose(arquivo);

    return 0;
}