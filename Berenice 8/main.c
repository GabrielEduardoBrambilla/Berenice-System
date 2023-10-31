#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  int codigo;
  char nome[50];
  float valor;
  int quantidade;
  int quant_vend;
} Item;
Item *p;
int contador = 5;

int validador(int cod, Item tabela[], int contador);
void RelatorioVendas(Item tabela[]);
void visualizarEstoque(Item tabela[], int contador);
void Cadastroitem(Item tabela[], int *contador);
void visualizarEstoque(Item tabela[], int contador);
void attproduto(Item tabela[], int contador);
void excluirproduto(Item tabela[], int *contador);
void Lerprodutos(Item tabela[], int *contador);
void saveFile(Item tabela[], int contador);
void RelatorioVendas(Item tabela[]);
void sell();

int main()
{

  p = (Item *)malloc((contador + 1) * sizeof(Item));

  int opcao;

  Item tabela[100] = {
      {1, "pao de forma", 7.50, 0},
      {2, "pao de centeio", 8.69, 0},
      {3, "broa de milho", 5.00, 0},
      {4, "Sonho", 4.50, 0},
      {5, "Tubaina", 3.25, 0},
  };

  do
  {
    printf("Menu:\n");
    printf("1 - Produtos\n");
    printf("2 - Vendas\n");
    printf("3 - Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      system("cls");
      Visualizarprodutos(tabela, &contador);
      break;

    case 2:
      system("cls");
      sell(tabela, &contador);
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
  return 0;
}

void Visualizarprodutos(Item tabela[], int *contador)
{
  int opcao;
  do
  {
    printf("1 - Exibir\n");
    printf("2 - Cadastrar\n");
    printf("3 - Atualizar\n");
    printf("4 - Excluir\n");
    printf("5 - Salvar\n");
    printf("6 - Ler\n");
    printf("7 - Voltar\n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      system("cls");
      visualizarEstoque(tabela, *contador);
      break;
    case 2:
      system("cls");
      Cadastroitem(tabela, contador);
      break;
    case 3:
      system("cls");
      attproduto(tabela, *contador);
      break;
    case 4:
      system("cls");
      excluirproduto(tabela, contador);
      break;
    case 5:
      saveFile(tabela, contador);
      break;
    case 6:
      system("cls");
      Lerprodutos(tabela, contador);
      break;
    case 7:
      system("cls");
      break;
    default:
      system("cls");
      printf("Opção inválida!!\n");
      break;
    }
  } while (opcao != 7);
}

void sell(Item tabela[], int *contador)
{
  int opcao;
  printf("Menu\n");
  printf("1 - Realizar Venda:\n");
  printf("2 - Relatorio de Venda:\n");
  printf("3 - Sair");
  printf("Selecione: \n");
  scanf("%d", &opcao);

  switch (opcao)
  {
  case 1:
    system("cls");
    RealizarVenda(tabela, contador);
    break;

  case 2:
    system("cls");
    RelatorioVendas(tabela);
    break;

  case 3:
    system("cls");
    break;
  default:
    system("cls");
    printf("opcao invalida!!\n");
    break;
  }
  while (opcao != 3)
    ;
}

void visualizarEstoque(Item tabela[], int contador)
{
  printf("Código | Item           | Valor   | Quantidade | Produtos vendidos\n");
  for (int i = 0; i < contador; i++)
  {
    printf("%6d | %-15s | R$ %.2f | %d | %d \n", tabela[i].codigo, tabela[i].nome, tabela[i].valor, tabela[i].quantidade, tabela[i].quant_vend);
  }
}

void Cadastroitem(Item tabela[], int *contador)
{
  int quant_item = 0;
  int validar, quant, cod;
  int opcao;
  int test = *contador;
  printf("\n1 - Cadastrar Novo item: ");
  printf("\n2 - Adicionar estoque aos itens:");
  printf("\n3 - Voltar");
  printf("\nSelecione: ");
  scanf("%d", &opcao);
  getchar();

  do
  {
    if (opcao == 1)
    {
      printf("\nEscreva o número do código: ");
      scanf("%d", &cod);
      validar = validador(cod, tabela, *contador);
      if (validar == 0)
      {
        tabela[*contador].codigo = cod;
        printf("\nNome do item: ");
        scanf("%s", tabela[*contador].nome);
        printf("\nValor do item: ");
        scanf("%f", &tabela[*contador].valor);
        printf("\nQuantidade do item: ");
        scanf("%d", &tabela[*contador].quantidade);
        (*contador)++;
        return 1;
      }
    }
    else if (opcao == 2)
    {
      p = (Item *)malloc((test + 1) * sizeof(Item));

      printf("\nQual produto deseja adicionar estoque (codigo do produto): ");
      scanf("%d", &cod);
      for (int i = 0; i < *contador; i++)
      {
        if (cod == tabela[i].codigo)
        {
          printf("\nDigite a quantidade: ");
          scanf("%d", &quant);
          tabela[i].quantidade += quant;
        }
      }
      return 1;
    }
    else if (opcao == 3)
    {
      system("cls");
      printf("\nSaindo...\n");
    }
    if (opcao != 3)
    {
      printf("\n Codigo existente!!");
    }
  } while (opcao != 3);
}

int validador(int cod, Item tabela[], int contador)
{
  int validar;
  for (int i = 0; i < contador; i++)
  {
    if (cod == tabela[i].codigo)
    {
      validar = 0;
      return 1;
    }
  }
  printf("\nCódigo válido\n");
  return 0;
}

void attproduto(Item tabela[], int contador)
{
  int codigo_editado;
  int encontrado = 0;
  int verification;
  system("cls");
  printf("Código | Item           | Valor   | Quantidade\n");
  for (int i = 0; i < contador; i++)
  {
    printf("%6d | %-15s | R$ %.2f | %d | %d \n", tabela[i].codigo, tabela[i].nome, tabela[i].valor, tabela[i].quantidade);

    printf("Digite o codigo do produto a ser editado: ");
    scanf("%d", &codigo_editado);

    for (int i = 0; i < contador; i++)
    {
      if (tabela[i].codigo == codigo_editado)
      {
        encontrado = 1;
        printf("Produto encontrado:\n");
        printf("Codigo Produto: %d", tabela[i].codigo);
        printf("Nome Produto: %s\n", tabela[i].nome);
        printf("Valor Produto: %f\n", tabela[i].valor);
        printf("Quantidade Produto: %d\n", tabela[i].quantidade);

        char opcao[50];
        printf("O que você deseja editar (codigo, nome, valor, quantidade)? ");
        scanf("%s", opcao);

        if (strcmp(opcao, "nome") == 0)
        {
          printf("Digite o novo nome: ");
          scanf("%s", tabela[i].nome);
        }
        else if (strcmp(opcao, "codigo") == 0)
        {
          printf("Digite o novo codigo: ");
          scanf("%d", &tabela[i].codigo);
        }
        else if (strcmp(opcao, "valor") == 0)
        {
          printf("Digite o novo valor: ");
          scanf("%f", &tabela[i].valor);
        }
        else if (strcmp(opcao, "quantidade") == 0)
        {
          printf("Digite a nova quantidade: ");
          scanf("%d", &tabela[i].quantidade);
        }
        else
        {
          printf("Opcao invalida.\n");
        }
      }
    }

    if (!encontrado)
    {
      printf("Produto nao encontrado.\n");
    }
  }
}

void excluirproduto(Item tabela[], int *contador)
{
  int codigo_editado;
  char nome_close[100];
  char excluir[10];
  int verification;
  system("cls");
  printf("Código | Item           | Valor   | Quantidade\n");
  for (int i = 0; i < contador; i++)
  {
    printf("%6d | %-15s | R$ %.2f | %d | %d \n", tabela[i].codigo, tabela[i].nome, tabela[i].valor, tabela[i].quantidade);

    printf("Digite o codigo do produto deseja excluir : ");
    scanf("%d", &codigo_editado);
    int encontrar = 0;

    for (int i = 0; i < contador; i++)
    {
      if (tabela[i].codigo == codigo_editado)
      {
        printf("\nDeseja excluir %s? (excluir/cancelar):", tabela[i].nome);
        scanf("%s", excluir);
        if (strcmp(excluir, "excluir") == 0)
        {
          for (int j = i; j < contador - 1; j++)
          {
            tabela[j] = tabela[j + 1]; // Move os contatos restantes
          }
          contador--;
          printf("Contato excluído!\n");
          encontrar = 1;
          break;
        }
        else if (strcmp(excluir, "cancelar") == 0)
        {
          printf("Cancelado.\n");
          encontrar = 1;
          break;
        }
        else
        {
          printf("Resposta inválida. Digite 'excluir' ou 'cancelar'.\n");
        }
      }
    }
    if (!encontrar)
    {
      printf("Produto não encontrado.\n");
    }
  }
}

void saveFile(Item tabela[], int contador)
{
  FILE *pont_texto = fopen("produto.txt", "w");

  if (pont_texto == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }
  else
  {
    printf("\n criou arquivo");
  }

  fprint(pont_texto, "%d", contador);

  for (int i = 0; i < contador; i++)
  {
    fprintf(pont_texto, "%d,%s,%.2f,%d,%d\n", tabela[i].codigo, tabela[i].nome, tabela[i].valor, tabela[i].quantidade, tabela[i].quant_vend);
  }

  fclose(pont_texto);
}

void Lerprodutos(Item tabela[], int *contador)
{
  FILE *pont_texto = fopen("produto.txt", "r");

  if (pont_texto == NULL)
  {
    printf("Arquivo de produto não encontrado.\n");
    return;
  }
  else
  {
    printf("\n Leu o arquivo");
  }
  fscanf(pont_texto, "%d\n", &contador);

  //   p = (tabela *)malloc(contador+1*sizeof(tabela));

  for (int i = 0; i < contador; i++)
  {
    fprintf(pont_texto, "%d,%s,%.2f,%d,%d\n", tabela[i].codigo, tabela[i].nome, tabela[i].valor, tabela[i].quantidade, tabela[i].quant_vend);
  }
  fclose(pont_texto);
}

void RealizarVenda(Item tabela[], int contador)
{
  int has_estoque = 0, quant_upt, keep_sell, qnt_parcela, porcentagem_desc, porcent_juros, opc_pagamento, verification, i, actionCode = 0, estoque_verificacao = 0, venda_quantidade[5] = {0, 0, 0, 0, 0}, qnt_item;
  float valor_item, venda_total, *vendas_totais, venda_total_juros, pagamento_recebido, valor_parcela, troco, max, subtotal, subtotal_item[5] = {0, 0, 0, 0, 0};
  do
  {

    i = 0;
    for (i = 0; i < 5; i++)
    {
      if (tabela[tabela->codigo].quantidade <= 0)
      {
        estoque_verificacao++;

        if (estoque_verificacao == 5)
        {
          printf("Nenhum item possui estoque, cadastre o estoque antes de vender \n");
          return 1;
        }
      }
    }
    do
    {
      printf("Digite qual item deseja vender\n");
      scanf(" %d", &tabela->codigo);
      tabela->codigo--;
      if (tabela->codigo < 0 || tabela->codigo > 4)
      {
        system("cls");
        printf("Código invalido\n");
        has_estoque = 0;
      }
      else
      {
        if (tabela[tabela->codigo].quantidade <= 0)
        {
          has_estoque = 0;
        }
        else
        {
          has_estoque = 1;
        }

        if (has_estoque == 0)
        {
          system("cls");
          printf("Item sem estoque. Selecione outro item\n");
        }
      }

    } while ((tabela->codigo < 0 || tabela->codigo > 4) || has_estoque == 0);
    // Seleciona uma quantidade valida
    do
    {
      printf("Quantos itens deseja comprar\n");
      scanf("%d", &qnt_item);

      if (qnt_item < 0)
      {
        system("cls");
        printf("Quantidade invalida, digite novamente\n");
      }
      else
      {
        tabela[tabela->codigo].quantidade = tabela[tabela->codigo].quantidade - qnt_item;
        if (verification < 0)
        {
          printf("Estoque insuficiente, digite novamente\n");
          qnt_item = 0;
        }
      }
    } while (qnt_item <= 0);

    tabela[tabela->codigo].quantidade -= qnt_item;

    valor_item = tabela[tabela->codigo].valor;
    subtotal = tabela[tabela->codigo].valor * qnt_item;

    venda_quantidade[tabela->codigo] += qnt_item;

    subtotal_item[tabela->codigo] += subtotal;

    venda_total += subtotal;
    do
    {
      keep_sell = 0;
      printf("Deseja vender outro produto?\n");
      printf("1 - sim\n");
      printf("2 - não\n");
      scanf("%d", &keep_sell);

      if (keep_sell != 1 && keep_sell != 2)
      {
        keep_sell = 0;
      }
    } while (keep_sell == 0);

    if (keep_sell == 2)
    {
      system("cls");
      printf("Item (código)\tNome do Item\tValor (Unidade)\t Quant \tSub-Total\n");
      i = 0;
      for (i = 0; i < 5; i++)
      {
        if (venda_quantidade[i] > 0)
        {
          printf("%d\t\t%s\t    R$ %.2f\t %d \tR$ %.2f\n", i + 1, tabela->nome, tabela->valor, tabela->quantidade, subtotal_item[i]);
        }
      }
      printf("\t\t\t\t\t\t Total\tR$ %.2f", venda_total);

      max = subtotal_item[0];
      i = 0;
      for (i = 0; i < 5; i++)
      {
        if (max < subtotal_item[i])
        {
          max = subtotal_item[i];
        }
      }
      printf("\nO maior valor é: %.2f\n", max);

      printf("Deseja pagar a vista ou a prazo digite:\n");
      printf("Total da venda: RS %.2f\n", venda_total);
      void relatorioVendas(tabela);
      do
      {

        printf("1 - para avista\n");
        printf("2 - para a prazo\n");
        scanf(" %d", &opc_pagamento);
        if (opc_pagamento != 1 && opc_pagamento != 2)
        {
          printf("Opçao invalida\n");
        }

      } while (opc_pagamento != 1 && opc_pagamento != 2);

      // Verifica se a opção de pagamento selecionada foi A ou a
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
          scanf("%f", &pagamento_recebido);
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
          printf("Tudo certo sem necessidade de troco \n");
        }
      }
      else
      {
        do
        {
          printf("Digite a quantidade de vezes que deseja parcelar\n");
          scanf("%d", &qnt_parcela);
          if (qnt_parcela <= 0)
          {
            system('cls');
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
  } while (keep_sell != 2);
}

void RelatorioVendas(Item tabela[])
{
  float *vendas_totais;
  system("cls");
  printf("Relatorio de fechamento de caixa: \n");
  printf("Item (codigo)\tNome do item\tQuantidade\nVendidos");
  for (int i = 0; i < contador; i++)
  {
    if (vendas_totais[i] > 0)
    {
      printf("%d\t\t%s\t    %d\t\t%d", tabela->codigo, tabela->nome, tabela->quantidade, vendas_totais[i]);
    }
  }
}
