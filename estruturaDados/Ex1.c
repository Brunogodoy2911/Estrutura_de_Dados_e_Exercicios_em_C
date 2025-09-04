// Exercício 1: Ponteiros e Acesso Indireto
// • Objetivo: Compreender a declaração de ponteiros e o acesso indireto a valores.
// • Descrição: Na Linguagem C, um ponteiro é uma variável especial que armazena um endereço de memória. Crie um programa em C que:
//     1. Declare uma variável inteira idade e a inicialize com o valor 25.
//     2. Declare um ponteiro para inteiro ptr_idade.
//     3. Faça com que ptr_idade armazene o endereço da variável idade utilizando o operador &.
//     4. Imprima o valor de idade utilizando o ponteiro (*ptr_idade).
// • Requisito: Explique em um comentário no código o que o operador & faz (obter o endereço de memória) e o que o operador * de indireção faz (acessar o conteúdo do endereço apontado).

#include <stdio.h>

int main()
{

  int age = 25;
  int *ptr_age;

  ptr_age = &age;

  printf("Valor by pointer: %d", *ptr_age);

  return 0;
}
