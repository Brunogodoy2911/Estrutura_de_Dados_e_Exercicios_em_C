// 6. Pilha com Alocação Sequencial (Array)
// • Objetivo: Implementar uma estrutura de dados do tipo Pilha (Stack) utilizando um array, controlando as condições de overflow (pilha cheia) e underflow (pilha vazia) [Listas, pilhas e filas.pdf, 222-230].
// • Tarefa: Crie um programa em C que simule uma pilha de inteiros com capacidade máxima de 5 elementos.
//     1. Declare um vetor global de inteiros (ex: int pilha;) e uma variável global int topo = -1; para gerenciar o topo da pilha [Listas, pilhas e filas.pdf, 224-225].
//     2. Implemente a função int push(int elemento):
//         ▪ Adiciona um elemento ao topo da pilha.
//         ▪ Retorna 1 em caso de sucesso e 0 se a pilha estiver cheia (overflow), sem adicionar o elemento [Listas, pilhas e filas.pdf, 225-226].
//     3. Implemente a função int pop():
//         ▪ Remove e retorna o elemento do topo da pilha.
//         ▪ Retorna um valor especial (ex: -9999 ou um valor que não seja um elemento válido da pilha) se a pilha estiver vazia (underflow), sem remover nada [Listas, pilhas e filas.pdf, 226-228].
//     4. Na função main, realize uma sequência de operações push e pop para testar o funcionamento, incluindo tentativas de push em pilha cheia e pop em pilha vazia.

#include <stdio.h>

#define TAMANHO_PILHA 5

int pilha[TAMANHO_PILHA];

int topo = -1;

int push(int elemento);

int pop();

void listarPilha();

int main()
{

  push(5);
  push(4);
  push(3);
  push(2);

  listarPilha();

  printf("-------- Pop --------- \n");
  pop();
  pop();

  listarPilha();

  return 0;
}

int push(int elemento)
{
  if (topo < (TAMANHO_PILHA - 1))
  {
    topo++;
    pilha[topo] = elemento;
    return 1;
  }
  else
    return 0;
}

int pop()
{
  int valor_recuperado;
  if (topo >= 0)
  {
    valor_recuperado = pilha[topo];
    topo--;
    return valor_recuperado;
  }
  else
  {
    printf("Underflow");
    return -9999;
  }
}

void listarPilha()
{
  int i;

  if (topo == -1)
  {
    printf("Pilha está vazia!");
    return;
  }

  for (i = 0; i <= topo; i++)
  {
    printf("Pilha[%d] = %d \n", i, pilha[i]);
  }
}
