// Menor e Posição
// Faça um programa que leia um valor N. Este N será o tamanho de um vetor X[N]. A seguir, leia cada um dos valores de X, encontre o menor elemento deste vetor e a sua posição dentro do vetor, mostrando esta informação.

#include <stdio.h>

int main()
{

  int tamanho;
  scanf("%d", &tamanho);

  if (tamanho <= 0 || tamanho > 1000)
  {
    return 0;
  };

  int vetor[tamanho];
  int i;

  for (i = 0; i < tamanho; i++)
  {
    scanf("%d", &vetor[i]);
  }

  int menorValor = vetor[0];
  int menorValorPosicao = 0;

  for (i = 1; i < tamanho; i++)
  {

    if (vetor[i] < menorValor)
    {
      menorValor = vetor[i];
      menorValorPosicao = i;
    }
  }

  printf("Menor valor: %d\n", menorValor);
  printf("Posicao: %d\n", menorValorPosicao);

  return 0;
}
