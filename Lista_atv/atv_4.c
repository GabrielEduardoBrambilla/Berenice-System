#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{

// Atividade 4
    int input_1, input_2, input_3;
    int maior = 0, medio = 0, menor =0;
    printf("Digite tres valores\n");

    scanf("%d ", &input_1);

    scanf("%d", &input_2);

    scanf("%d", &input_3);

    if(input_1 > input_2 && input_1 > input_3){
        maior = input_1;
        if(input_2 > input_3){
            medio = input_2;
            menor = input_3;
        }else{
            medio = input_3;
            menor = input_2;
        }
    }
    else{
        if (input_2 > input_1 && input_2 > input_3){
            maior= input_2;
            if(input_1 > input_3){
                medio = input_1;
                menor = input_3;
            }else{
                medio = input_1;
                menor = input_2;
            }
        }
        else{
            maior = input_3;
            if(input_1 > input_2){
                medio = input_1;
                menor = input_2;
            }else{
                medio = input_2;
                menor = input_1;
            }
        }
    }

    printf("Maior: %d \nMedio: %d \nMenor: %d ", maior, medio, menor);

    return 0;

}
