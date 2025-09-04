// 8. Fila com Alocação Dinâmica (Lista Encadeada Simples)
// • Objetivo: Implementar uma estrutura de dados do tipo Fila (Queue) utilizando alocação dinâmica (lista simplesmente encadeada), gerenciando os ponteiros de início e fim da fila [Listas, pilhas e filas.pdf, 268-277].
// • Tarefa: Crie um programa em C que simule uma fila de caracteres.
//     1. Defina uma struct No para representar os nós da fila, contendo um campo char dado e um ponteiro struct No *prox [Listas, pilhas e filas.pdf, 273].
//     2. Use dois ponteiros globais: No *inicio = NULL; e No *fim = NULL; para controlar o início e o fim da fila [Listas, pilhas e filas.pdf, 269].
//     3. Implemente a função int enqueue(char caractere):
//         ▪ Aloca um novo nó dinamicamente usando malloc ou calloc.
//         ▪ Adiciona o nó ao final da fila, atualizando os ponteiros fim e inicio (se a fila estiver vazia) [Listas, pilhas e filas.pdf, 274-276].
//         ▪ Retorna 1 em caso de sucesso e 0 se a alocação de memória falhar.
//     4. Implemente a função char dequeue():
//         ▪ Remove o nó do início da fila e retorna o caractere armazenado.
//         ▪ Libera a memória do nó removido usando free [Listas, pilhas e filas.pdf, 276-277].
//         ▪ Retorna um valor especial (ex: \0 para indicar fila vazia ou erro) se a fila estiver vazia.
//     5. Na função main, execute uma sequência de operações enqueue e dequeue para testar o funcionamento da fila.

#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
  char dado;
  struct No *prox;
} No;

No *inicio = NULL;
No *fim = NULL;

int enqueue(char elemento);

char dequeue();

void listarFila();

int main()
{
  printf("Iniciando operacoes na fila...\n");

  printf("\nEnfileirando '5', '6', '7', '8'...\n");
  enqueue('5');
  enqueue('6');
  enqueue('7');
  enqueue('8');

  listarFila();

  printf("\nDesenfileirando dois elementos...\n");

  char valor_removido1 = dequeue();
  char valor_removido2 = dequeue();

  printf("Primeiro valor removido: %c\n", valor_removido1);
  printf("Segundo valor removido: %c\n", valor_removido2);

  listarFila();

  printf("\nEnfileirando 'A'...\n");
  enqueue('A');
  listarFila();

  return 0;
}

int enqueue(char elemento)
{

  No *novo_no = (No *)malloc(sizeof(No));

  if (novo_no == NULL)
  {
    printf("Erro de alocaçao de memória!\n");
    return 0;
  }

  novo_no->dado = elemento;
  novo_no->prox = NULL;

  if (inicio == NULL)
  {
    inicio = novo_no;
    fim = novo_no;
  }
  else
  {
    fim->prox = novo_no;
    fim = novo_no;
  }

  return 1;
}

char dequeue()
{
  if (inicio == NULL)
  {
    return '\0';
  }

  No *no_a_remover = inicio;

  char dado_retornado = no_a_remover->dado;

  inicio = inicio->prox;

  if (inicio == NULL)
    fim = NULL;

  free(no_a_remover);

  return dado_retornado;
}

void listarFila()
{

  No *ponteiro_atual = inicio;

  printf("Inicio -> ");

  while (ponteiro_atual != NULL)
  {
    printf("[%c] -> ", ponteiro_atual->dado);

    ponteiro_atual = ponteiro_atual->prox;
  }

  printf("NULL (Fim)\n");
}
