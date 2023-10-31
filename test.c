#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[25];
    int telefone;
} agenda;

///Var global
agenda *p;


int main(){
  FILE *arq = fopen("arquivo.txt", "w");

    if (arq == NULL){
        printf ("\n deu ruim no arquivo");
        return;
    } else {
        printf ("\n criou ou maio o arquivo");
    }
  fprintf(arq, "Texto no arquivo\n");
  fclose(arq);
  printf("\nLeitura de arq agora\n")
   FILE *arqr = fopen("arquivo.txt", "r");

    if (arqr == NULL){
        printf ("\n deu ruim no arquivo");
        return;
    } else {
        printf ("\n abriu o arquivo");
    }
  
    fgets()
  return 0;

}
