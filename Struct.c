#include <stdio.h>
#include <string.h>

struct Pessoa {
  char nome[50];
  int idade;
  char telefone[15];
};

int main()
{
  struct Pessoa lista[3];
  int i;

  strcpy(lista[0].nome, "João");
  lista[0].idade = 30;
  strcpy(lista[0].telefone, "123456789");

  strcpy(lista[1].nome, "Maria");
  lista[1].idade = 25;
  strcpy(lista[1].telefone, "987654321");

  strcpy(lista[2].nome, "Pedro");
  lista[2].idade = 40;
  strcpy(lista[2].telefone, "555555555");

  for(i = 0; i < 3; i++) {
    printf("Pessoa %d:\n", i + 1);
    printf("Nome: %s\n", lista[i].nome);
    printf("Idade: %d\n", lista[i].idade);
    printf("Telefone: %s\n\n", lista[i].telefone);
  }

  return 0;
}
