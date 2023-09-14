#include <stdio.h>
#include <string.h>

// Variáveis globais
int estoque[5] = {100, 100, 100, 100, 100};
float valor_item[5] = {7.50, 8.69, 5.00, 4.50, 3.25};
char nomes[5][20] = {"Pão de Forma", "Pão de Centeio", "Broa de Milho", "Sonho", "Tubaina"};

int cadastro();
void ver();
void venda();

int main()
{
  int menu;

  do
  {
    printf("\n1 - Cadastrar estoque\n2 - Visualizar estoque\n3 - Realizar venda\n4 - Sair\n\nSelecione a opção desejada: ");
    scanf("%i", &menu);
    getchar();

    switch (menu)
    {
    case 1:
      cadastro();
      break;
    case 2:
      ver();
      break;
    case 3:
      venda();
      break;
    case 4:
      printf("\nEncerrando...\n\n");
      break;
    default:
      printf("\nOpção inválida. Tente novamente.\n");
    }
  } while (menu != 4);

  return 0;
}

int cadastro()
{
  char continuar;
  int codigo, quantidade;

  printf("\n 1-Pão de Forma (estoque: %d)\n 2-Pão de Centeio (estoque: %d)\n 3-Broa de Milho (estoque: %d)\n 4-Sonho (estoque: %d)\n 5-Tubaina (estoque: %d)\n", estoque[0], estoque[1], estoque[2], estoque[3], estoque[4]);

  do
  {
    printf("\nDeseja alterar o estoque? (s - sim / n - não): ");
    scanf(" %c", &continuar);
    getchar();

    switch (continuar)
    {
    case 's':
      printf("\nDigite o código do item que deseja alterar no estoque: ");
      scanf("%i", &codigo);
      if (codigo >= 1 && codigo <= 5)
      {
        printf("\nDigite a quantidade de produtos para o estoque[%i]: ", codigo - 1);
        scanf("%i", &quantidade);
        if (quantidade >= 0)
        {
          estoque[codigo - 1] = quantidade;
          printf("\nO valor foi alterado.\n");
        }
        else
        {
          printf("\nQuantidade não pode ser negativa.\n");
        }
      }
      else
      {
        printf("\nCódigo inválido.\n");
      }
      break;
    case 'n':
      printf("\nRetornando ao menu.\n");
      break;
    default:
      printf("\nOpção inválida. Tente novamente.\n");
    }
  } while (continuar != 'n');
}

void ver()
{
  char retornar;

  printf("\nItem (código) Nome do Item Valor (Unidade) Estoque\n");
  for (int i = 0; i < 5; i++)
  {
    printf("%d %s R$ %.2f %d\n", i + 1, nomes[i], valor_item[i], estoque[i]);
  }

  do
  {
    printf("\nPressione 'r' para retornar ao menu: ");
    scanf(" %c", &retornar);
  } while (retornar != 'r');
}

