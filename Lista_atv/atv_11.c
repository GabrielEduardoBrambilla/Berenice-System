#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{

//atividade 11
    int opcao;
    printf("Bem-vindo(a) à Berenice - Menu de Produtos\n");
    printf("Opções:\n");
    printf("1. pao de centeio\n");
    printf("2. pao de forma\n");
    printf("3. broa\n");
    printf("4. sonho\n");
    printf("5. tubaina\n");

    printf("Escolha uma opção 1 a 5: \n");
    scanf("%d", &opcao);

    if (opcao>=1 && opcao <=5){
        switch (opcao) {
            case 1:
                printf("Você escolheu: pao de centeio\n");
                break;
            case 2:
                printf("Você escolheu: pao de forma\n");
                break;
            case 3:
                printf("Você escolheu: broa\n");
                break;
            case 4:
                printf("Você escolheu: sonho\n");
                break;
            case 5:
                printf("Você escolheu: tubaina\n");
                break;
            default:
                printf("Opção não encontrada!\n");
                break;
        }
    }else
    printf("opcao invalida");

    return 0;
}
