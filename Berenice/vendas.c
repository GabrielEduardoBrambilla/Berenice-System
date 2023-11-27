#include "Header.h"

void menuVendas(Item tabela[])
{
  int opcao;
  printf("Menu\n");
  printf("1 - Realizar Venda:\n");
  printf("2 - Relatorio de Venda:\n");
  printf("3 - Sair\n");
  printf("Selecione: \n");
  inputNumRange(&opcao, 1, 3);

  switch (opcao)
  {
  case 1:
    system("cls");
    realizarVenda(tabela);
    break;

  case 2:
    system("cls");
    relatorioVendas(tabela);
    break;

  case 3:
    system("cls");
    break;
  }
}

void realizarVenda(Item tabela[])
{
  int has_estoque = 0, quant_upt, qnt_parcela, porcentagem_desc, porcent_juros, opc_pagamento, verification, i, actionCode = 0, estoque_verificacao = 0, venda_quantidade[5] = {0, 0, 0, 0, 0}, qnt_item;
  float venda_total, *vendas_totais, venda_total_juros, pagamento_recebido, valor_parcela, troco, max, subtotal, subtotal_item[5] = {0, 0, 0, 0, 0};

  Item *carrinho;
  int cart_size = 0;
  int item_index = cart_size;
  printf("%d", cart_size);

  // Verificação se algum item tem estoque
  for (int i = 0; i < contador; i++)
  {
    if (tabela[i].quantidade <= 0)
    {
      estoque_verificacao++;

      if (estoque_verificacao == contador)
      {
        printf("Nenhum item possui estoque, cadastre o estoque antes de vender \n");
        return 1;
      }
    }
  }

  // Parte de Seleção de item do carrinho
  // Parte de Seleção de item do carrinho
  // Parte de Seleção de item do carrinho
  do
  {
    // Aloca espaço para um item novo no carrinho
    if (cart_size == 0)
    {
      cart_size++;
      carrinho = (Item *)malloc((cart_size) * sizeof(Item));
    }
    else
    {
      cart_size++;
      carrinho = (Item *)realloc(carrinho, ((cart_size) * sizeof(Item)));
    }

    do
    {
      system("cls");
      visualizarEstoque(tabela);
      printf("\n%d\n", cart_size);

      printf("Para sair digite 9999 qual item deseja vender\n");
      printf("Digite qual item deseja vender\n");
      inputNum(&carrinho[cart_size - 1].codigo);
      if (carrinho[cart_size - 1].codigo == 9999)
      {
        break;
      }

      for (int i = 0; i < contador; i++)
      {
        if (carrinho[cart_size - 1].codigo == tabela[i].codigo)
        {
          item_index = i;
        }
      }
      // Verifica se tem estoque no item selecionado
      if (tabela[item_index].quantidade <= 0)
      {
        has_estoque = 0;
        system("cls");
        printf("Item sem estoque. Selecione outro item\n");
      }
      else
      {
        has_estoque = 1;
      }
    } while (validador(carrinho[cart_size - 1].codigo, tabela) != 1 && has_estoque != 0);
    // Verifica se o codigo digitado é o codigo de escape ou não
    // se for pula para a parte seguinte
    if (carrinho[cart_size - 1].codigo == 9999)
    {
      cart_size--;
      carrinho = (Item *)realloc(carrinho, ((cart_size) * sizeof(Item)));
      break;
    }

    // Seleciona uma quantidade valida
    printf("Quantos unidades deseja comprar\n");

    // Permite ao usuario digitar somente entre o range de 1 ou a quantidade total do item presente na tabela
    inputNumRange(&carrinho[cart_size - 1].quantidade, 1, tabela[item_index].quantidade);

    // Subtrai q quantiade de itens comprados da struct
    tabela[item_index].quantidade -= carrinho[cart_size - 1].quantidade;
    tabela[item_index].quant_vend += carrinho[cart_size - 1].quantidade;

    // Passa as informaçõe do item para o carrinho
    strcpy(carrinho[cart_size - 1].nome, tabela[item_index].nome);
    carrinho[cart_size - 1].codigo = tabela[item_index].codigo;
    carrinho[cart_size - 1].valor = tabela[item_index].valor;

  } while (carrinho[cart_size].codigo != 9999);

  // // Parte de pagamento
  // // Parte de pagamento
  // // Parte de pagamento
  {
    system("cls");

    // Visualiza os itens presente no carrinho
    visualizarComanda(carrinho, cart_size);

    printf("\nDeseja pagar a vista ou a prazo digite:\n");
    printf("1 - para avista\n");
    printf("2 - para a prazo\n");
    inputNumRange(&opc_pagamento, 1, 2);
    for (int i = 0; i < cart_size; i++)
    {
      venda_total += carrinho[i].valor * carrinho[i].quantidade;
    }
    // Verifica se a opção de pagamento selecionada foi 1 ou seja avista
    if (opc_pagamento == 1)
    {
      printf("\nPagamento avista selecionado\n");
      // Verifica se o total da venda é menor ou igual a 50
      if (venda_total <= 50)
      {
        // Desconto de 5%
        venda_total = venda_total - (venda_total * 0.05);
        porcentagem_desc = 5;
      }
      // Verifica se o total da venda é maior a 50 e ao mesmo tempo menor que 100
      else if (venda_total > 50 && venda_total < 100)
      {
        // Desconto de 10%
        venda_total = venda_total - (venda_total * 0.1);
        porcentagem_desc = 10;
      }
      // Verifica se o total da venda é maior ou igual a 100
      else if (venda_total >= 100)
      {
        // Desconto de 18%
        venda_total = venda_total - (venda_total * 0.18);
        porcentagem_desc = 18;
      }
      do
      {
        printf("Digite o valor recebido para calcular o troco\n");
        printf("Desconto de %d%% aplicado a compra\n", porcentagem_desc);
        printf("Total com desconto: RS %.2f\n", venda_total);
        inputFloat(&pagamento_recebido);
      } while (pagamento_recebido < venda_total);

      // Verifica se o pagamento recebido é menor que o preco da venda a ser cobrada, e ao mesmo tempo se o pagamento é diferente de 0
      // Se a verificação do if de cima for falso executa esse else
      if (pagamento_recebido > venda_total)
      {
        troco = venda_total - pagamento_recebido;
        troco = troco * -1;
        printf("O troco e %.2f\n", troco);
      }
      if (pagamento_recebido == venda_total)
      {
        printf("Compra finalizada \n");
      }
    }
    else
    {
      do
      {
        printf("Digite a quantidade de vezes que deseja parcelar\n");
        inputNum(&qnt_parcela);
        if (qnt_parcela <= 0)
        {
          system("cls");
          printf("Quantidade de parcelas invalida, digite novamente\n");
        }
      } while (qnt_parcela <= 0);
      // Verifica se a quantidade de parcelas é valido sendo maior que 0
      // Verifica se a quantidade de parcelas é está entre 3 e 1. E calcula os valores de acordo
      if (qnt_parcela <= 3 && qnt_parcela >= 1)
      {
        venda_total_juros = venda_total + (venda_total * 0.05);
        porcent_juros = 5;
        valor_parcela = venda_total_juros / qnt_parcela;
      }
      // Verifica se a quantidade de parcelas é maior que 3 e calcula os valores de acordo
      else if (qnt_parcela > 3)
      {
        venda_total_juros = venda_total + (venda_total * 0.08);
        porcent_juros = 8;
        valor_parcela = venda_total_juros / qnt_parcela;
      }
      printf("\nJuros Simples: %d%%\n", porcent_juros);
      printf("Parcelado em: %dX\n", qnt_parcela);
      printf("Total: RS%.2f\n", venda_total);
      printf("Total com juros: RS%.2f\n", venda_total_juros);
      printf("Valor da parcela: RS%.2f\n", valor_parcela);
    }
  }

  salvarArquivoTXT(carrinho, cart_size);
  free(carrinho);
  return;
}

void relatorioVendas(Item tabela[])
{
  sortQntVenda(tabela, contador);
  system("cls");
  printf("Relatorio de Vendas: \n");
  printf("Código\t| %-20s\t| Qnt. Estoque\t| Qnt. Vendido\n", "Nome");
  for (int i = 0; i < contador; i++)
  {
    if (tabela[i].quant_vend > 0)
    {
      printf("%d\t| %-20s\t| %d\t\t| \t%d\t\n", tabela[i].codigo, tabela[i].nome, tabela[i].quantidade, tabela[i].quant_vend);
    }
  }
}

