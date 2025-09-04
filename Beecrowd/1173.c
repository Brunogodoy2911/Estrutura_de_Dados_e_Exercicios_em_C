// Preenchimento de Vetor I
// Leia um valor e faça um programa que coloque o valor lido na primeira posição de um vetor N[10]. Em cada posição subsequente, coloque o dobro do valor da posição anterior. Por exemplo, se o valor lido for 1, os valores do vetor devem ser 1,2,4,8 e assim sucessivamente. Mostre o vetor em seguida.

#include <stdio.h>
#define MAX_VETOR 10

int main()
{

  int vetor[MAX_VETOR];
  int numero;
  int i;

  scanf("%d", &numero);
  vetor[0] = numero;

  for (i = 1; i < MAX_VETOR; i++)
  {
    vetor[i] = vetor[i - 1] * 2;
  }

  for (i = 0; i < MAX_VETOR; i++)
  {
    printf("N[%d] = %d\n", i, vetor[i]);
  }

  return 0;
}
