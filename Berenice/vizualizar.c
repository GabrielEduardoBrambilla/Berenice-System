#include "Header.h"

void visualizarEstoque(Item tabela[])
{
  sortCode(tabela, contador);
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
  sortQntVenda(tabela, contador);
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
