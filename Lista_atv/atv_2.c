#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
// Atividade 2
    float media, prova, trabalho;

    printf("\n Insira a nota da sua prova: ");
    scanf("%f", &prova);

    printf("\n Insira a nota do seu trabalho: ");
    scanf("%f", &trabalho);

    media = (prova * 0.4) + (trabalho * 0.6); // Média ponderada correta

    printf("\n Valor da prova: %.2f", prova);
    printf("\n Valor do trabalho: %.2f", trabalho);
    printf("\n Media: %4.f", media);

    if (media >=70){
      printf("\n aprovado");
    }
    else{
      printf("\n reprovado");
    }

    return 0;

}
