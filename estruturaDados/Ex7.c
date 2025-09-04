// 7. Structs Aninhadas e Array de Structs
// • Objetivo: Combinar o uso de structs aninhadas com arrays de structs para modelar e manipular dados complexos e hierárquicos [EstruturadeDados-02.pdf, 101-120, 122-134].
// • Tarefa: Crie um programa em C que gerencie dados de 3 alunos, incluindo suas datas de nascimento.
//     1. Defina uma struct separada chamada Data com os campos dia (int), mes (int) e ano (int) [EstruturadeDados-02.pdf, 120-122].
//     2. Defina uma struct chamada Aluno com os campos nome (string, ex: char nome), matricula (int), e um campo do tipo Data chamado data_nascimento (ou outro nome, ex: datNasc) [EstruturadeDados-02.pdf, 105, 120-122].
//     3. Na função main, declare um array de 3 structs Aluno (ex: struct Aluno turma;).
//     4. Use um laço de repetição para solicitar e preencher os dados de cada um dos 3 alunos (nome, matrícula, dia, mês e ano de nascimento).
//     5. Após o cadastro, imprima os dados de todos os alunos de forma organizada, acessando os campos da Data aninhada [EstruturadeDados-02.pdf, 112-113].

#include <stdio.h>

#define MAX_ALUNOS 3

typedef struct
{
  int dia;
  int mes;
  int ano;
} Data;

typedef struct
{
  char nome[50];
  int matricula;
  Data data_nascimento;
} Aluno;

void listarAlunos(Aluno turma[], int n_alunos);

int main()
{

  Aluno turma[MAX_ALUNOS];
  int i;

  for (i = 0; i < MAX_ALUNOS; i++)
  {

    printf("\n------- CADASTRO DE ALUNO ---------- \n");
    printf("Nome: ");
    scanf("%s", &turma[i].nome);
    printf("Matricula: ");
    scanf("%d", &turma[i].matricula);

    printf("Data de Nascimento\n");
    printf("Dia: ");
    scanf("%d", &turma[i].data_nascimento.dia);
    printf("Mês: ");
    scanf("%d", &turma[i].data_nascimento.mes);
    printf("Ano: ");
    scanf("%d", &turma[i].data_nascimento.ano);
  }

  listarAlunos(turma, MAX_ALUNOS);

  return 0;
}

void listarAlunos(Aluno turma[], int n_alunos)
{
  int i, j;
  Aluno aux;

  for (j = 0; j < n_alunos - 1; j++)
  {
    for (i = 0; i < n_alunos - 1; i++)
    {

      if (turma[i].data_nascimento.ano < turma[i + 1].data_nascimento.ano)
      {
        aux = turma[i];
        turma[i] = turma[i + 1];
        turma[i + 1] = aux;
      }

      else if (turma[i].data_nascimento.ano == turma[i + 1].data_nascimento.ano && turma[i].data_nascimento.mes < turma[i + 1].data_nascimento.mes)
      {
        aux = turma[i];
        turma[i] = turma[i + 1];
        turma[i + 1] = aux;
      }
      else if (turma[i].data_nascimento.ano == turma[i + 1].data_nascimento.ano && turma[i].data_nascimento.mes == turma[i + 1].data_nascimento.mes && turma[i].data_nascimento.dia < turma[i + 1].data_nascimento.dia)
      {
        aux = turma[i];
        turma[i] = turma[i + 1];
        turma[i + 1] = aux;
      }
    }
  }

  printf("\n--- LISTA DE ALUNOS (DO MAIS NOVO AO MAIS VELHO) ---\n");
  for (i = 0; i < n_alunos; i++)
  {
    printf("\nAluno %d:", i + 1);
    printf("\n  Nome: %s", turma[i].nome);
    printf("\n  Matricula: %d", turma[i].matricula);
    printf("\n  Data de Nascimento: %02d/%02d/%d\n",
           turma[i].data_nascimento.dia,
           turma[i].data_nascimento.mes,
           turma[i].data_nascimento.ano);
  }
}
