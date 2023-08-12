#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{

    // Atividade 8
    int id_item, qnt_item, qnt_parcela;
    char opc_pagamento;
    float valor_item, venda_total, pagamento_recebido, valor_parcela, troco;

    printf("Item (código) Nome do Item       Valor (Unidade)\n");
    printf("1             Pão de Forma       R$ 7,50\n");
    printf("2             Pão de Centeio     R$ 8,69\n");
    printf("3             Broa de Milho      R$ 5,00\n");
    printf("4             Sonho              R$ 4,50\n");
    printf("5             Tubaína            R$ 3,25\n");
    printf("Digite o id do item que deseja comprar\n");
    scanf("%d", &id_item);
    if (id_item >= 1 && id_item <= 5)
    {
        if (id_item == 1)
        {
            valor_item = 7.50;
        }
        if (id_item == 2)
        {
            valor_item = 8.69;
        }
        if (id_item == 3)
        {
            valor_item = 5;
        }
        if (id_item == 4)
        {
            valor_item = 4.50;
        }
        if (id_item == 5)
        {
            valor_item = 3.25;
        }
    }
    else
    {
        printf("Id digitado invalido\n");
        printf("Sonho de ouro selecionado\n");
        valor_item = 100;
        printf("Valor: RS%f\n", valor_item);
    }

    printf("Quantos itens deseja comprar\n");
    scanf("%d", &qnt_item);
    if (qnt_item > 0)
    {
        venda_total = qnt_item * valor_item;
    }
    else
    {
        printf("Quantidade invalida, multa aplicada\n");
        printf("Dez itens adicionados a compra\n");
        // printf("Pressione Enter para continuar...\n");
        venda_total = 10 * valor_item;
    }

    printf("Deseja pagar a vista ou a prazo digite:\n");
    printf("A - para avista\n");
    printf("P - para a prazo\n");
    scanf(" %c", &opc_pagamento);
    if (opc_pagamento == 'A' || opc_pagamento == 'a' || opc_pagamento == 'P' || opc_pagamento == 'p')
    {
        if (opc_pagamento == 'A' || opc_pagamento == 'a')
        {
            printf("\nPagamento avista selecionado\n");
            if (venda_total <= 50)
            {
                // Desconto de 5%
                venda_total = venda_total - (venda_total * 0.05);
            }
            if (venda_total > 50 && venda_total < 100)
            {
                // Desconto de 10%
                venda_total = venda_total - (venda_total * 0.1);
            }
            if (venda_total >= 100)
            {
                // Desconto de 18%
                venda_total = venda_total - (venda_total * 0.18);
            }
            printf("Digite o valor recebido para calcular o troco\n");
            printf("Total da venda: RS %f\n", venda_total);
            scanf("%f", &pagamento_recebido);
            if (pagamento_recebido == 0 || pagamento_recebido < 0)
            {
                printf("Falta receber: RS%f\n", venda_total);
            }
            else if (pagamento_recebido < venda_total && pagamento_recebido != 0)
            {
                troco = venda_total - pagamento_recebido;

                printf("Falta receber: RS%f\n", troco);
            }
            else
            {
                troco = venda_total - pagamento_recebido;
                troco = troco * -1;
                printf("O troco é %f\n", troco);
            }
        }
        else
        {
            printf("Digite a quantidade de vezes que deseja parcelar\n");
            scanf("%d", &qnt_parcela);
            if (qnt_parcela == 0 || qnt_parcela < 0)
            {
                printf("Quantidade de parcelas invalida: \nA receber: RS%f\n", venda_total);
            }
            if (qnt_parcela <= 3 && qnt_parcela >= 1)
            {
                venda_total = venda_total + (venda_total * 0.05);
                valor_parcela = venda_total / qnt_parcela;
                system("cls");
                printf("Juros Simples: 5%%\n");
                printf("Parcelado em: X%d\n", qnt_parcela);
                printf("Total: RS%f\n", venda_total);
                printf("Valor da parcela: RS%f\n", valor_parcela);
            }
            if (qnt_parcela > 3)
            {
                venda_total = venda_total + (venda_total * 0.08);
                // divide o total da venda pela quantidade de parcelas para descobrir o quanto sera recebido por mes
                valor_parcela = venda_total / qnt_parcela;
                system("cls");
                printf("Juros Simples: 8%%\n");
                printf("Parcelado em: X%d\n", qnt_parcela);
                printf("Total: RS%f\n", venda_total);
                printf("Valor da parcela: RS%f\n", valor_parcela);
            }
        }
    }
    else
    {
        printf("Opção invalida\n");
        printf("Pague a Berenice: RS%f\n", venda_total);
    }

    return 0;
}
