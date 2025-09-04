// Balanço de Parênteses I
// Dada uma expressão qualquer com parênteses, indique se a quantidade de parênteses está correta ou não, sem levar em conta o restante da expressão. Por exemplo:

// a+(b*c)-2-a        está correto
// (a+b*(2-c)-2+a)*2  está correto

// enquanto

// (a*b-(2+c)         está incorreto
// 2*(3-a))           está incorreto
// )3+b*(2-c)(        está incorreto

// Ou seja, todo parênteses que fecha deve ter um outro parênteses que abre correspondente e não pode haver parênteses que fecha sem um previo parenteses que abre e a quantidade total de parenteses que abre e fecha deve ser igual.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Pilha
{
  int topo;
  int capa;
  char *pElem;
};

void criarPilha(struct Pilha *p, int c);
void empilhar(struct Pilha *p, char v);
char desempilhar(struct Pilha *p);
int pilhaVazia(struct Pilha *p);
int pilhaCheia(struct Pilha *p);
void liberarPilha(struct Pilha *p);

int main()
{

  char expression[1001];

  struct Pilha pilha;

  while (fgets(expression, 1000, stdin) != NULL)
  {
    int len = strlen(expression);
    criarPilha(&pilha, len);

    int i;
    int correct = 1;

    for (i = 0; i < len; i++)
    {

      if (expression[i] == '(')
        empilhar(&pilha, '(');
      else if (expression[i] == ')')
        if (pilhaVazia(&pilha))
        {
          correct = 0;
          break;
        }
        else
          desempilhar(&pilha);
    }

    if (correct && pilhaVazia(&pilha))
      printf("correct\n");
    else
      printf("incorrect\n");

    liberarPilha(&pilha);
  }

  return 0;
}

void criarPilha(struct Pilha *p, int c)
{
  p->topo = -1;
  p->capa = c;
  p->pElem = (char *)malloc(c * sizeof(char));
}

int pilhaVazia(struct Pilha *p)
{
  return p->topo == -1;
}

int pilhaCheia(struct Pilha *p)
{
  return p->topo == p->capa - 1;
}

void empilhar(struct Pilha *p, char v)
{
  if (!pilhaCheia(p))
  {
    p->topo++;
    p->pElem[p->topo] = v;
  }
}

char desempilhar(struct Pilha *p)
{
  char aux = '\0';
  if (!pilhaVazia(p))
  {
    aux = p->pElem[p->topo];
    p->topo--;
  }
  return aux;
}

void liberarPilha(struct Pilha *p)
{
  free(p->pElem);
}