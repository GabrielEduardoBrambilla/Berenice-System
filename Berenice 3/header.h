#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct
{
  int codigo;
  char nome[25];
  float valor;
  int quantidade;
  int quant_vend;
} Item;

int contador = 5;

int validador(int cod, Item *tabela);
void cadastroitem(Item *tabela);
void visualizarEstoque(Item *tabela);
void atualziarProd(Item *tabela);
void excluirproduto(Item *tabela);
void lerprodutos();
void salvarArquivoBN(Item *tabela);
void relatorioVendas(Item *tabela);
void menuVendas(Item *tabela);
void visualizarComanda(Item *tabela, int counter);
void salvarArquivoBN(Item *tabela);
void salvarArquivoTXT(Item *tabela, int contador);
void produtos(Item *tabela);
void realizarVenda(Item *tabela);
void sortQntVenda(Item *tabela, int size_tabela);
void sortCode(Item *tabela, int size_tabela);

// FUNÇÕES UTILITARIAS
void inputNum(int *var);
void inputFloat(float *var);
void inputNumRange(int *var, int minRange, int maxRange);
void inputString(char *str);
void initializeDefaultItems(Item *tabela);

#endif