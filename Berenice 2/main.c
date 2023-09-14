#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int App();
void visualizarEstoque(int estoque_quants[], double estoque_preco[]);
void realizarVenda(int estoque_quants[], double estoque_preco[]);

int main()
{

    App();

    return 0;
}

int App()
{
    int opcao, quant_upt;

    int estoque_quants[5] = {10};
    char estoque_item_name[5][20] = {"Pão de Forma", "Pão de Centeio", "Broa de Milho", "Sonho", "Tubaína"};
    double estoque_preco[5] = {7.50, 8.69, 5, 4.50, 3.25};
    int has_estoque = 0, item_counter;

    int keep_sell;
    int id_item, qnt_item, qnt_parcela, porcentagem_desc, porcent_juros;
    char opc_pagamento;
    double subtotal;

    float valor_item, venda_total, venda_total_juros, pagamento_recebido, valor_parcela, troco;

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
            cadastrarEstoque(estoque_quants);
            break;

        case 2:
            system("cls");
            visualizarEstoque(estoque_quants, estoque_preco);

            break;
        case 3:

            realizarVenda(estoque_quants, estoque_preco);
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

void realizarVenda(int estoque_quants[], double estoque_preco[])
{
    int item_code, has_estoque, qnt_item, valor_item, quant_upt, subtotal, venda_total, keep_sell;

    int venda_item[1000];
    int venda_quantidade[1000];
    float subtotal_item[1000];
    int venda[5] = {0};

    do
    {
        // Seleciona um item valido
        do
        {
            visualizarEstoque(estoque_quants, estoque_preco);
            printf("Digite qual item deseja vender\n");
            scanf(" %i", &item_code);
            if (item_code < 1 || item_code > 5)
            {
                system("cls");
                printf("Código invalido\n");
                has_estoque = 0;
            }
            else
            {
                has_estoque = (estoque_quants[item_code - 1] <= 0) ? 0 : 1;
                if (has_estoque == 0)
                {
                    system("cls");
                    printf("Item sem estoque. Selecione outro item\n");
                    // Fazer If se nenhum item possuir estoque redirecionar para o menu principal
                }
            }

        } while ((item_code < 1 || item_code > 5) || (has_estoque == 0));
        // Seleciona uma quantidade valida
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
                if ((estoque_quants[item_code - 1] -= qnt_item) < 0)
                {
                    printf("Estoque insuficiente, digite novamente\n");
                    qnt_item = -1;
                }
            }
        } while (qnt_item < 0);

        estoque_quants[item_code - 1] -= qnt_item;

        valor_item = estoque_preco[item_code - 1];
        subtotal = valor_item * quant_upt;

        venda_item[item_code - 1] = item_code;
        venda_item[item_code - 1] = qnt_item;
        subtotal_item[item_code - 1] = subtotal;

        venda_total += valor_item * qnt_item;
        do
        {
            printf("Deseja vender outro produto?\n");
            printf("1 - sim\n");
            printf("2 - não\n");
            scanf(" %d", &keep_sell);
        } while (keep_sell < 1 || keep_sell > 2);

        if (keep_sell == 2)
        {

            printf("Item Nome do Item        Valor Unit. (R$) Quant. Sub-Total (R$)\n");

            printf("1    Pão de Centeio       8.69         5     43.45\n");
            printf("2    Pão de Centeio       8.69         2     17.38\n");
            printf("3    Broa de Milho        5.00         2     10.00\n");
            printf("4    Sonho                4.50         1     4.50\n");
            printf("Total                      75.33\n");
        }
    } while (keep_sell == 1);
}
void cadastrarEstoque(int estoque_quants[])
{
    int item_code = 0;
    int quant_upt = 0;

    do
    {

        printf("Código   Item\n");
        printf("1        Pão de Forma\n");
        printf("2        Pão de Centeio\n");
        printf("3        Broa de Milho\n");
        printf("4        Sonho\n");
        printf("5        Tubaína\n");
        printf("Selecione o item que deseja atualizar o estoque\n");
        scanf(" %d", &item_code);
        if (item_code < 1 || item_code > 5)
        {
            system("cls");
            printf("Código inválido\n");
        }
    } while (item_code < 1 || item_code > 5);
    do
    {
        printf("Digite quantas unidades à em estoque deste item\n");
        scanf(" %d", &quant_upt);

        if (quant_upt < 0)
        {
            system("cls");
            printf("Quantidade inválida, a mesma deve ser maior ou igual a zero\n");
        }
    } while (quant_upt < 1);

    estoque_quants[item_code - 1] = quant_upt;
}

void visualizarEstoque(int estoque_quants[], double estoque_preco[])
{
    printf("Item (código) Nome do Item       Valor (Unidade) Estoque\n");
    printf("1           Pão de Forma       R$ %.2f          %d\n", estoque_preco[0], estoque_quants[0]);
    printf("2           Pão de Centeio     R$ %.2f          %d\n", estoque_preco[1], estoque_quants[1]);
    printf("3           Broa de Milho      R$ %.2f          %d\n", estoque_preco[2], estoque_quants[2]);
    printf("4           Sonho              R$ %.2f          %d\n", estoque_preco[3], estoque_quants[3]);
    printf("5           Tubaína            R$ %.2f          %d\n", estoque_preco[4], estoque_quants[4]);
}
