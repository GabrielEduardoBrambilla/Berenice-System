#include "Header.h"

void sortQntVenda(Item *tabela, int size_tabela)
{
  int i, j;
  for (i = 0; i < size_tabela - 1; i++)
  {
    for (j = 0; j < size_tabela - i - 1; j++)
    {
      if (tabela[j].quant_vend < tabela[j + 1].quant_vend)
      {
        // Swap elements
        Item temp = tabela[j];
        tabela[j] = tabela[j + 1];
        tabela[j + 1] = temp;
      }
    }
  }
}
void sortCode(Item *tabela, int size_tabela)
{
  int i, j;
  for (i = 0; i < size_tabela - 1; i++)
  {
    for (j = 0; j < size_tabela - i - 1; j++)
    {
      if (tabela[j].codigo > tabela[j + 1].codigo)
      {
        // Swap elements
        Item temp = tabela[j];
        tabela[j] = tabela[j + 1];
        tabela[j + 1] = temp;
      }
    }
  }
}
