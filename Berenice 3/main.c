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

int validador(int cod, Item tabela[]);
void RelatorioVendas(Item tabela[]);
void cadastroitem(Item tabela[]);
void visualizarEstoque(Item tabela[]);
void atualziarProd(Item tabela[]);
void excluirproduto(Item tabela[]);
void Lerprodutos(Item tabela[]);
void saveFile(Item tabela[]);
void RelatorioVendas(Item tabela[]);
void sell();

void initializeDefaultItems()
{
  tabela[0].codigo = 1;
  strcpy(tabela[0].nome, "pao de forma");
  tabela[0].valor = 7.50;
  tabela[0].quantidade = 10;
  tabela[0].quant_vend = 1000;

  tabela[1].codigo = 2;
  strcpy(tabela[1].nome, "pao de centeio");
  tabela[1].valor = 8.69;
  tabela[1].quantidade = 10;
  tabela[1].quant_vend = 10;

  tabela[2].codigo = 3;
  strcpy(tabela[2].nome, "broa de milho");
  tabela[2].valor = 5.00;
  tabela[2].quantidade = 10;
  tabela[2].quant_vend = 100;

  tabela[3].codigo = 4;
  strcpy(tabela[3].nome, "Sonho");
  tabela[3].valor = 4.50;
  tabela[3].quantidade = 10;
  tabela[3].quant_vend = 100;

  tabela[4].codigo = 5;
  strcpy(tabela[4].nome, "Tubaina");
  tabela[4].valor = 3.25;
  tabela[4].quantidade = 10;
  tabela[4].quant_vend = 100;
}

int main()
{
  int opcao;

  tabela = (Item *)malloc(contador * sizeof(Item));
  initializeDefaultItems();
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
      produtos(tabela);
      break;

    case 2:
      system("cls");
      sell(tabela);
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

// FUNÇÕES UTILITARIAS
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
    if (*var >= minRange && *var <= maxRange)
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
    printf("5 - Salvar\n");
    printf("6 - Ler\n");
    printf("7 - Voltar\n");
    scanf("%d", &opcao);

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
      saveFile(tabela);
      break;
    case 6:
      system("cls");
      Lerprodutos(tabela);
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

void visualizarEstoque(Item tabela[])
{
  printf("Código\t| %-20s\t| Valor\t\t| Quantidade\t| Produtos Vendidos\n", "Nome");
  for (int i = 0; i < contador; i++)
  {
    printf("%d\t| %-20s\t| R$ %.2f\t| %d\t\t| %d\n", tabela[i].codigo, tabela[i].nome, tabela[i].valor, tabela[i].quantidade, tabela[i].quant_vend);
  }
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
  char nome_close[100];
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
      printf("Código\t| %-20s\t| Valor\t\t| Quantidade\t| Produtos Vendidos\n", "Nome");
      printf("%d\t| %-20s\t| R$ %.2f\t| %d\t\t| %d\n", tabela[i].codigo, tabela[i].nome, tabela[i].valor, tabela[i].quantidade, tabela[i].quant_vend);
      printf("\nDeseja realmente excluir este item ");
      printf("\n1- Confirmar\n2- Cancelar\n");
      inputNumRange(&confirm, 1, 2);

      if (confirm == 1)
      {
        // Substitui/sob-escreve o item com o codigo digitado pelo usuario pelo ultimo item da struct
        tabela[codigo_editar].codigo = tabela[contador].codigo;
        strcpy(tabela[codigo_editar].nome, tabela[contador].nome);
        tabela[codigo_editar].quant_vend = tabela[contador].quant_vend;
        tabela[codigo_editar].quantidade = tabela[contador].quantidade;
        tabela[codigo_editar].valor = tabela[contador].valor;

        // Diminui o contador
        contador--;
        // Realoca o espaço da struct com uma posição a menos excluindo o ultimo item
        tabela = (Item *)realloc(tabela, (contador) * sizeof(Item));

        printf("\nProduto excluído!\n");
        return;
      }
      if (confirm == 2)
      {
        printf("\nCancelado.\n");
        return;
      }
    }
  }
}

void saveFile(Item tabela[])
{
  FILE *file = fopen("produto.bin", "wb");

  if (file == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }
  else
  {
    printf("\nCriou arquivo\n");
  }
  fwrite(&contador, sizeof(int), 1, file);

  for (int i = 0; i < contador; i++)
  {
    fwrite(&tabela[i].codigo, sizeof(int), 1, file);     // Write 'codigo' as binary (int)
    fwrite(&tabela[i].nome, sizeof(char), 50, file);     // Write 'nome' as binary (char array)
    fwrite(&tabela[i].valor, sizeof(float), 1, file);    // Write 'valor' as binary (float)
    fwrite(&tabela[i].quantidade, sizeof(int), 1, file); // Write 'quantidade' as binary (int)
    fwrite(&tabela[i].quant_vend, sizeof(int), 1, file); // Write 'quant_vend' as binary (int)
  }

  fclose(file);
}

void Lerprodutos(Item tabela[])
{
  FILE *file = fopen("produto.bin", "rb");

  if (file == NULL)
  {
    printf("\nArquivo de produto não encontrado.\n");
    return;
  }
  else
  {
    printf("\nLeu o arquivo\n");
  }

  fread(&contador, sizeof(int), 1, file);

  tabela = (Item *)malloc(contador * sizeof(Item));

  for (int i = 0; i < contador; i++)
  {
    fread(&tabela[i].codigo, sizeof(int), 1, file);
    fread(&tabela[i].nome, sizeof(char), 50, file);
    fread(&tabela[i].valor, sizeof(float), 1, file);
    fread(&tabela[i].quantidade, sizeof(int), 1, file);
    fread(&tabela[i].quant_vend, sizeof(int), 1, file);
  }
  visualizarEstoque(tabela);

  fclose(file);
}

void RealizarVenda(Item tabela[])
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

void sell(Item tabela[])
{
  int opcao;
  printf("Menu\n");
  printf("1 - Realizar Venda:\n");
  printf("2 - Relatorio de Venda:\n");
  printf("3 - Sair");
  printf("Selecione: \n");
  inputNum(&opcao);

  switch (opcao)
  {
  case 1:
    system("cls");
    RealizarVenda(tabela);
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
