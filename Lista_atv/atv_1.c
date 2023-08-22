#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
// Atividade 1
    float raio, altura, volume ;
    printf("\n digite o valor do raio: ");
    scanf("%f", &raio);

    printf("\n digite o valor da altura: ");
    scanf("%f", &altura);

    volume = (3,14*(raio*raio)*altura);
    printf("o valor de volume e: %f", volume);

    if (volume>=1000){
        printf("\n suficiente");
    }
    else{
    printf("\n insuficiente");
    }


    return 0;

}
