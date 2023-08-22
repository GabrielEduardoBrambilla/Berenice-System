#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
// Atividade 7
    int input_num, conta;
    printf("Digite um valor inteiro\n");
    scanf("%d", &input_num);

    conta = input_num % 2;

    if( conta == 0){
        printf("Numero par\n");
    }
    else{
        printf("Numero impar\n");
    }

    return 0;
}
