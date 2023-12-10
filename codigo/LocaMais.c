/**
 * @file   main.c
 * @brief  Codigo para o Trabalho interdiciplinar de AEDS I/FES, sobre uma locadore de veiculos
 * @author Gustavo Rodrigo - Pedro Braga - Gabriel da Silveira
 * @date   2023-12-07
 */

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


void cadastrarLocacao()
{
    Locacao locacao;
    Veiculo veiculoAux;
    int veiculoDisponivel = 1;
    FILE *arquivoLocacao = fopen("locacoes.bin", "ab+");
    FILE *arquivoVeiculo = fopen("veiculos.bin", "rb+");

    if (arquivoLocacao == NULL || arquivoVeiculo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("Digite o código da locação: ");
    scanf("%d", &locacao.codigo);

    printf("Código do Cliente: ");
    scanf("%d", &locacao.codigoCliente);
    printf("Código do Veículo: ");
    scanf("%d", &locacao.codigoVeiculo);

    while (fread(&veiculoAux, sizeof(Veiculo), 1, arquivoVeiculo))
    {
        if (veiculoAux.codigo == locacao.codigoVeiculo && strcmp(veiculoAux.status, "alugado") == 0)
        {
            veiculoDisponivel = 0;
            printf("Veículo não disponível para locação.\n");
            break;
        }
    }

    if (veiculoDisponivel)
    {
        printf("Data de Retirada (dd/mm/aaaa): ");
        scanf("%s", locacao.dataRetirada);
        printf("Data de Devolução (dd/mm/aaaa): ");
        scanf("%s", locacao.dataDevolucao);
        printf("Seguro (0 para não, 1 para sim): ");
        scanf("%d", &locacao.seguro);
        printf("Quantidade de dias: ");
        scanf("%d", &locacao.qtdDias);

        fseek(arquivoVeiculo, 0, SEEK_SET);

        while (fread(&veiculoAux, sizeof(Veiculo), 1, arquivoVeiculo))
        {
            if (veiculoAux.codigo == locacao.codigoVeiculo)
            {
                strcpy(veiculoAux.status, "alugado");
                fseek(arquivoVeiculo, -sizeof(Veiculo), SEEK_CUR);
                fwrite(&veiculoAux, sizeof(Veiculo), 1, arquivoVeiculo);
                break;
            }
        }

        fwrite(&locacao, sizeof(Locacao), 1, arquivoLocacao);
    }

    fclose(arquivoLocacao);
    fclose(arquivoVeiculo);
}

void darBaixaLocacao()
{
    int codigoLocacao;
    Locacao locacao;
    FILE *arquivoLocacao = fopen("locacoes.bin", "rb+");
    FILE *arquivoVeiculo = fopen("veiculos.bin", "rb+");

    if (arquivoLocacao == NULL || arquivoVeiculo == NULL)
    {
        printf("Erro ao abrir os arquivos.\n");
        return;
    }

    printf("Digite o código da locação para dar baixa: ");
    scanf("%d", &codigoLocacao);

    while (fread(&locacao, sizeof(Locacao), 1, arquivoLocacao))
    {
        if (locacao.codigo == codigoLocacao)
        {
            fseek(arquivoVeiculo, 0, SEEK_SET);

            while (fread(&locacao, sizeof(Locacao), 1, arquivoLocacao))
            {
                if (locacao.codigoVeiculo == locacao.codigoVeiculo)
                {
                    fseek(arquivoVeiculo, 0, SEEK_SET);

                    // Utiliza uma variável Veiculo para armazenar informações do veículo
                    Veiculo veiculo;

                    // Busca o veículo associado à locação
                    while (fread(&veiculo, sizeof(Veiculo), 1, arquivoVeiculo))
                    {
                        if (veiculo.codigo == locacao.codigoVeiculo)
                        {
                            // Atualiza o status do veículo para "disponível"
                            strcpy(veiculo.status, "disponível");
                            fseek(arquivoVeiculo, -sizeof(Veiculo), SEEK_CUR);
                            fwrite(&veiculo, sizeof(Veiculo), 1, arquivoVeiculo);
                            break;
                        }
                    }

                    break;
                }
            }

            printf("Locação finalizada e veículo disponível novamente.\n");
            break;
        }
    }

    fclose(arquivoLocacao);
    fclose(arquivoVeiculo);
}

void calcularValorTotal()
{
    int codigoLocacao;
    Locacao locacao;
    float valorTotal = 0.0;
    int encontrouLocacao = 0;
    FILE *arquivo = fopen("locacoes.bin", "rb");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("Digite o código da locação: ");
    scanf("%d", &codigoLocacao);

    while (fread(&locacao, sizeof(Locacao), 1, arquivo))
    {
        if (locacao.codigo == codigoLocacao)
        {
            encontrouLocacao = 1;
            // Utiliza o código do veículo associado à locação para obter a diária
            Veiculo veiculo;
            FILE *arquivoVeiculo = fopen("veiculos.bin", "rb");

            if (arquivoVeiculo == NULL)
            {
                printf("Erro ao abrir o arquivo de veículos.\n");
                fclose(arquivo);
                return;
            }

            // Busca o veículo associado à locação
            while (fread(&veiculo, sizeof(Veiculo), 1, arquivoVeiculo))
            {
                if (veiculo.codigo == locacao.codigoVeiculo)
                {
                    valorTotal = locacao.qtdDias * veiculo.valorDiaria;

                    // Adiciona o valor do seguro, se necessário
                    if (locacao.seguro)
                    {
                        valorTotal += locacao.qtdDias * TAXA_SEGURO;
                    }

                    fclose(arquivoVeiculo);
                    break;
                }
            }

            break;
        }
    }

    fclose(arquivo);

    if (encontrouLocacao)
    {
        printf("Valor total da locação: R$ %.2f\n", valorTotal);
    }
    else
    {
        printf("Locação não encontrada.\n");
    }
}

void calcularPontosFidelidade()
{
    int codigoCliente;
    Locacao locacao;
    int pontos = 0;
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
            pontos += locacao.qtdDias;
        }
    }

    fclose(arquivo);

    printf("Total de pontos de fidelidade: %d\n", pontos);
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