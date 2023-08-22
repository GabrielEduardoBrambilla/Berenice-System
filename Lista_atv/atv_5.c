#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
// Atividade 5
    int input_A, input_B, resultado;
    printf("Digite dois valores inteiros\n");

    scanf("%d", &input_A);

    scanf("%d", &input_B);

    resultado = (input_A+input_B)*(input_A+input_B);
    printf("Resultado: %d \n", resultado);
    return 0;
}
