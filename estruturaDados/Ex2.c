// Exercício 2: Definição e Manipulação de Structs
// • Objetivo: Definir e manipular uma estrutura de dados heterogênea simples (struct).
// • Descrição: As structs em C são usadas para definir estruturas de dados heterogêneas, permitindo combinar variáveis de diferentes tipos sob um único nome. Defina uma struct chamada Produto que contenha os campos char nome, int codigo e float preco. No programa principal (main):
//     1. Declare uma variável do tipo struct Produto chamada monitor.
//     2. Inicialize os campos de monitor com dados de exemplo (ex: nome = "Monitor LED", codigo = 101, preco = 799.99). Lembre-se de usar strcpy() para strings.
//     3. Imprima os valores de cada campo de monitor na tela.
// • Requisito: Indique qual operador (. ou ->) é utilizado para acessar os membros de uma struct quando se trabalha diretamente com a variável da struct.

#include <string.h>

int main()
{

  typedef struct
  {
    char name[50];
    int code;
    float price;
  } Product;

  Product monitor;
  int i;

  strcpy(monitor.name, "Monitor LED");
  monitor.code = 101;
  monitor.price = 799.99;

  printf("Nome do Produto: %s\n", monitor.name);
  printf("Código: %d\n", monitor.code);
  printf("Preço: R$ %.2f\n", monitor.price);

  return 0;
}
