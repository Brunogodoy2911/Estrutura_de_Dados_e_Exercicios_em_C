// Considere, por exemplo, a seguinte lista: [1, 3, 6, 7, 9, 12, 15, 22, 90]. Suponha que você esteja buscando o elemento de valor 5. Pois bem, consultando o elemento central da lista (9), verificamos que ele é maior do que o elemento buscado.

#include <stdio.h>
#include <math.h> // Para a função floor

// A função de busca binária assume que a 'lista' está ordenada.
// Ela retorna o índice do elemento se encontrado, ou -1 caso contrário.
int busca_binaria(int lista[], int elemento, int inicio, int fim)
{
  // Calcula o meio do segmento atual da lista.
  int meio = floor((fim + inicio) / 2);

  // Condição de parada: Se o segmento de busca se reduziu a um único elemento
  // e esse elemento não é o que estamos buscando.
  if ((inicio == fim) && (lista[meio] != elemento))
    return -1; // Elemento não encontrado
  // Se o elemento no meio é o que estamos buscando.
  else if (lista[meio] == elemento)
    return meio; // Elemento encontrado, retorna seu índice.
  // Se o elemento buscado é menor que o elemento no meio, busca na metade esquerda.
  else if (elemento < lista[meio])
    return busca_binaria(lista, elemento, inicio, meio);
  // Se o elemento buscado é maior que o elemento no meio, busca na metade direita.
  else
    return busca_binaria(lista, elemento, meio + 1, fim);
}

int main()
{
  // Exemplo de uma lista linear ordenada (implementada como um array de inteiros)
  // Os elementos estão em ordem crescente.
  int minha_lista[] = {1, 3, 6, 7, 9, 12, 15, 22, 90};
  int tamanho = sizeof(minha_lista) / sizeof(minha_lista);

  int elemento_buscado_1 = 7;
  int elemento_buscado_2 = 5;

  printf("Lista ordenada: [2, 21-28]\n");

  // Teste 1: Buscar um elemento que existe
  int indice_1 = busca_binaria(minha_lista, elemento_buscado_1, 0, tamanho - 1);
  if (indice_1 != -1)
  {
    printf("Elemento %d encontrado no índice: %d\n", elemento_buscado_1, indice_1);
  }
  else
  {
    printf("Elemento %d não encontrado na lista.\n", elemento_buscado_1);
  }

  // Teste 2: Buscar um elemento que não existe
  int indice_2 = busca_binaria(minha_lista, elemento_buscado_2, 0, tamanho - 1);
  if (indice_2 != -1)
  {
    printf("Elemento %d encontrado no índice: %d\n", elemento_buscado_2, indice_2);
  }
  else
  {
    printf("Elemento %d não encontrado na lista.\n", elemento_buscado_2);
  }

  return 0;
}

// int main()
// {

//   int i;
//   int array[] = {1, 3, 6, 7, 9, 12, 15, 22, 90};
//   int number_searched = 5;
//   int sizeArray = sizeof(array);
//   int isFound = 0;

//   for (i = 0; i < sizeArray; i++)
//   {
//     if (array[i] == number_searched)
//     {
//       printf("O número %d foi encontrado no indice: %d\n", number_searched, i);
//       isFound = 1;
//       break;
//     }
//   }

//   if (!isFound)
//   {
//     printf("O número %d não foi encontrado na lista.\n", number_searched);
//   }

//   return 0;
// }
