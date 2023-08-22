#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
// Atividade 3
    int horas, minutos, segundos, segundos_input;
    printf("\n digite a hora desejada: ");
    scanf("%d", &horas);

    printf("\n digite os minutos desejados: ");
    scanf("%d", &minutos);

    printf("\n digite os segundos desejados: ");
    scanf("%d", &segundos_input);

    segundos = (horas*60)*60+(minutos*60)+segundos_input;
    printf("segundos igual: %d", segundos);

    return 0;

}
