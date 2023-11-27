#include "Header.h"

void atualziarProd(Item tabela[])
{
  int codigo_editar;
  int verification;
  int opcao, confirm;
  Item tempItem;
  system("cls");
  visualizarEstoque(tabela);

  printf("Digite o codigo do produto a ser editado: ");
  inputNum(&codigo_editar);
  if (validador(codigo_editar, tabela) == 0)
  {
    system("cls");
    printf("\nProduto não encontrado \n");
    return;
  }

  for (int i = 0; i < contador; i++)
  {
    if (tabela[i].codigo == codigo_editar)
    {
      system("cls");
      printf("\nProduto encontrado!");
      printf("\nCodigo Produto: %d", tabela[i].codigo);
      printf("\nNome: %s", tabela[i].nome);
      printf("\nValor Unitario: %.2f", tabela[i].valor);
      printf("\nQuantidade: %d\n", tabela[i].quantidade);

      printf("\nO que você deseja editar \n1- Valor unitario\n2- Quantidade em estoque\n3- Valor unitario e estoque: \n");
      inputNumRange(&opcao, 1, 3);
      switch (opcao)
      {
      case 1:
        printf("\nValor atual: %.2f\n", tabela[i].valor);
        printf("\nDigite o novo valor unitário: ");
        inputFloat(&tempItem.valor);
        printf("\nConfirmação: Valor alterado de %.2f para %.2f\n", tabela[i].valor, tempItem.valor);
        printf("\n1- Confirmar\n2- Cancelar\n");
        inputNumRange(&confirm, 1, 2);
        if (confirm == 1)
        {
          tabela[i].valor = tempItem.valor;
        }
        else
        {
          return;
        }
        break;
      case 2:
        printf("\nQuantidade atual: %d\n", tabela[i].quantidade);
        printf("\nDigite a nova quantidade: ");
        inputNum(&tempItem.quantidade);
        printf("\nConfirmação: Quantidade alterada de %d para %d\n", tabela[i].quantidade, tempItem.quantidade);
        printf("\n1- Confirmar\n2- Cancelar\n");
        inputNumRange(&confirm, 1, 2);
        if (confirm == 1)
        {
          tabela[i].valor = tempItem.quantidade;
        }
        else
        {
          return;
        }
        break;
      case 3:
        printf("\nValor atual: %.2f\n", tabela[i].valor);
        printf("\nDigite o novo valor unitário: ");
        inputFloat(&tempItem.valor);
        printf("\nQuantidade atual: %d\n", tabela[i].quantidade);
        printf("\nDigite a nova quantidade: ");
        inputNum(&tempItem.quantidade);
        printf("\nConfirme a alteração: \nValor alterado de %.2f para %.2f \nQuantidade alterada de %d para %d", tabela[i].valor, tempItem.valor, tabela[i].quantidade, tempItem.quantidade);
        printf("\n1- Confirmar\n2- Cancelar\n");
        inputNumRange(&confirm, 1, 2);
        if (confirm == 1)
        {
          tabela[i].valor = tempItem.valor;
          tabela[i].quantidade = tempItem.quantidade;
        }
        else
        {
          return;
        }

        break;
      default:
        printf("\nOpção inválida. Como?");
        break;
      }
    }
  }
}

void excluirproduto(Item tabela[])
{
  int codigo_editar;
  int confirm;
  int verification;
  system("cls");
  visualizarEstoque(tabela);

  printf("Digite o codigo do produto deseja excluir : ");
  inputNum(&codigo_editar);
  if (validador(codigo_editar, tabela) == 0)
  {
    system("cls");
    printf("\nProduto não encontrado \n");
    return;
  }

  for (int i = 0; i < contador; i++)
  {
    if (tabela[i].codigo == codigo_editar)
    {
      system("cls");

      // Mostra somente o item que sera excluido
      printf("Código\t| %-20s\t| Valor\t\t| Quantidade\t| Produtos Vendidos\n", "Nome");
      printf("%d\t| %-20s\t| R$ %.2f\t| %d\t\t| %d\n", tabela[i].codigo, tabela[i].nome, tabela[i].valor, tabela[i].quantidade, tabela[i].quant_vend);
      printf("\nDeseja realmente excluir este item ");
      printf("\n1- Confirmar\n2- Cancelar\n");
      inputNumRange(&confirm, 1, 2);

      if (confirm == 1)
      {
        for (int i = 0; i < contador; i++)
        {
          if (codigo_editar == tabela[i].codigo)
          {
            // recebe a posição do item dentro do array
            codigo_editar = i;
          }
        }
        // Substitui/sob-escreve o item com o codigo digitado pelo usuario pelo ultimo item da struct
        tabela[codigo_editar].codigo = tabela[contador - 1].codigo;
        strcpy(tabela[codigo_editar].nome, tabela[contador - 1].nome);
        tabela[codigo_editar].quant_vend = tabela[contador - 1].quant_vend;
        tabela[codigo_editar].quantidade = tabela[contador - 1].quantidade;
        tabela[codigo_editar].valor = tabela[contador - 1].valor;

        // Diminui o contador
        contador--;
        // Realoca o espaço da struct com uma posição a menos excluindo o ultimo item
        tabela = (Item *)realloc(tabela, (contador) * sizeof(Item));

        printf("\nProduto excluído!\n");
        return;
      }
      if (confirm == 2)
      {
        printf("\nAção cancelada.\n");
        return;
      }
    }
  }
}
