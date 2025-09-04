// Exercício 4: Passagem por Referência para Troca de Valores
// • Objetivo: Aplicar a passagem de parâmetros por referência para modificar variáveis originais.
// • Descrição: Para que uma sub-rotina possa alterar o valor de uma variável original, deve-se usar a passagem por referência, que envolve o uso de ponteiros para o endereço de memória da variável. Crie um procedimento void chamado trocarValores que receba dois ponteiros para inteiros (int *x, int *y) como parâmetros. Implemente a lógica para trocar os valores apontados por x e y. No main:
//     1. Declare duas variáveis inteiras valor1 e valor2 e inicialize-as.
//     2. Imprima seus valores antes da troca.
//     3. Chame trocarValores() passando os endereços dessas variáveis (utilizando &).
//     4. Imprima os valores de valor1 e valor2 novamente para verificar se a troca ocorreu.
// • Requisito: Explique a principal vantagem da passagem por referência em comparação com a passagem por valor para cenários onde a modificação dos dados originais é necessária.

#include <stdio.h>

void trocarValores(int *x, int *y);

int main()
{

  int valor1 = 90, valor2 = 80;

  printf(" Valor 1: %d, \n Valor 2: %d", valor1, valor2);

  trocarValores(&valor1, &valor2);

  printf("\n Depois da troca: \n Valor 1: %d, \n Valor 2: %d \n", valor1, valor2);

  return 0;
}

void trocarValores(int *x, int *y)
{
  *x = 80;
  *y = 90;
}
