#include "Header.h"

void cadastroitem(Item tabela[])
{
  int quant_item = 0;
  int validar, quant, cod, new_items;
  int opcao, i = 0;
  float valor;
  do
  {
    printf("\n1 - Cadastrar Novo item");
    printf("\n2 - Adicionar estoque aos itens");
    printf("\n3 - Voltar");
    printf("\nSelecione: ");
    inputNumRange(&opcao, 1, 3);
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
          system("cls");
        }

        printf("\nProduto %d de %d novos produtos", i, new_items);

        // Cod item
        do
        {
          printf("\nCódigo do produto novo: ");
          inputNum(&tabela[contador].codigo);

          if (validador(tabela[contador].codigo, tabela) == 1)
          {
            system("cls");
            printf("\nCódigo invalido ou em uso, tente novamente ");
          }
        } while (validador(tabela[contador].codigo, tabela) == 1);

        //  Nome Item
        printf("\nNome do produto: ");
        inputString(&tabela[contador].nome);

        //  Preco unidade
        printf("\nPreço unitario: ");
        inputFloat(&tabela[contador].valor);

        //  Quant item
        printf("\nQuantidade em estoque: ");
        inputNum(&tabela[contador].quantidade);
        tabela[contador].quant_vend = 0;
        contador += i;
      }
    }
    else if (opcao == 2)
    {
      system("cls");
      visualizarEstoque(tabela);
      do
      {
        printf("\nQual produto deseja ADICIONAR estoque (codigo do produto): ");
        inputNum(&cod);
        if (validador(cod, tabela) != 1)
        {
          // Limpar o buffer de input
          printf("\nCódigo invalido, digite outro: ");
        }
      } while (validador(cod, tabela) != 1);

      for (int i = 0; i < contador; i++)
      {
        if (cod == tabela[i].codigo)
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
      printf("\nVoltando ao menu...\n");
    }
    else if (opcao != 3)
    {
      printf("\n Codigo inexistente!!");
    }
  } while (opcao != 3);
}
