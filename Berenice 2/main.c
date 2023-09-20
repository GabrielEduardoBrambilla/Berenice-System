#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int estoque_quants[5] = {0, 0, 0, 0, 0};
int vendas_totais[5] = {0, 0, 0, 0, 0};

int main()
{
    char estoque_item_name[5][50] = {"Pão de Forma", "Pão de Centeio", "Broa de Milho", "Sonho        ", "Tubaína      "};
    int opcao, quant_upt, actionCode, keep_sell, venda_quantidade[5] = {0, 0, 0, 0, 0};
    float estoque_preco[5] = {7.50, 8.69, 5, 4.50, 3.25};

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
            visualizarEstoque(estoque_quants, estoque_preco, estoque_item_name);

            break;
        case 3:
            realizarVenda(estoque_quants, estoque_preco, estoque_item_name, vendas_totais);
            break;
        case 4:
            system("cls");
            relatorioVendas(vendas_totais, venda_quantidade, estoque_item_name, 1);

            printf("Fechando programa\n");
            opcao = 4;
            break;
        default:
            system("cls");
            printf("Opção inválida. Tente novamente.\n");
            break;
        }
    } while (opcao != 4);
    return 0;
}

void realizarVenda(int estoque_quants[], float estoque_preco[], char estoque_item_name[][50], int vendas_totais[])
{
    int item_code, has_estoque = 0, qnt_item, quant_upt, keep_sell, id_item, qnt_parcela, porcentagem_desc, porcent_juros, opc_pagamento, verification, i, actionCode = 0, estoque_verificacao = 0, venda_quantidade[5] = {0, 0, 0, 0, 0};
    float valor_item, venda_total, venda_total_juros, pagamento_recebido, valor_parcela, troco, max, subtotal, subtotal_item[5] = {0, 0, 0, 0, 0};
    do
    {
        // Seleciona um item valido
        i = 0;
        for (i = 0; i < 5; i++)
        {
            if (estoque_quants[i] <= 0)
            {
                estoque_verificacao++;

                if (estoque_verificacao == 5)
                {
                    printf("Nenhum item possui estoque, cadastre o estoque antes de vender \n");
                    return 1;
                }
            }
        }
        do
        {
            visualizarEstoque(estoque_quants, estoque_preco, estoque_item_name);
            printf("Digite qual item deseja vender\n");
            scanf(" %d", &item_code);
            item_code--;
            if (item_code < 0 || item_code > 4)
            {
                system("cls");
                printf("Código invalido\n");
                has_estoque = 0;
            }
            else
            {
                if (estoque_quants[item_code] <= 0)
                {
                    has_estoque = 0;
                }
                else
                {
                    has_estoque = 1;
                }

                if (has_estoque == 0)
                {
                    system("cls");
                    printf("Item sem estoque. Selecione outro item\n");
                }
            }

        } while ((item_code < 0 || item_code > 4) || (has_estoque == 0));
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
                verification = estoque_quants[item_code] - qnt_item;
                if (verification < 0)
                {
                    printf("Estoque insuficiente, digite novamente\n");
                    qnt_item = 0;
                }
            }
        } while (qnt_item <= 0);

        estoque_quants[item_code] -= qnt_item;

        valor_item = estoque_preco[item_code];
        subtotal = valor_item * qnt_item;

        venda_quantidade[item_code] += qnt_item;

        subtotal_item[item_code] += subtotal;

        venda_total += subtotal;
        do
        {
            keep_sell = 0;
            printf("Deseja vender outro produto?\n");
            printf("1 - sim\n");
            printf("2 - não\n");
            scanf("%d", &keep_sell);

            if (keep_sell != 1 && keep_sell != 2)
            {
                keep_sell = 0;
            }
        } while (keep_sell == 0);

        if (keep_sell == 2)
        {
            system("cls");
            printf("Item (código)\tNome do Item\tValor (Unidade)\t Quant \tSub-Total\n");
            i = 0;
            for (i = 0; i < 5; i++)
            {
                if (venda_quantidade[i] > 0)
                {
                    printf("%d\t\t%s\t    R$ %.2f\t %d \tR$ %.2f\n", i + 1, estoque_item_name[i], estoque_preco[i], venda_quantidade[i], subtotal_item[i]);
                }
            }
            printf("\t\t\t\t\t\t Total\tR$ %.2f", venda_total);

            max = subtotal_item[0];
            i = 0;
            for (i = 0; i < 5; i++)
            {
                if (max < subtotal_item[i])
                {
                    max = subtotal_item[i];
                }
            }
            printf("\nO maior valor é: %.2f\n", max);

            printf("Deseja pagar a vista ou a prazo digite:\n");
            printf("Total da venda: RS %.2f\n", venda_total);
            relatorioVendas(vendas_totais, venda_quantidade, estoque_item_name, 0);
            do
            {

                printf("1 - para avista\n");
                printf("2 - para a prazo\n");
                scanf(" %d", &opc_pagamento);
                if (opc_pagamento != 1 && opc_pagamento != 2)
                {
                    printf("Opçao invalida\n");
                }

            } while (opc_pagamento != 1 && opc_pagamento != 2);

            // Verifica se a opção de pagamento selecionada foi A ou a
            if (opc_pagamento == 1)
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
                do
                {
                    printf("Digite o valor recebido para calcular o troco\n");
                    printf("Desconto de %d%% aplicado a compra\n", porcentagem_desc);
                    printf("Total com desconto: RS %.2f\n", venda_total);
                    scanf("%f", &pagamento_recebido);
                } while (pagamento_recebido < venda_total);

                // Verifica se o pagamento recebido é menor que o preco da venda a ser cobrada, e ao mesmo tempo se o pagamento é diferente de 0
                // Se a verificação do if de cima for falso executa esse else
                if (pagamento_recebido > venda_total)
                {
                    troco = venda_total - pagamento_recebido;
                    troco = troco * -1;
                    printf("O troco e %.2f\n", troco);
                }
                if (pagamento_recebido == venda_total)
                {
                    printf("Tudo certo sem necessidade de troco \n");
                }
            }
            else
            {
                do
                {
                    printf("Digite a quantidade de vezes que deseja parcelar\n");
                    scanf("%d", &qnt_parcela);
                    if (qnt_parcela > 0)
                    {
                        system('cls');
                        printf("Quantidade de parcelas invalida, digite novamente\n");
                    }
                } while (qnt_parcela > 0);
                // Verifica se a quantidade de parcelas é valido sendo maior que 0
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
                printf("Total: RS%.2f\n", venda_total);
                printf("Total com juros: RS%.2f\n", venda_total_juros);
                printf("Valor da parcela: RS%.2f\n", valor_parcela);
            }
        }
    } while (keep_sell != 2);
}

void cadastrarEstoque(int estoque_quants[])
{
    int quant_upt = 0, item_code = 0;

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

void visualizarEstoque(int estoque_quants[], float estoque_preco[], char estoque_item_name[][50])
{
    int i = 0;
    printf("Item (código)\tNome do Item\tValor (Unidade)\tEstoque\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d\t\t%s\t    R$ %.2f\t%d\n", i + 1, estoque_item_name[i], estoque_preco[i], estoque_quants[i]);
    }
}

void relatorioVendas(int vendas_totais[], int venda_quantidade[], char estoque_item_name[][50], int actionCode)
{
    int i = 0;

    if (actionCode == 0)
    {
        i = 0;
        for (i = 0; i < 5; i++)
        {
            vendas_totais[i] += venda_quantidade[i];
        }
    }
    else if (actionCode == 1)
    {
        system("cls");
        printf("Relatorio de fechamento de caixa:\n");
        printf("Item (código)\tNome do Item\t Quant\n");

        i = 0;
        for (i = 0; i < 5; i++)
        {
            if (vendas_totais[i] > 0)
            {
                printf("%d\t\t%s\t    %d \n", i + 1, estoque_item_name[i], vendas_totais[i]);
            }
        }
    }
}