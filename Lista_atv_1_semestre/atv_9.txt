#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{

// Atividade 9
  int num_mes;
  printf("Digite um numero de mes entre 1 e 12\n");
  scanf("%d", &num_mes);

    switch (num_mes) {
        case 1:
            printf("Janeiro tem 31 dias.\n");
            break;
        case 2:
            printf("Fevereiro tem 28 dias.\n");
            break;
        case 3:
            printf("Março tem 31 dias.\n");
            break;
        case 4:
            printf("Abril tem 30 dias.\n");
            break;
        case 5:
            printf("Maio tem 31 dias.\n");
            break;
        case 6:
            printf("Junho tem 30 dias.\n");
            break;
        case 7:
            printf("Julho tem 31 dias.\n");
            break;
        case 8:
            printf("Agosto tem 31 dias.\n");
            break;
        case 9:
            printf("Setembro tem 30 dias.\n");
            break;
        case 10:
            printf("Outubro tem 31 dias.\n");
            break;
        case 11:
            printf("Novembro tem 30 dias.\n");
            break;
        case 12:
            printf("Dezembro tem 31 dias.\n");
            break;
        default:
            printf("Número invalido.\n");
    }

    return 0;
}
