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
int contador=0;
/// prototipo funcao
void cadastrocontato ();
void imprimitudo ();
int busca (int numero);
void salvaArquivo();
void learquivo();

/* p = (agenda *)malloc (contador*sizeof (agenda));
 contador  = 30;
 p  = (int *)malloc (contador*sizeof (int));
 p[30]={0};
   p  = (int *)malloc (40*sizeof (int));
 p[40]={0};
 */


int main()
{
    int opc,verificar, indice;


    while (1)
    {
        printf("\n 1 - cadastro contato\n");
        printf("\n 2 - ver todos\n");
        printf("\n 3 - buscar\n");
         printf("\n 4 - salvar arquivo texto\n");
         printf("\n 5 - LER arquivo texto\n");
        scanf ("%d",&opc);
        getchar();
        switch (opc)
        {
        case 1:
            cadastrocontato();
            break;

        case 2:
            imprimitudo ();
            break;

        case 3:
            printf ("\n Qual numero vai buscar");
            scanf ("%d",&verificar);
            getchar();
            indice = busca (verificar);
                if (indice == -1){
                    printf ("\n contato nao tem");
                }else{
                printf ("\n\n nome %s  numero %d", p[indice].nome, p[indice].telefone);
                }


            break;

        case 4:
            salvaArquivo();
            break;
        case 5:
            learquivo();
        break;
        }
    }

    return 0;
}

void cadastrocontato ()
{

    if (contador == 0)
    {


    }
    else
    {

        p = (agenda *)malloc(contador+1*sizeof(agenda));
        p = (agenda *)realloc(p,((contador+1)*sizeof(agenda)));

    }
    printf (" \n o nome ");
    gets (p[contador].nome);
    fflush(stdin);
    printf ("\n numero ");
    scanf ("%d",&p[contador].telefone);
    getchar();
    printf ("\n nome %s numero %d",p[contador].nome, p[contador].telefone);
    contador++;
    return;
}


void imprimitudo ()
{

    for (int i =0; i<contador; i++)
    {
        printf ("\n nome %s numero %d",p[i].nome, p[i].telefone);

    }

}


int busca (int numero)
{
        for (int i=0; i<contador; i++)
        {
            if (numero == p[i].telefone)
            {
                return i;
            }
        }
    return -1;

}


void salvaArquivo(){

    FILE *pont_texto = fopen ("agenda.txt","w");

    if (pont_texto == NULL){
        printf ("\n deu ruim no arquivo");
        return;
    } else {
        printf ("\n criou ou maio o arquivo");
    }
    fprintf (pont_texto,"%d",contador);
    for (int i=0; i<contador; i++){
        fprintf (pont_texto,"\n%s\n%d",p[i].nome,p[i].telefone);
    }

    fclose (pont_texto);

}

void learquivo(){

FILE *pont_texto = fopen ("agenda.txt","r");

    if (pont_texto == NULL){
        printf ("\n deu ruim no arquivo");
        return;
    } else {
        printf ("\n LEU o arquivo");
    }
    fscanf (pont_texto,"%d\n",&contador); //FALTA VERIF.
    p = (agenda *)malloc(contador*sizeof(agenda));
    for (int i=0;i<contador;i++){
          fscanf (pont_texto,"\n%s\n%d",p[i].nome,&p[i].telefone);
    }
     fclose (pont_texto);

}