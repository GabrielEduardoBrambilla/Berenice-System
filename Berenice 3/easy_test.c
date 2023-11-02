#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define nameLength 50
typedef struct
{
  int codigo;
  char nome[nameLength];
  float valor;
  int quantidade;
  int quant_vend;
} Item;
Item *tabela;
int contador = 5;

int main()
{
  cadastroitem(tabela);
  return 0;
}
void inputNum(int *var)
{
  int validInput = 0;
  do
  {
    if (scanf("%d", var) != 1)
    {
      // Clear input buffer
      int c;
      while ((c = getchar()) != '\n' && c != EOF)
        ;
      printf("\nNumero invalido. Tente novamente: ");
    }
    else
    {
      validInput = 1;
    }
  } while (!validInput);
}
void inputFloat(float *var)
{
  int validInput = 0;
  do
  {
    scanf("%f", var);
    if (*var > 0)
    {
      validInput = 1;
    }
    else
    {
      // Clear input buffer
      int c;
      while ((c = getchar()) != '\n' && c != EOF)
        ;
      printf("\nInput invalido. Tente novamente: ");
    }
  } while (!validInput);
}
void inputNumRange(int *var, int minRange, int maxRange)
{
  while (1)
  {
    scanf("%d", var);
    if (*var >= minRange && *var < maxRange)
    {
      return;
    }
    else
    {

      printf("\nNúmero inválido. Tente novamente.\n");
    }
  }
}
void inputString(char *str)
{
  int scape = 0;

  do
  {

    scanf("%s", str);

    size_t length = strlen(str);
    if (str[length - 1] == '\n')
    {
      str[length - 1] = '\0'; // Remove the newline character
    }

    if (strlen(str) < 1)
    {
      printf("\nString invalid. Please try again.\n");
    }
    else
    {
      scape = 1;
      return;
    }
  } while (scape != 1);
}

int validador(int cod, Item tabela[])
{
  for (int i = 0; i < contador; i++)
  {
    if (cod == tabela[i].codigo)
    {
      // codigo invalido já existe na tabela
      return 1;
    }
  }
  // Não existe nao tabela
  // Novo código válido
  return 0;
}

void cadastroitem(Item tabela[])
{
  int quant_item = 0;
  int validar, quant, cod, new_items;
  int opcao, i = 0;
  int test = contador;
  float valor;
  Item temp;
  do
  {
    printf("\n1 - Cadastrar Novo item");
    printf("\n2 - Adicionar estoque aos itens");
    printf("\n3 - Voltar");
    printf("\nSelecione: ");
    scanf("%d", &opcao);
    getchar();

    if (opcao == 1)
    {
      printf("\nQuantos produtos novos deseja cadastrar?: ");
      inputNum(&new_items);

      tabela = (Item *)realloc(tabela, (contador + new_items) * sizeof(Item));
      printf("\n%d novos items serão adicionados", new_items);

      for (int i = 1; new_items >= i; i++)
      {
        if (i > 1)
        {
          system('cls');
        }
        printf("\nProduto %d de %d novos produtos", i, new_items);

        // Cod item
        do
        {
          printf("\nCódigo do produto novo: ");
          inputNum(&tabela[contador + i].codigo);
          if (validador(tabela[contador + i].codigo, tabela) == 1)
          {
            system('cls');
            printf("\nCódigo invalido ou em uso, tente novamente ");
          }
        } while (validador(tabela[contador + i].codigo, tabela) == 1);

        //  Nome Item
        printf("\nNome do produto: ");
        inputString(&tabela[contador + i].nome);
        printf("\nIn table %s ", tabela[contador + i].nome);

        //  Preco unidade
        printf("\nPreço unitario: ");
        inputFloat(&tabela[contador + i].valor);

        //  Quant item
        printf("\nQuantidade em estoque: ");
        inputNum(&tabela[contador + i].quantidade);
      }
    }
    else if (opcao == 2)
    {

      do
      {
        printf("\nQual produto deseja adicionar estoque (codigo do produto): ");
        inputNum(&cod);
        if (validador(cod, tabela) != 0)
        {
          system('cls');
          while (getchar() != '\n')
            ;
          printf("\nCódigo invalido, digite outro: ");
        }
      } while (validador(cod, tabela) != 0);

      for (int i = 0; i < contador; i++)
      {
        if (cod == tabela[cod].codigo)
        {
          printf("\nDigite a quantidade: ");
          inputNum(&quant);
          tabela[i].quantidade += quant;
        }
      }
    }
    else if (opcao == 3)
    {

      system("cls");
      printf("\nSaindo...\n");
    }
    else if (opcao != 3)
    {
      printf("\n Codigo inexistente!!");
    }
  } while (opcao != 3);
}
