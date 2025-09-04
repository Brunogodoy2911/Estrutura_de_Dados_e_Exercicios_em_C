// Preenchimento de Vetor II
// Faça um programa que leia um valor T e preencha um vetor N[1000] com a sequência de valores de 0 até T-1 repetidas vezes, conforme exemplo abaixo. Imprima o vetor N.

#include <stdio.h>
#define MAX_VETOR 1000

int main()
{

  int vetor[MAX_VETOR];
  int T;
  int i;

  scanf("%d", &T);

  for (i = 0; i < MAX_VETOR; i++)
  {
    vetor[i] = i % T;
  }

  for (i = 0; i < MAX_VETOR; i++)
  {
    printf("N[%d] = %d\n", i, vetor[i]);
  }

  return 0;
}
