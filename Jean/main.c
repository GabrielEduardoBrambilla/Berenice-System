#include <stdio.h>
#include <stdlib.h>

struct Contato
{
  char nome[50];
  int numero;
};

struct Contato add[1000];

void addcontato();
void listacontato();
void editarcontato();
int main()
{
  int opcao;
  int numContatos = 0;
  printf("......Lista de contatos......\n");

  do
  {
    printf("1 - Adicionar contatos\n");
    printf("2 - Lista de contatos\n");
    printf("3 - Fechar lista\n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      if (numContatos < 1000)
      {
        addcontato();
        numContatos++;
      }
      else
      {
        printf("Lista de contatos está cheia.\n");
      }
      break;
    case 2:
      listacontato();
      break;
    }

  } while (opcao != 3);

  system("cls");
  printf("\nLista fechada\n");

  return 0;
}

void addcontato()
{
  system("cls");
  int i;
  char cancelar;
  for (i = 0; i < 1000; i++)
  {
    if (add[i].numero == 0)
    {
      printf("........ADICIONAR CONTATO........\n");
      printf("\nNome: ");
      fflush(stdin);
      gets(add[i].nome);
      printf("\nNumero: ");
      scanf("%d", &add[i].numero);
      printf("Deseja adicionar outro contato? (s/n): ");
      scanf(" %c", &cancelar);
      if (cancelar != 's')
      {
        break;
      }
    }
  }
}

void listacontato()
{
  system("cls");
  int i;
  for (i = 0; i < 1000; i++)
  {
    if (add[i].numero != 0)
    {
      printf("......lista de contatos......\n");
      printf("Nome: %s\n", add[i].nome);
      printf("Numero: %d\n", add[i].numero);
    }
  }
}

void editarcontato()
{
  char edit;
  char contato_nome;
  short int index;
  system("cls");
  printf("Digite o nome do contato\n");
  scanf("%s", contato_nome);

  for (int i = 0; i < 1000; i++)
  {
    char nomezinho = add[i].nome;
    if (nomezinho = contato_nome)
    {
      index = i;
    }
  }

  printf("Contato sendo editado");
  printf("Nome: %s", add[index].nome);
  prinft("Numero: %d", add[index].numero);
  do
  {
    printf("Qual deseja editar?");
    scanf("%c", &edit);
    if (edit != 'nome' || edit != !!'numero')
    {
      system("cls");
      printf("Erro tente novamente");
    }
  } while (edit != 'nome' || edit != !!'numero');
  if (edit == 'nome')
  {
    printf("digite o nome: ");
    scanf("%s", add[index].nome);
  }
  if (edit == 'numero')
  {
    prinft("digite o numero: ");
    scanf("%d", add[index].numero);
  }
}