#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "structure.h"

void cadastrarCliente();
void cadastrarVeiculo();
void cadastrarLocacao();
void darBaixaLocacao();
void calcularValorTotal();
void pesquisarCliente();
void pesquisarVeiculo();
void exibirLocacoesCliente();
void calcularPontosFidelidade();
void relatorioVeiculosDisponiveis();

void cadastrarCliente()
{
    Cliente cliente;
    Cliente clienteAux;
    int existeCliente = 0;
    FILE *arquivo;

    arquivo = fopen("clientes.bin", "ab+"); // Corrigido para ab+

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("Digite o código do cliente: ");
    scanf("%d", &cliente.codigo);

    while (fread(&clienteAux, sizeof(Cliente), 1, arquivo))
    {
        if (clienteAux.codigo == cliente.codigo)
        {
            existeCliente = 1;
            printf("Cliente com este código já existe.\n");
            break;
        }
    }

    if (!existeCliente)
    {
        printf("Nome do cliente: ");
        scanf("%s", cliente.nome);
        printf("Endereço: ");
        scanf("%s", cliente.endereco);
        printf("Telefone: ");
        scanf("%s", cliente.telefone);

        fwrite(&cliente, sizeof(Cliente), 1, arquivo);
    }

    fclose(arquivo); // Fecha o arquivo
}

void pesquisarCliente()
{
    int codigoCliente;
    Cliente cliente;
    int encontrado = 0;
    FILE *arquivo = fopen("clientes.bin", "rb");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("Digite o código do cliente: ");
    scanf("%d", &codigoCliente);

    while (fread(&cliente, sizeof(Cliente), 1, arquivo))
    {
        if (cliente.codigo == codigoCliente)
        {
            encontrado = 1;
            printf("Código: %d\nNome: %s\nEndereço: %s\nTelefone: %s\n",
                   cliente.codigo, cliente.nome, cliente.endereco, cliente.telefone);
            break;
        }
    }

    fclose(arquivo);

    if (!encontrado)
    {
        printf("Cliente não encontrado.\n");
    }
}

void exibirLocacoesCliente()
{
    int codigoCliente;
    Locacao locacao;
    int encontrouLocacao = 0;
    FILE *arquivo = fopen("locacoes.bin", "rb");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("Digite o código do cliente: ");
    scanf("%d", &codigoCliente);

    while (fread(&locacao, sizeof(Locacao), 1, arquivo))
    {
        if (locacao.codigoCliente == codigoCliente)
        {
            encontrouLocacao = 1;
            printf("Código Locação: %d\nCódigo Veículo: %d\nData Retirada: %s\nData Devolução: %s\n",
                   locacao.codigo, locacao.codigoVeiculo, locacao.dataRetirada, locacao.dataDevolucao);
        }
    }

    fclose(arquivo);

    if (!encontrouLocacao)
    {
        printf("Não foram encontradas locações para este cliente.\n");
    }
}

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
