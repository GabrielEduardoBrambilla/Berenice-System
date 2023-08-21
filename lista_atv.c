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



// Atividade 5
    int input_A, input_B, resultado;
    printf("Digite dois valores inteiros\n");

    scanf("%d", &input_A);

    scanf("%d", &input_B);

    resultado = (input_A+input_B)*(input_A+input_B);
    printf("Resultado: %d \n", resultado);




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
    else
        if(media <70)
        printf("\n reprovado");



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
    else
        if(volume <1000){
    printf("\n insuficiente");
    }


    return 0;




}