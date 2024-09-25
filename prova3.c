#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Q1(int matricula)
{
    int n, retorno = 0;
    while (matricula != 0)
    {
        n = matricula % 10;
        retorno = retorno * 10 + n;
        matricula = matricula / 10;
    }
    return retorno;
}

void Q2(char *str)
{
    int n = strlen(str);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (str[i] < str[j])
            {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

char *Q3(int *M, char *NC)
{
    char *code = (char *)malloc(9 * sizeof(char));
    for (int i = 0; i < 9; i++)
    {
        code[i] = NC[M[i] % 9];
        if (code[i] == ' ')
            code[i] = '$';
    }
    return code;
}

int Verifica(char c)
{
    if ((c >= 'a' && c <= 'z') &&
        (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u'))
        return 1; // true
    else
        return 0; // false
}

int Q4(char *NC, char L, int pos)
{
    if (NC[0] == '\0' || pos < 0 || pos >= strlen(NC) - 1)
    {
        return -1;
    }

    if (NC[pos] == L && Verifica(NC[pos + 1]))
    {
        return pos;
    }

    return Q4(NC, L, pos + 1);
}

int Q5(char *NC, int R)
{
    int r;
    FILE *A = fopen("Saida.txt", "w");

    for (int i = 0; i < R; i++)
    {
        fprintf(A, "%s", NC);
    }

    fclose(A);

    A = fopen("Saida.txt", "r");
    fseek(A, 0, SEEK_END);
    r = ftell(A);
    fclose(A);

    return r;
}

void Q6(char *str, char ch, int index)
{
    if (str[index] == '\0')
    {
        return;
    }

    if (str[index] == ch)
    {
        int i = index;

        while (str[i] != '\0')
        {
            str[i] = str[i + 1];
            i++;
        }

        Q6(str, ch, index);
    }
    else
    {
        Q6(str, ch, index + 1);
    }
}

/*int main()
{

    printf("Questao 01: %d\n", Q1(222015248));

    char pNome[] = "rafael";
    Q2(&pNome[2]);
    printf("Questao 02: %s\n", pNome);

    int matricula[] = {2, 2, 2, 0, 1, 5, 2, 4, 8};
    char NC[] = "rafael gomes pereira";
    printf("Questao 03: %s\n", Q3(matricula, NC));

    char nomeC[] = "rafael gomes pereira";
    printf("Questao 04: %d\n", Q4(nomeC, 'a', 0));

    char nomeComp[] = "rafael gomes pereira";
    printf("Questao 05: %d\n", Q5(&nomeComp[4], 10));

    Q6(NC, NC[5], 0);
    printf("Questao 06: %s\n", NC);
}*/

int main()
{

    printf("Questao 01: %d\n", Q1(222025324));

    char pNome[] = "joao";
    Q2(&pNome[2]);
    printf("Questao 02: %s\n", pNome);

    int matricula[] = {2, 2, 2, 0, 2, 5, 3, 2, 4};
    char NC[] = "joao lucas araujo siqueira";
    printf("Questao 03: %s\n", Q3(matricula, NC));

    char nomeC[] = "william bernardo da silva";
    printf("Questao 04: %d\n", Q4(&nomeC[0], 'a', 0));

    char nomeComp[] = "rafael gomes pereira";
    printf("Questao 05: %d\n", Q5(&nomeComp[5], 10));

    Q6(NC, NC[5], 0);
    printf("Questao 06: %s\n", NC);
}