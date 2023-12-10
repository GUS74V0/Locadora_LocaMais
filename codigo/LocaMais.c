/**
 * @file   main.c
 * @brief  Codigo para o Trabalho interdiciplinar de AEDS I/FES, sobre uma locadore de veiculos
 * @author Gustavo Rodrigo - Pedro Braga - Gabriel da Silveira
 * @date   inicio 2023-12-07 | fim 2023-12-10
 */
#include "structure.h"










int main()
{
    setlocale(LC_ALL, "Portuguese");

    int opcao;

    do
    {
        printf("\n--- LocaMais ---\n");
        printf("1. Cadastrar Cliente\n");
        printf("2. Cadastrar Veículo\n");
        printf("3. Cadastrar Locação\n");
        printf("4. Dar Baixa em Locação\n");
        printf("5. Calcular Valor Total da Locação\n");
        printf("6. Pesquisar Cliente\n");
        printf("7. Pesquisar Veículo\n");
        printf("8. Exibir Locações de Cliente\n");
        printf("9. Calcular Pontos de Fidelidade\n");
        printf("10. Exibir Relatório de Veículos Disponíveis\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrarCliente();
            break;
        case 2:
            cadastrarVeiculo();
            break;
        case 3:
            cadastrarLocacao();
            break;
        case 4:
            darBaixaLocacao();
            break;
        case 5:
            calcularValorTotal();
            break;
        case 6:
            pesquisarCliente();
            break;
        case 7:
            pesquisarVeiculo();
            break;
        case 8:
            exibirLocacoesCliente();
            break;
        case 9:
            calcularPontosFidelidade();
            break;
        case 10:
            relatorioVeiculosDisponiveis();
            break;
        case 0:
            printf("Saindo do sistema...\n");
            break;
        default:
            printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}