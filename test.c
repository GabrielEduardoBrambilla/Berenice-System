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

p = (agenda *)malloc(contador+1*sizeof(agenda));
p = (agenda *)realloc(p,((contador+1)*sizeof(agenda)));


int main(){
  FILE *arq = fopen("arquivos.txt", "w");

    if (arq == NULL){
        printf ("\n deu ruim no arquivo");
        return;
    } else {
        printf ("\n criou ou maio o arquivo");
    }
  fprintf(arq, "11");
  fclose(arq);

  printf("\nLeitura de arq agora\n");
   
  FILE *arqr = fopen("arquivos.txt", "r");
  int value;
  
  if (arqr == NULL){
      printf ("\n deu ruim no arquivo");
      return;
  } else {
      printf ("\n abriu o arquivo");
  }

  fscanf(arqr, "%d", &value); //FALTA VERIF.
  printf("\n%d", value);
  
  fclose(arqr);

  return 0;

}
