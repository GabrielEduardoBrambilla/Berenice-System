#include <stdio.h>

int main() {
    float num_1, num_2, result;
    char operation;

    do {
        printf("Operação: ");
        scanf(" %c", &operation);
        getchar();
        
        if(operation !='='){
          printf("Numero 1: ");
          scanf(" %f", &num_1);
          printf("\nNumero 2: ");
          scanf(" %f", &num_2);
        }

        switch (operation) {
            case '+':
                result = num_1 + num_2;
                printf("%f\n", result);
                break;
            case '-':
                result = num_1 - num_2;
                printf("%f\n", result);
                break;
            case '*':
                result = num_1 * num_2;
                printf("%f\n", result);
                break;
            case '/':
                result = num_1 / num_2;
                printf("%f\n", result);
                break;
        }
    } while (operation != '=');

    return 0;
}
