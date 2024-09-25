#include <stdio.h>
#include <stdlib.h>
void Q1()
{
    int vet[] = {10, 20, 30};

    int *p = vet;
    p++;

    printf("\n%d", *p);
    (*p)++;
    printf(" - %d", *p);
    printf(" - %d", *(p + 1));
}

char *acheSobrenome(char nome[])
{
    char *pnome;
    int i = 0;
    while (nome[i] != ' ')
    {
        i++;
    }
    i++;
    pnome = &nome[i];
    return pnome;
}
float Media(float *pV, int pn)
{
    float pM = 0;
    int pInd;
    for (pInd = 0; pInd < pn; pInd++)
    {
        pM += pV[pInd];
    }
    return (pM / pn);
}

float Media2(float *pV, int pn)
{
    float pM = 0, *pVaux = pV;
    int pInd;
    for (pInd = 0; pInd < pn; pInd++)
    {
        pM += *pVaux;
        pVaux++;
    }
    return (pM / pn);
}

int repete1(int numero, int digito)
{
    int pdig, pdiv, pcont = 0;

    if (numero < 10)
    {
        if (numero == digito)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    pdiv = numero / 10;
    pdig = (numero - pdiv * 10);

    if (pdig == digito)
    {
        pcont = 1;
    }

    return pcont + repete1(pdiv, digito);
}
int main()
{
    printf("REPETE 1: %d", repete1(1234323, 3));

    /*char nomeCompleto [80];
    char *p;
    puts("Entre com o seu nome e um sobrenome:");
    gets(nomeCompleto);
    p = acheSobrenome(nomeCompleto);
    puts(p);*/
}