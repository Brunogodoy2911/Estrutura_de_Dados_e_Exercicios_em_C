#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct Product
{
  int id;
  char name[50];
  int quantity;
  float price;
};

struct Stock
{
  struct Product product[MAX_PRODUCTS];
  int count;
};

void create(struct Stock *stock, const char *name, int quantity, float price)
{
  if (stock == NULL || stock->count >= MAX_PRODUCTS)
  {
    printf("Erro: Nao foi possivel cadastrar o produto. Estoque cheio ou invalido.\n");
    return;
  }

  int new_index = stock->count;
  stock->product[new_index].id = new_index + 1;
  strcpy(stock->product[new_index].name, name);
  stock->product[new_index].quantity = quantity;
  stock->product[new_index].price = price;

  stock->count++;

  printf("Produto '%s' cadastrado com sucesso com o ID %d.\n", name, stock->product[new_index].id);
}

void list(struct Stock *stock)
{
  int i;

  printf("\n=== Estoque de Produtos ===\n");

  if (stock->count == 0)
  {
    printf("Estoque vazio.\n");
    return;
  }
  for (i = 0; i < stock->count; i++)
  {
    printf("  ID: %d\n", stock->product[i].id);
    printf("  Nome: %s\n", stock->product[i].name);
    printf("  Quantidade: %d\n", stock->product[i].quantity);
    printf("  Preco: R$ %.2f\n\n", stock->product[i].price);
  }
}

void update(struct Stock *stock, int id, const char *new_name, int new_quantity, float new_price)
{
  int i;
  int found = 0;

  for (i = 0; i < stock->count; i++)
  {
    if (stock->product[i].id == id)
    {
      strcpy(stock->product[i].name, new_name);
      stock->product[i].quantity = new_quantity;
      stock->product[i].price = new_price;

      printf("Produto com ID %d atualizado com sucesso!\n", id);
      found = 1;
      break;
    }
  }

  if (!found)
  {
    printf("Erro: Produto com ID %d nao encontrado para atualizacao.\n", id);
  }
}

void delete(struct Stock *stock, int id)
{
  int i;
  int found_index = -1;

  for (i = 0; i < stock->count; i++)
  {
    if (stock->product[i].id == id)
    {
      found_index = i;
      break;
    }
  }

  if (found_index != -1)
  {
    for (i = found_index; i < stock->count - 1; i++)
    {
      stock->product[i] = stock->product[i + 1];
    }
    stock->count--;
    printf("Produto com ID %d excluido com sucesso.\n", id);
  }
  else
  {
    printf("Erro: Produto com ID %d nao encontrado para exclusao.\n", id);
  }
}

void clear_input_buffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

int main()
{
  struct Stock my_stock;
  my_stock.count = 0;
  int option;

  while (1)
  {
    printf("\n--- MENU DE ESTOQUE ---\n");
    printf("1. Adicionar Produto\n");
    printf("2. Listar Produtos\n");
    printf("3. Atualizar Produto\n");
    printf("4. Excluir Produto\n");
    printf("5. Sair\n");
    printf("Escolha uma opcao: ");

    if (scanf("%d", &option) != 1)
    {
      printf("Entrada invalida. Por favor, insira um numero.\n");
      clear_input_buffer();
      continue;
    }
    clear_input_buffer();

    switch (option)
    {
    case 1:
    {
      char name[50];
      int quantity;
      float price;

      printf("Digite o nome do produto: ");
      fgets(name, 50, stdin);
      name[strcspn(name, "\n")] = 0;

      printf("Digite a quantidade: ");
      scanf("%d", &quantity);

      printf("Digite o preco: ");
      scanf("%f", &price);

      create(&my_stock, name, quantity, price);
      break;
    }
    case 2:
      list(&my_stock);
      break;
    case 3:
    {
      int id;
      char name[50];
      int quantity;
      float price;

      printf("Digite o ID do produto a ser atualizado: ");
      scanf("%d", &id);
      clear_input_buffer();

      printf("Digite o novo nome do produto: ");
      fgets(name, 50, stdin);
      name[strcspn(name, "\n")] = 0;

      printf("Digite a nova quantidade: ");
      scanf("%d", &quantity);

      printf("Digite o novo preco: ");
      scanf("%f", &price);

      update(&my_stock, id, name, quantity, price);
      break;
    }
    case 4:
    {
      int id;
      printf("Digite o ID do produto a ser excluido: ");
      scanf("%d", &id);
      delete(&my_stock, id);
      break;
    }
    case 5:
      printf("Saindo do programa.\n");
      return 0;
    default:
      printf("Opcao invalida. Tente novamente.\n");
    }
  }
  return 0;
}
