
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include "Funcoes.h"

int main()
{
  Item *tabela;
  contador = 5;

  int opcao;

  tabela = (Item *)malloc(contador * sizeof(Item));
  initializeDefaultItems(tabela);
  do
  {
    printf("Menu:\n");
    printf("1 - Produtos\n");
    printf("2 - Vendas\n");
    printf("3 - Sair\n");
    printf("Escolha uma opção: ");
    inputNumRange(&opcao, 1, 3);

    switch (opcao)
    {
    case 1:
      system("cls");
      produtos(tabela);
      break;

    case 2:
      system("cls");
      menuVendas(tabela);
      break;

    case 3:
      system("cls");
      printf("Fechando o programa!\n");

      break;

    default:
      system("cls");
      printf("Opção inválida. Tente novamente.\n");
      break;
    }
  } while (opcao != 3);
  free(tabela);
  return 0;
}
