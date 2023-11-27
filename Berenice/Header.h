#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct
{
  int codigo;
  char nome[25];
  float valor;
  int quantidade;
  int quant_vend;
} Item;

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
  tabela[1].quant_vend = 5;

  tabela[2].codigo = 3;
  strcpy(tabela[2].nome, "broa de milho");
  tabela[2].valor = 5.00;
  tabela[2].quantidade = 10;
  tabela[2].quant_vend = 3;

  tabela[3].codigo = 4;
  strcpy(tabela[3].nome, "Sonho");
  tabela[3].valor = 4.50;
  tabela[3].quantidade = 10;
  tabela[3].quant_vend = 9;

  tabela[4].codigo = 5;
  strcpy(tabela[4].nome, "Tubaina");
  tabela[4].valor = 3.25;
  tabela[4].quantidade = 10;
  tabela[4].quant_vend = 2;
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

#endif // HEADER_H_INCLUDED
