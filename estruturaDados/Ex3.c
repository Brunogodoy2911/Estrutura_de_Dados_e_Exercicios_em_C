// Exercício 3: Procedimentos (void) e Passagem por Valor
// • Objetivo: Entender o conceito de procedimento (void function) e a passagem de parâmetros por valor.
// • Descrição: Em C, procedimentos são funções do tipo void que executam um conjunto de comandos sem retornar valor. Crie um procedimento void chamado alterarValor que receba um parâmetro inteiro numero_original (passagem por valor). Dentro desse procedimento, tente modificar o valor de numero_original (ex: numero_original = 100;). No main:
//     1. Declare uma variável inteira meu_numero e inicialize-a com 50.
//     2. Imprima o valor de meu_numero antes da chamada.
//     3. Chame alterarValor(meu_numero).
//     4. Após a chamada, imprima novamente o valor de meu_numero.
// • Requisito: Com base na saída do programa, explique em um comentário por que a modificação de numero_original dentro do procedimento alterarValor não afeta a variável meu_numero no main, relacionando com o conceito de passagem por valor ("xerox" das informações).

#include <stdio.h>

void alterValue(int *origin_number);

int main()
{

  int my_number = 50;

  printf("My Number: %d", my_number);

  alterValue(&my_number);

  printf("My umber: %d", my_number);

  return 0;
}

void alterValue(int *origin_number)
{
  *origin_number = 100;
}

// My_Number não é afetada pois é criado uma cópia do valor do próprio em origin_number. Para que o valor de my_number seja modificado, é necessario passar o endereço de memória para a modificação do valor.s
