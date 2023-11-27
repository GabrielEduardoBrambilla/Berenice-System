#include <stdio.h>
#include <stdlib.h>

void initializeDefaultItems(Item *tabela);

void inputNum(int *var);
void inputFloat(float *var);
void inputNumRange(int *var, int minRange, int maxRange);
void inputString(char *str);

void produtos(Item tabela[]);
void visualizarEstoque(Item tabela[]);
void visualizarComanda(Item tabela[], int counter);
void cadastroitem(Item tabela[]);
int validador(int cod, Item tabela[]);
void atualziarProd(Item tabela[]);
void excluirproduto(Item tabela[]);
void salvarArquivoBN(Item tabela[]);
void lerprodutos(Item *tabela);
void menuVendas(Item tabela[]);
void realizarVenda(Item tabela[]);
void salvarArquivoTXT(Item tabela[], int contador);
void relatorioVendas(Item tabela[]);

void salvarArquivoCSV(Item *tabela, int contador);
void lerArquivoCSV(Item **tabela, int *contador);
void sortQntVenda(Item *tabela, int size_tabela);
void sortCode(Item *tabela, int size_tabela);
void salvarArquivoHTML(Item *tabela);
