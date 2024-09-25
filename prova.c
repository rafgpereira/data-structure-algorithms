#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
PONTEIROS:

- Com asterisco: *pointer - acessamos o valor de onde ele aponta
- Sem asterisco: pointer - acessamos o endereço para onde ele aponta


- Podemos passar endereços como argumentos para uma função, e receber os valores nesses endereços através de ponteiros nos parâmetros
*/
int Q1(int valor){
    int *ptr, *pnumeros, pn = valor % 10, pp, psoma = 0;

    if(pn < 2) pn = 5 - pn;

    pnumeros = (int *)malloc(pn*sizeof(int));
    ptr = pnumeros;

    printf("\nPtr: %p\n", ptr);
    for(pp = 0; pp < pn; pp++){
        ptr[pp] = valor % 10;
        valor = valor / 10;
    }
    printf("\nPtr: %p\n", ptr);

    for(pp = 0; pp < pn; pp++){
        if((*ptr%2) == 1){
            psoma = psoma + *ptr;
        }
        ptr++;
    }
    printf("\nPtr: %p\n", ptr);
    return (psoma);
}

void Q2(char *str) {
    int n = strlen(str);

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(str[i] > str[j]){
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

char *Q3(int *M, char *NC){
    int n;
    char *code = (char*)malloc(9*sizeof(char));

    for(int i = 0; i < 9; i++){
        code[i] = NC[M[i]];
        if(code[i] == ' ') code[i] = '-';
    }

    return code;
}

int Verifica(char c){
    return (c >= 'a' && c <= 'z' && c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u');
}

int Q4(char *NC, char L, int pos) {

  if (NC[0] == '\0' || pos < 0 || pos >= strlen(NC) - 1) {
    return -1;
  }

  if (NC[pos] == L && Verifica(NC[pos + 1])) {
    return pos;
  }

  return Q4(NC, L, pos + 1);
}


int Q5(char *NC, int R) {
    int r;
    FILE *A = fopen("Saida.txt", "w");
    for(int i = 0; i < R; i++){
        fprintf(A, "%s", NC);
    }
    fclose(A);
    A = fopen("Saida.txt", "r+");
    fseek(A, -20, SEEK_END);
    r = ftell(A);
    fclose(A);
    return r;
}


int main()
{
    int psoma = Q1(222015248);
    printf("Questao 1: %d\n", psoma);

    char nome[] = "rafael";
    Q2(nome);
    printf("Questao 2: %s\n", nome);

    int matricula[] = {2, 2, 2, 0, 1, 5, 2, 4, 8};
    char *resp = Q3(matricula, "rafael gomes pereira");
    printf("Questao 3: %s\n", resp);

    int pos = Q4("rafael gomes pereira", 'a', 0);
    printf("Questao 4: %d\n", pos);

    int r = Q5("rafael gomes pereira", 11);
    printf("Questao 5: %d\n", r);


    return 0;
}