#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int telefone;
    int data;
    char cnome[25];
} cliente;

void store_user(cliente **c, int *counter);
void view_all(cliente *c, int contador);
void search(cliente *c, int contador);

int main()
{
    cliente *cliente;
    int contador = 0;
    int opc = 0;
    do
    {
        printf("\nMenu");
        printf("\n1 - Armazenar");
        printf("\n2 - Visualizar todos");
        printf("\n3 - Buscar por numero");
        printf("\n4 - Sair\n");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            printf("Dentro switch");
            getchar();
            store_user(&cliente, &contador);
            break;
        case 2:
            view_all(cliente, contador);
            break;
        case 3:
            search(cliente, contador);
            break;
        }
    } while (opc != 3);
    return 0;
}

void view_all(cliente *c, int contador)
{
    printf("\nCliente\t|\tTelefone\t|\tData\t|Nome\t|");
    for (int i = 0; i < contador; i++)
    {
        printf("\n%d\t|\t%d\t\t|\t%d\t|\t%s\t|", i, c[i].telefone, c[i].data, c[i].cnome);
    }
}
void search(cliente *c, int contador)
{
    int search;
    int found, index = NULL;
    printf("\n Digite o numero do cliente que deseja procurar: \n");
    scanf("%d", &search);
    for (int i = 0; i < contador; i++)
    {
        if (search == c[i].telefone)
        {
            index = i;
        }
    }
    if (index != NULL)
    {
        printf("\nCliente\t|\tTelefone\t|\tData\t|Nome\t|");
        printf("\n%d\t|\t%d\t\t|\t%d\t|\t%s\t|", index, c[index].telefone, c[index].data, c[index].cnome);
    }
}

void store_user(cliente **c, int *counter)
{
    printf("AQUI");
    if (*counter == 0)
    {
        *counter += 1;
        *c = malloc(*counter * sizeof(cliente));
        printf("DPS malloc");
        getchar();
    }
    else
    {
        *counter += 1;
        realloc(*c, *counter * sizeof(cliente));
    }
    printf("\nNome, é uma string de 25 char: ");
    gets(&c[*counter - 1]->cnome);
    // printf("String %s ", c[*counter - 1]->cnome);
    printf("\nTelefone em numeros somente: ");
    scanf("%d", &c[*counter - 1]->telefone);
    // printf("Telefone %d ", c[*counter - 1]->telefone);
    printf("\nData, mes dia ano em numeros somente, sem espaços: ");
    scanf("%d", &c[*counter - 1]->data);
    // printf("Data %d ", c[*counter - 1]->data);
}
