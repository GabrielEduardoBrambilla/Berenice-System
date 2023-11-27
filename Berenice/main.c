
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>


int contador;


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



// Lógica do programa
void produtos(Item tabela[])
{
  int opcao;
  do
  {
    printf("1 - Exibir\n");
    printf("2 - Cadastrar\n");
    printf("3 - Atualizar\n");
    printf("4 - Excluir\n");
    printf("5 - Salvar Binario\n");
    printf("6 - Ler Binario\n");
    printf("7 - Salvar CSV\n");
    printf("8 - Ler CSV\n");
    printf("9 - Salvar HTML\n");
    printf("10 - Voltar\n");
    inputNumRange(&opcao, 1, 10);

    switch (opcao)
    {
    case 1:
      system("cls");
      visualizarEstoque(tabela);
      break;
    case 2:
      system("cls");
      cadastroitem(tabela);
      break;
    case 3:
      system("cls");
      atualziarProd(tabela);
      break;
    case 4:
      system("cls");
      excluirproduto(tabela);
      break;
    case 5:
      salvarArquivoBN(tabela);
      break;
    case 6:
      system("cls");
      lerprodutos(tabela);
      break;
    case 7:
      system("cls");
      salvarArquivoCSV(tabela, contador);
      break;
    case 8:
      system("cls");
      lerArquivoCSV(&tabela, contador);
      break;
    case 9:
      system("cls");
      salvarArquivoHTML(tabela);
      break;
    case 10:
      system("cls");
      break;
    default:
      system("cls");
      printf("Opção inválida!!\n");
      break;
    }
  } while (opcao != 10);
}


int validador(int cod, Item tabela[])
{
  for (int i = 0; i < contador; i++)
  {
    if (cod == tabela[i].codigo)
    {
      // printf("\n Codigo passado %d, index do codigo %d", cod, i);

      // codigo invalido já existe na tabela
      return 1;
    }
  }
  // Não existe na tabela
  // Novo código válido
  return 0;
}


