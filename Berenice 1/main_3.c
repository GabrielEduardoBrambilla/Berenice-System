#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{

int id_item, qnt_item, qnt_parcela, porcentagem_desc, porcent_juros;
char opc_pagamento;
float valor_item, venda_total, venda_total_juros, pagamento_recebido, valor_parcela, troco;

printf("Item (codigo) Nome do Item       Valor (Unidade)\n");
printf("1             Pão de Forma       R$ 7,50\n");
printf("2             Pão de Centeio     R$ 8,69\n");
printf("3             Broa de Milho      R$ 5,00\n");
printf("4             Sonho              R$ 4,50\n");
printf("5             Tubaina            R$ 3,25\n");

printf("Digite o id do item que deseja comprar\n");
scanf("%d", &id_item);

// Verifica se o id_item inserido está dentro do intervalo válido
// Não tem default por causa do if antes do case, nos verificamos já, ent não tem como nao ser um dos cases
if (id_item >= 1 && id_item <= 5)
{
    // Atribui o valor apropriado para valor_item com base no id_item selecionado
    switch (id_item)
    {
        case 1:

            valor_item = 7.50;
            break;

        case 2:

            valor_item = 8.69;
            break;

        case 3:

            valor_item = 5;
            break;

        case 4:

            valor_item = 4.50;
            break;

        case 5:

            valor_item = 3.25;
            break;
        // Não tem default por causa do if antes do case, nos verificamos já, ent não tem como nao ser um dos cases
    }
    printf("Quantos itens deseja comprar\n");
    scanf("%d", &qnt_item);

    // Verifica se a quantidade de itens inserida é válida (maior que 0)
    if (qnt_item > 0)
        {
          // calcula o valor total da venda 
            venda_total = qnt_item * valor_item;

            printf("Deseja pagar a vista ou a prazo digite:\n");
            printf("Total da venda: RS %f\n", venda_total);

            printf("A - para avista\n");
            printf("P - para a prazo\n");
            scanf(" %c", &opc_pagamento);

            // Verifica a opção de pagamento selecionada (A/a para à vista, P/p para a prazo)
            if (opc_pagamento == 'A' || opc_pagamento == 'a' || opc_pagamento == 'P' || opc_pagamento == 'p')
            {
                // Verifica se a opção de pagamento selecionada foi A ou a
                if (opc_pagamento == 'A' || opc_pagamento == 'a')
                {
                    printf("\nPagamento avista selecionado\n");
                    // Verifica se o total da venda é menor ou igual a 50
                    if (venda_total <= 50)
                    {
                        // Desconto de 5%
                        venda_total = venda_total - (venda_total * 0.05);
                        porcentagem_desc = 5;
                    }
                    // Verifica se o total da venda é maior a 50 e ao mesmo tempo menor que 100
                    else if (venda_total > 50 && venda_total < 100)
                    {
                        // Desconto de 10%
                        venda_total = venda_total - (venda_total * 0.1);
                        porcentagem_desc = 10;
                    }
                    // Verifica se o total da venda é maior ou igual a 100
                    else if (venda_total >= 100)
                    {
                        // Desconto de 18%
                        venda_total = venda_total - (venda_total * 0.18);
                        porcentagem_desc = 18;
                    }
                    printf("Digite o valor recebido para calcular o troco\n");
                    printf("Desconto de %d%% aplicado a compra\n", porcentagem_desc);
                    printf("Total com desconto: RS %f\n", venda_total);
                    scanf("%f", &pagamento_recebido);

                    // Verifica se o pagamento recebido é invalido, sendo igual a 0 ou menor que 0
                    if (pagamento_recebido == 0 || pagamento_recebido < 0)
                    {
                        printf("Falta receber: RS%f\n", venda_total);
                    }
                    // Verifica se o pagamento recebido é menor que o preco da venda a ser cobrada, e ao mesmo tempo se o pagamento é diferente de 0
                    else if (pagamento_recebido < venda_total && pagamento_recebido != 0)
                    {
                        troco = venda_total - pagamento_recebido;
                        printf("Falta receber: RS%f\n", troco);
                    }
                    // Se a verificação do if de cima for falso executa esse else
                    else
                    {
                        troco = venda_total - pagamento_recebido;
                        troco = troco * -1;
                        printf("O troco e %f\n", troco);
                    }
                }
                else
                {
                    printf("Digite a quantidade de vezes que deseja parcelar\n");
                    scanf("%d", &qnt_parcela);
                    // Verifica se a quantidade de parcelas é valido sendo maior que 0 
                    if (qnt_parcela > 0)
                    {
                      // Verifica se a quantidade de parcelas é está entre 3 e 1. E calcula os valores de acordo 
                      if (qnt_parcela <= 3 && qnt_parcela >= 1)
                      {
                          venda_total_juros = venda_total + (venda_total * 0.05);
                          porcent_juros = 5;
                          valor_parcela = venda_total_juros / qnt_parcela;
                      }
                      // Verifica se a quantidade de parcelas é maior que 3 e calcula os valores de acordo 
                      else if (qnt_parcela > 3)
                      {
                          venda_total_juros = venda_total + (venda_total * 0.08);
                          porcent_juros = 8;
                          valor_parcela = venda_total_juros / qnt_parcela;
                      }
                      printf("\nJuros Simples: %d%%\n", porcent_juros);
                      printf("Parcelado em: %dX\n", qnt_parcela);
                      printf("Total: RS%f\n", venda_total);
                      printf("Total com juros: RS%f\n", venda_total_juros);
                      printf("Valor da parcela: RS%f\n", valor_parcela);
                    }else{
                        printf("Quantidade de parcelas invalida \nA receber: RS%f\n", venda_total);
                    }
                }
            }
            else
            {
                // Trata uma opção de pagamento inválida e fornece uma mensagem alternativa
                printf("Opçao invalida\n");
                printf("Pague a Berenice: RS%f\n", venda_total);
            }
        }
        else
        {
            // Trata uma quantidade de itens inválida, adicionando 10 itens e informando o usuário
            printf("Quantidade invalida\n");
        }
 }

  else
  {
      // Trata um id_item inválido atribuindo um valor padrão e informando o usuário
      printf("Id digitado invalido\n");
  }

    return 0;
}