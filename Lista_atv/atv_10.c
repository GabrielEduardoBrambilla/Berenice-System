#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
// Atividade 10
    int num_a, num_b;
    float result;
    char num_operation;

    printf("Digite dois numeros:\n");
    scanf("%d", &num_a);
    getchar();
    scanf("%d", &num_b);

    printf("Digite qual operação deseja fazer:\n  m para multiplicação\n        d para divisão\n        a para adição\n        s para subtração\n");
    scanf("%d", &num_operation);

    switch(num_operation){
    case 'm':
        result = num_a * num_b;
        break;
    case 'd':
        result = num_a / num_b; 
        break;
    case 'a':
        result = num_a + num_b;
        break;
    case 's':
        result = num_a - num_b;
        break;
    default:
        printf("Operação inválida.\n");
        result = 0; 
        break;
    }
    printf('O resultado e %f', &result);

    return 0;
}
