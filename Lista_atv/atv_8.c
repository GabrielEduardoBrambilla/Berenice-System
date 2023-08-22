#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
// Atividade 8
    int input_ano, verificacao_ano;
    float verificacao_ano_100, verificacao_ano_400, verificacao_ano_04;

    printf("Digite um ano ex: 2023\n");
    scanf("%d", &input_ano);

    verificacao_ano_100 = input_ano % 100;
    verificacao_ano_400 = input_ano % 400;
    verificacao_ano_04 = input_ano % 04;

    if(verificacao_ano_100 == 0 && verificacao_ano_400 == 0){
        printf("Nao e bissexto\n");
    }else{
        if(verificacao_ano_04 == 0 && !verificacao_ano_100 ==0){
          printf("E bissexto\n");
        }else{
            printf("Nao e bissexto\n");
        }
    }

    return 0;

}
