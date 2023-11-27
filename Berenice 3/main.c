
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
typedef struct
{
  int codigo;
  char nome[25];
  float valor;
  int quantidade;
  int quant_vend;
} Item;

int contador = 5;
int main()
{

  Item *tabela;

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

void initializeDefaultItems(Item *tabela)
{
  tabela[0].codigo = 1;
  strcpy(tabela[0].nome, "pao de forma");
  tabela[0].valor = 7.50;
  tabela[0].quantidade = 10;
  tabela[0].quant_vend = 2;

  tabela[1].codigo = 2;
  strcpy(tabela[1].nome, "pao de centeio");
  tabela[1].valor = 8.69;
  tabela[1].quantidade = 10;
  tabela[1].quant_vend = NULL;

  tabela[2].codigo = 3;
  strcpy(tabela[2].nome, "broa de milho");
  tabela[2].valor = 5.00;
  tabela[2].quantidade = 10;
  tabela[2].quant_vend = NULL;

  tabela[3].codigo = 4;
  strcpy(tabela[3].nome, "Sonho");
  tabela[3].valor = 4.50;
  tabela[3].quantidade = 10;
  tabela[3].quant_vend = NULL;

  tabela[4].codigo = 5;
  strcpy(tabela[4].nome, "Tubaina");
  tabela[4].valor = 3.25;
  tabela[4].quantidade = 10;
  tabela[4].quant_vend = NULL;
}

// FUNÇÕES UTILITARIAS
void inputNum(int *var)
{
  int validInput = 0;
  int c;
  do
  {
    if (scanf("%d", var) != 1)
    {
      // Clear input buffer
      while ((c = getchar()) != '\n' && c != EOF)
        ;
      printf("\nNumero invalido. Tente novamente: ");
    }
    else
    {
      if (*var < 0)
      {
        // Clear input buffer
        *var = NULL;
        while ((c = getchar()) != '\n' && c != EOF)
          ;
        printf("\nNumero invalido. Tente novamente: ");
      }
      else
      {
        validInput = 1;
        // Clear input buffer
        while ((c = getchar()) != '\n' && c != EOF)
          ;
      }
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
      printf("\nString invalida. Tente novamente:\n");
    }
    else if (strlen(str) > 25)
    {
      printf("\nString invalida. Tente novamente:\n");
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
    inputNumRange(&opcao, 1, 7);

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

  printf("Código\t| %-20s\t| Valor\t\t| Quantidade\t\n", "Nome");
  for (int i = 0; i < contador; i++)
  {
    printf("%d\t| %-20s\t| R$ %.2f\t| %d\t\t\n", tabela[i].codigo, tabela[i].nome, tabela[i].valor, tabela[i].quantidade);
  }
  return;
}

void visualizarComanda(Item tabela[], int counter)
{
  float venda_total;
  printf("Código\t| %-20s\t| Valor \t|   Quantidade\t| Sub-Total\n", "Nome");
  for (int i = 0; i < counter; i++)
  {
    if (tabela[i].quantidade >= 0)
    {
      printf("%d\t| %-20s\t| R$ %-.2f\t| %7d \t| R$ %-.2f\n", tabela[i].codigo, tabela[i].nome, tabela[i].valor, tabela[i].quantidade, (tabela[i].valor * tabela[i].quantidade));
      venda_total += tabela[i].valor * tabela[i].quantidade;
    }
  }
  printf("Total\tR$ %.2f\n", venda_total);

  return;
}

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

          printf("\nCod in table: %d\n", tabela[contador].codigo);

          if (validador(tabela[contador].codigo, tabela) == 1)
          {
            system("cls");
            printf("\nCódigo invalido ou em uso, tente novamente ");
          }
        } while (validador(tabela[contador].codigo, tabela) == 1);

        //  Nome Item
        printf("\nNome do produto: ");
        inputString(&tabela[contador].nome);

        printf("\nName in table %s ", tabela[contador].nome);

        //  Preco unidade
        printf("\nPreço unitario: ");
        inputFloat(&tabela[contador].valor);

        printf("\nPreço in table: %f\n", tabela[contador].valor);

        //  Quant item
        printf("\nQuantidade em estoque: ");
        inputNum(&tabela[contador].quantidade);
        printf("\nQuantidade in table: %d\n", tabela[contador].quantidade);
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

void salvarArquivoBN(Item tabela[])
{
  FILE *file = fopen("produto.bin", "wb");

  if (file == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }
  else
  {
    // printf("\nCriou arquivo\n");
  }
  fwrite(&contador, sizeof(int), 1, file);

  for (int i = 0; i < contador; i++)
  {
    fwrite(&tabela[i].codigo, sizeof(int), 1, file);
    fwrite(&tabela[i].nome, sizeof(char), 50, file);
    fwrite(&tabela[i].valor, sizeof(float), 1, file);
    fwrite(&tabela[i].quantidade, sizeof(int), 1, file);
    fwrite(&tabela[i].quant_vend, sizeof(int), 1, file);
  }

  fclose(file);
}

void lerprodutos(Item *tabela)
{
  FILE *file = fopen("produto.bin", "rb");

  if (file == NULL)
  {
    printf("\nArquivo de produto não encontrado.\n");
    return;
  }
  else
  {
    // printf("\nLeu o arquivo\n");
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

void salvarArquivoTXT(Item tabela[], int contador)
{
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  char filename[22];

  sprintf(filename, "%d-%02d-%02d_%02d-%02d-%02d.txt",
          tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
          tm.tm_hour, tm.tm_min, tm.tm_sec);

  FILE *file = fopen(filename, "w");

  if (file == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }
  else
  {
    printf("\nCriou arquivo\n");
  }
  fprintf(file, "%d\n", contador);

  for (int i = 0; i < contador; i++)
  {
    fprintf(file, "%d\n", tabela[i].codigo);
    fprintf(file, "%s\n", tabela[i].nome);
    fprintf(file, "%f\n", tabela[i].valor);
    // quantidade vendida no carrinho
    fprintf(file, "%d\n", tabela[i].quantidade);
  }

  fclose(file);
}

void relatorioVendas(Item tabela[])
{
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
