#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int App();
void visualizarEstoque(int estoque[]);

int main()
{

    App();

    return 0;
}

int App()
{
    int opcao, quant_upt;
    int estoque[5] = {0};
    int venda[5] = {0};
    int item_code;
    int has_estoque = 0, item_counter;
    int keep_sell;
    int id_item, qnt_item, qnt_parcela, porcentagem_desc, porcent_juros;
    char opc_pagamento;

    float valor_item, venda_total, venda_total_juros, pagamento_recebido, valor_parcela, troco;

    int soldItem[item_counter];
    int soldQuantity[item_counter];
    float subTotalItem[item_counter];

    do
    {
        printf("Menu:\n");
        printf("1 - Cadastrar estoque\n");
        printf("2 - Visualizar estoque\n");
        printf("3 - Realizar venda\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            // Cadastrar estoque()
            do
            {

                printf("Código   Item\n");
                printf("1        Pão de Forma\n");
                printf("2        Pão de Centeio\n");
                printf("3        Broa de Milho\n");
                printf("4        Sonho\n");
                printf("5        Tubaína\n");
                printf("Selecione o item que deseja atualizar o estoque\n");
                scanf(" %i", &item_code);
                if (item_code < 1 && item_code > 5)
                {
                    system("cls");
                    printf("Código inválido\n");
                }
            } while (item_code < 1 && item_code > 5);
            do
            {
                system("cls");
                printf("Digite quantas unidades à em estoque deste item\n");
                scanf(" %i", &quant_upt);

                if (quant_upt < 0)
                {
                    system("cls");
                    printf("“Quantidade inválida, a mesma deve ser maior ou igual a zero\n");
                }
            } while (quant_upt < 1);

            estoque[item_code - 1] = quant_upt;

            break;

        case 2:
            system("cls");
            visualizarEstoque(estoque);

            break;
        case 3:
            do
            {
                // realizarVenda();
                system("cls");
                visualizarEstoque(estoque);

                // Seleciona um item valido
                do
                {
                    printf("Digite qual item deseja vender\n");
                    scanf(" %i", &item_code);
                    if (item_code < 1 && item_code > 5)
                    {
                        system("cls");
                        printf("Código invalido\n");
                        visualizarEstoque(estoque);
                    }
                    else
                    {
                        has_estoque = (estoque[item_code - 1] > 0) ? 1 : 0;
                        printf("Quantidade inválida ou insuficiente\n");
                    }

                } while (item_code < 1 && item_code > 5 && has_estoque == 1);
                do
                {
                    printf("Quantos itens deseja comprar\n");
                    scanf("%d", &qnt_item);

                    if (qnt_item < 0)
                    {
                        system("cls");
                        printf("Quantidade invalida, digite novamente\n");
                    }
                    else
                    {
                        if ((estoque[item_code - 1] -= qnt_item) < 0)
                        {
                            printf("Estoque insuficiente, digite novamente\n");
                        }
                    }
                } while (qnt_item < 0);

                item_counter++;
                estoque[item_code - 1] -= qnt_item;
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
                }
                double subtotal = valor_item * quant_upt;

                soldItem[item_counter] = item_code;
                soldQuantity[item_counter] = qnt_item;
                subTotalItem[item_counter] = subtotal;

                venda_total += valor_item * qnt_item;

                printf("Deseja vender outro produto?\n");
                printf("1 - sim\n");
                printf("2 - não\n");
                scanf(" %d", &keep_sell);

                if (keep_sell == 2)
                {

                    printf("Item Nome do Item        Valor Unit. (R$) Quant. Sub-Total (R$)\n");
                    printf("1    Pão de Centeio       8.69         5     43.45\n");
                    printf("2    Pão de Centeio       8.69         2     17.38\n");
                    printf("3    Broa de Milho        5.00         2     10.00\n");
                    printf("4    Sonho                4.50         1     4.50\n");
                }
                printf("Total                      75.33\n");
            } while (keep_sell == 1);
            break;
        case 4:
            system("cls");
            printf("Fechando programa\n");
            opcao = 4;
            break;
        default:
            system("cls");
            printf("Opção inválida. Tente novamente.\n");
            break;
        }
    } while (opcao != 4);
}
void visualizarEstoque(int estoque[])
{
    printf("Item (código) Nome do Item       Valor (Unidade) Estoque\n");
    printf("1           Pão de Forma       R$ 7.50          %d\n", estoque[0]);
    printf("2           Pão de Centeio     R$ 8.69          %d\n", estoque[1]);
    printf("3           Broa de Milho      R$ 5.00          %d\n", estoque[2]);
    printf("4           Sonho              R$ 4.50          %d\n", estoque[3]);
    printf("5           Tubaína            R$ 3.25          %d\n", estoque[4]);
}