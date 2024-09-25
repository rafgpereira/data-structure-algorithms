#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa
{
    char *nome;
    int idade;
};

void mudaNome(char *nome)
{
    *nome = '_';
    *(nome + 2) = '_';
}

void inicializaPessoa(struct Pessoa *p)
{
    //p->nome = (char *)malloc((strlen("Rafinha") + 1) * sizeof(char));

    strcpy(p->nome, "Rafinha");
    p->idade = 22;
}

void imprimePessoa(struct Pessoa *p)
{
    printf("\n\nA pessoa eh: %s, e ela tem %d anos.", p->nome, p->idade);
}

int main()
{
    int n;
    printf("Digite o tamanho do seu nome: ");
    scanf("%d", &n);

    char *nome = (char *)malloc(n * sizeof(char));

    getchar();
    printf("Digite seu nome: ");
    fgets(nome, n + 1, stdin);

    if (nome[strlen(nome) - 1] == '\n')
        nome[strlen(nome) - 1] = '\0';

    printf("\nSeu nome eh: %s", nome);

    mudaNome(&nome[1]);

    printf("\n\nSeu novo nome eh: %s", nome);

    char nome2[] = "thiago";

    char *pt2;
    pt2 = nome2;

    printf("\n\nO nome 2 eh: %s", pt2);

    *pt2 = 'T';
    printf("\n\nO NOVO nome 2 eh: %s", nome2);

    free(nome);

    struct Pessoa p1;
    inicializaPessoa(&p1);
    imprimePessoa(&p1);

    free(p1.nome);
}