void venda()
{
  int item, quantidade, vendidos[5] = {0}, pagamento, parcelas;
  float total = 0, soma[5] = {0}, troco, pago, cadaparcela;
  char cont;

  do
  {
    printf("\n _________________________________ \n |          0 para sair            |\n _________________________________ \n | Código |     Produto    | Valor | \n |________|________________|_______| \n |   1    |  Pão de forma  | 7.50  | \n |   2    | Pão de centeio | 8.69  | \n |   3    | Broa de milho  | 5.00  | \n |   4    |     Sonho      | 4.50  | \n |   5    |    Tubaina     | 3.25  | \n |________|________________|_______| \n ");
    scanf("%i", &item);
    getchar();

    if (item == 0)
    {
      printf("\nRetornando...\n");
      return; // Sair do loop se o usuário digitar 0
    }
    else if (item >= 1 && item <= 5)
    {
      printf("\nQuantidade de %s: ", nomes[item - 1]);
      scanf("%d", &quantidade);

      if (quantidade > 0 && quantidade <= estoque[item - 1])
      {
        estoque[item - 1] -= quantidade;
        total += valor_item[item - 1] * quantidade;
        soma[item - 1] += valor_item[item - 1] * quantidade;
        vendidos[item - 1] += quantidade; // Atualiza o total de itens vendidos

        printf("\n%d %s(s) adicionado(s) ao carrinho\n", quantidade, nomes[item - 1]);
      }
      else
      {
        printf("\nQuantidade inválida ou estoque insuficiente.\n");
      }
    }
    else
    {
      printf("\nItem não encontrado, tente novamente.\n");
      continue; // Volte ao início do loop para selecionar outro item
    }

    do
    {
      printf("\nDeseja selecionar mais itens? (s - sim / n - não): ");
      scanf(" %c", &cont);
      getchar();
      if (cont != 's' && cont != 'n')
      {
        printf("Opção inválida. ");
      }
    } while (cont != 's' && cont != 'n');
  } while (cont == 's');

  // Calcula o total de itens vendidos
  int quant_total = 0;
  for (int i = 0; i < 5; i++)
  {
    quant_total += vendidos[i];
  }

  printf("\n-------------------------------------\n|           Cupom Fiscal            |\n-------------------------------------\n| Quantidade | Nome do Item | Valor |\n-------------------------------------\n");

  for (int i = 0; i < 5; i++)
  {
    if (vendidos[i] > 0)
    {
      printf("|    %d     |  %s...%.2f  \n", vendidos[i], nomes[i], soma[i]);
    }
  }

  printf("-------------------------------------\n");
  printf("-------------------------------------\n|  Total de Itens Vendidos = %d  |\n-------------------------------------\n", quant_total); // Exibe o total de itens corretamente
  printf("|          Total = R$ %.2f         |\n-------------------------------------\n", total);

  float maior_valor = soma[0];
  for (int i = 1; i < 5; i++)
  {
    if (soma[i] > maior_valor)
    {
      maior_valor = soma[i];
    }
  }

  printf("\n-------------------------------------\n| Maior valor de um item = R$ %.2f |\n-------------------------------------\n", maior_valor);

  printf("\n _________________________________\n |     A vista    |    A prazo     | \n |       1        |       2        | \n |________________|________________|");

  for (int j = 0; j < 1;)
  {
    printf("\nSelecione a forma de pagamento: ");
    scanf("%i", &pagamento);

    if (pagamento == 1)
    {
      j = 1;
      if (total >= 0 && total <= 50)
      {
        total *= 0.95;
      }
      else if (total > 50 && total < 100)
      {
        total *= 0.90;
      }
      else if (total >= 100)
      {
        total *= 0.82;
      }

      printf("\nTotal a pagar: %.2f \n", total);
      for (int i = 0; i < 1;)
      {

        printf("Valor pago pelo cliente: ");
        scanf("%f", &pago);
        if (pago < total)
        {
          printf("\nValor insuficiente.\n");
        }
        else
        {
          troco = pago - total;
          printf("\nTroco a ser devolvido: %.2f \n", troco);
          i = 1;
        }
      }
    }
    else if (pagamento == 2)
    {
      j = 1;
      for (int i = 0; i < 1;)
      {

        printf("Selecione o número de parcelas: ");
        scanf("%d", &parcelas);

        if (parcelas > 0)
        {
          if (parcelas <= 3)
          {
            total *= 1.05;
          }
          else
          {
            total *= 1.08;
          }

          cadaparcela = total / parcelas;
          printf("\nValor de cada parcela: %.2f \n", cadaparcela);
          printf("Valor total parcelado: %.2f \n", total);
          i = 1;
        }
        else
        {
          printf("Quantidade de parcelas inválida.\n");
        }
      }
    }
    else
    {
      printf("Forma de pagamento inválida.\n");
    }
  }
}