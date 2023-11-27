#include "Header.h"

void salvarArquivoBN(Item tabela[])
{
  FILE *file = fopen("produto.bin", "wb");

  if (file == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }
  else
  {
    // printf("\nCriou arquivo\n");
  }
  fwrite(&contador, sizeof(int), 1, file);

  for (int i = 0; i < contador; i++)
  {
    fwrite(&tabela[i].codigo, sizeof(int), 1, file);
    fwrite(&tabela[i].nome, sizeof(char), 50, file);
    fwrite(&tabela[i].valor, sizeof(float), 1, file);
    fwrite(&tabela[i].quantidade, sizeof(int), 1, file);
    fwrite(&tabela[i].quant_vend, sizeof(int), 1, file);
  }

  fclose(file);
}

void lerprodutos(Item *tabela)
{
  FILE *file = fopen("produto.bin", "rb");

  if (file == NULL)
  {
    printf("\nArquivo de produto não encontrado.\n");
    return;
  }
  else
  {
    // printf("\nLeu o arquivo\n");
  }

  fread(&contador, sizeof(int), 1, file);

  tabela = (Item *)malloc(contador * sizeof(Item));

  for (int i = 0; i < contador; i++)
  {
    fread(&tabela[i].codigo, sizeof(int), 1, file);
    fread(&tabela[i].nome, sizeof(char), 50, file);
    fread(&tabela[i].valor, sizeof(float), 1, file);
    fread(&tabela[i].quantidade, sizeof(int), 1, file);
    fread(&tabela[i].quant_vend, sizeof(int), 1, file);
  }
  visualizarEstoque(tabela);

  fclose(file);
}

void salvarArquivoTXT(Item tabela[], int contador)
{
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  char filename[22];

  sprintf(filename, "%d-%02d-%02d_%02d-%02d-%02d.txt",
          tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
          tm.tm_hour, tm.tm_min, tm.tm_sec);

  FILE *file = fopen(filename, "w");

  if (file == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }
  else
  {
    printf("\nCriou arquivo\n");
  }
  fprintf(file, "%d\n", contador);

  for (int i = 0; i < contador; i++)
  {
    fprintf(file, "%d\n", tabela[i].codigo);
    fprintf(file, "%s\n", tabela[i].nome);
    fprintf(file, "%f\n", tabela[i].valor);
    // quantidade vendida no carrinho
    fprintf(file, "%d\n", tabela[i].quantidade);
  }

  fclose(file);
}

void salvarArquivoCSV(Item *tabela, int contador)
{
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  char filename[22];

  FILE *file = fopen("tabela.csv", "w");

  if (file == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  fprintf(file, "Código, Nome, Valor, Quantidade\n");

  for (int i = 0; i < contador; i++)
  {
    fprintf(file, "%d, %s, %.2f, %d\n", tabela[i].codigo, tabela[i].nome, tabela[i].valor, tabela[i].quantidade);
  }

  fclose(file);
}
void lerArquivoCSV(Item **tabela, int *contador)
{
  int counter = 0;
  FILE *file = fopen("tabela.csv", "r");
  if (file == NULL)
  {
    printf("\nArquivo de produto não encontrado.\n");
    return;
  }

  char ch;
  // feof = Find end of File
  // Ele continua ate o final do arquivo
  while (!feof(file))
  {
    ch = fgetc(file);
    if (ch == '\n')
    {
      (counter)++;
    }
  }
  rewind(file); // Retorna ao início do arquivo

  *tabela = (Item *)malloc((counter) * sizeof(Item));

  // Ignora a primeira linha, que contém os cabeçalhos
  char buffer[1024];
  fgets(buffer, 1024, file);

  for (int i = 0; i < counter; i++)
  {
    fscanf(file, "%d, %25[^,], %f, %d\n", &(*tabela)[i].codigo, (*tabela)[i].nome, &(*tabela)[i].valor, &(*tabela)[i].quantidade);
  }

  fclose(file);
}

void salvarArquivoHTML(Item *tabela)
{
  FILE *file = fopen("estoque.html", "w");
  sortQntVenda(tabela, contador);
  if (file == NULL)
  {
    printf("Erro ao criar o arquivo.\n");
    return;
  }
  else
  {
    fprintf(file, "<!DOCTYPE html>\n");
    fprintf(file, "<html>\n");
    fprintf(file, "<head>\n");
    fprintf(file, "<title>Produto</title>\n");
    fprintf(file, "<style>\n");
    fprintf(file, "html, body {\n");
    fprintf(file, "    height: 100vh;\n");
    fprintf(file, "    margin: 0;\n");
    fprintf(file, "    display: flex;\n");
    fprintf(file, "    justify-content: center;\n");
    fprintf(file, "    align-items: center;\n");
    fprintf(file, "}\n");
    fprintf(file, "table {\n");
    fprintf(file, "    border-collapse: collapse;\n");
    fprintf(file, "    border: 2px solid #ddd;\n");
    fprintf(file, "}\n");
    fprintf(file, "th, td {\n");
    fprintf(file, "    padding: 8px;\n");
    fprintf(file, "    border: 1px solid #ddd;\n");
    fprintf(file, "    text-align: center;\n"); // Center align content
    fprintf(file, "}\n");
    fprintf(file, "thead tr {\n");
    fprintf(file, "    background-color: #f2f2f2;\n");
    fprintf(file, "}\n");
    fprintf(file, "</style>\n");
    fprintf(file, "</head>\n");
    fprintf(file, "<body>\n");
    fprintf(file, "<table>\n");
    fprintf(file, "<thead>\n");
    fprintf(file, "<tr>\n");
    fprintf(file, "<th>Código</th>\n");
    fprintf(file, "<th>Nome</th>\n");
    fprintf(file, "<th>Valor</th>\n");
    fprintf(file, "<th>Quantidade</th>\n");
    fprintf(file, "<th>Quantidade Vendida</th>\n");
    fprintf(file, "</tr>\n");
    fprintf(file, "</thead>\n");
    fprintf(file, "<tbody>\n");
    for (int i = 0; i < contador; i++)
    {
      fprintf(file, "<tr>\n");
      fprintf(file, "<td>%d</td>\n", tabela[i].codigo);
      fprintf(file, "<td>%s</td>\n", tabela[i].nome);
      fprintf(file, "<td>%.2f</td>\n", tabela[i].valor);
      fprintf(file, "<td>%d</td>\n", tabela[i].quantidade);
      fprintf(file, "<td>%d</td>\n", tabela[i].quant_vend);
      fprintf(file, "</tr>\n");
    }
    fprintf(file, "</tbody>\n");
    fprintf(file, "</table>\n");
    fprintf(file, "</body>\n");
    fprintf(file, "</html>\n");
    sortCode(tabela, contador);
    fclose(file);
  }
}

