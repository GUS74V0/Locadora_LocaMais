#include "structure.h"

void cadastrarCliente();
void cadastrarVeiculo();
void cadastrarLocacao();

// Codigo para Cliente

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

    printf("Digite o Codigo do cliente: ");
    scanf("%d", &cliente.codigo);

    while (fread(&clienteAux, sizeof(Cliente), 1, arquivo))
    {
        if (clienteAux.codigo == cliente.codigo)
        {
            existeCliente = 1;
            printf("Cliente com este Codigo ja existe.\n");
            break;
        }
    }

    if (!existeCliente)
    {
        printf("Nome do cliente: ");
        scanf(" %50[^\n]", cliente.nome);
        printf("Endereço: ");
        scanf(" %100[^\n]", cliente.endereco);
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

    printf("Digite o Codigo do cliente: ");
    scanf("%d", &codigoCliente);

    while (fread(&cliente, sizeof(Cliente), 1, arquivo))
    {
        if (cliente.codigo == codigoCliente)
        {
            encontrado = 1;
            printf("Codigo: %d\nNome: %s\nEndereço: %s\nTelefone: %s\n",
                   cliente.codigo, cliente.nome, cliente.endereco, cliente.telefone);
            break;
        }
    }

    fclose(arquivo);

    if (!encontrado)
    {
        printf("Cliente nao encontrado.\n");
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

    printf("Digite o Codigo do cliente: ");
    scanf("%d", &codigoCliente);

    while (fread(&locacao, sizeof(Locacao), 1, arquivo))
    {
        if (locacao.codigoCliente == codigoCliente)
        {
            encontrouLocacao = 1;
            printf("Codigo Locacao: %d\nCodigo Veiculo: %d\nData Retirada: %s\nData Devolucao: %s\n",
                   locacao.codigo, locacao.codigoVeiculo, locacao.dataRetirada, locacao.dataDevolucao);
        }
    }

    fclose(arquivo);

    if (!encontrouLocacao)
    {
        printf("nao foram encontradas locacoees para este cliente.\n");
    }
}

// Codigo para Veiculos

void cadastrarVeiculo()
{
    Veiculo veiculo, veiculoAux;
    int veiculoExiste = 0;
    FILE *arquivo = fopen("veiculos.bin", "ab+"); // Corrigido para ab+

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("Digite o Codigo do Veiculo: ");
    scanf("%d", &veiculo.codigo);

    while (fread(&veiculoAux, sizeof(Veiculo), 1, arquivo))
    {
        if (veiculoAux.codigo == veiculo.codigo)
        {
            veiculoExiste = 1;
            printf("Um Veiculo com este Codigo ja existe.\n");
            break;
        }
    }

    if (!veiculoExiste)
    {
        printf("Descricao: ");
        scanf("%s", veiculo.descricao);
        printf("Modelo: ");
        scanf("%s", veiculo.modelo);
        printf("Cor: ");
        scanf("%s", veiculo.cor);
        printf("Placa: ");
        scanf("%s", veiculo.placa);
        printf("Valor da Diaria: ");
        scanf("%f", &veiculo.valorDiaria);
        printf("Quantidade de ocupantes: ");
        scanf("%d", &veiculo.qtdOcupantes);

        strcpy(veiculo.status, "disponivel");

        fseek(arquivo, 0, SEEK_END);
        fwrite(&veiculo, sizeof(Veiculo), 1, arquivo);
    }

    fclose(arquivo);
}

void pesquisarVeiculo()
{
    int codigoVeiculo;
    Veiculo veiculo;
    int encontrado = 0;
    FILE *arquivo = fopen("veiculos.bin", "rb");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("Digite o Codigo do Veiculo: ");
    scanf("%d", &codigoVeiculo);

    while (fread(&veiculo, sizeof(Veiculo), 1, arquivo))
    {
        if (veiculo.codigo == codigoVeiculo)
        {
            encontrado = 1;
            printf("Codigo: %d\nDescricao: %s\nModelo: %s\nCor: %s\nPlaca: %s\nValor Diaria: %.2f\nOcupantes: %d\n",
                   veiculo.codigo, veiculo.descricao, veiculo.modelo, veiculo.cor, veiculo.placa, veiculo.valorDiaria, veiculo.qtdOcupantes);
            break;
        }
    }

    fclose(arquivo);

    if (!encontrado)
    {
        printf("Veiculo nao encontrado.\n");
    }
}

void relatorioVeiculos()
{
    Veiculo veiculo;
    int veiculosDisponiveis = 0;
    FILE *arquivo = fopen("veiculos.bin", "rb");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("Veiculos disponiveis:\n");

    while (fread(&veiculo, sizeof(Veiculo), 1, arquivo))
    {
        if (strcmp(veiculo.status, "disponivel") == 0)
        {
            printf("Codigo: %d | Descricao: %s | Modelo: %s | Cor: %s | Placa: %s\n",
                   veiculo.codigo, veiculo.descricao, veiculo.modelo, veiculo.cor, veiculo.placa);
            veiculosDisponiveis++;
        }
    }

    if (veiculosDisponiveis == 0)
    {
        printf("Nao ha veiculos disponiveis no momento.\n");
    }

    fclose(arquivo);
}

// Codigo para Locaçao

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

    printf("Digite o codigo da locacao: ");
    scanf("%d", &locacao.codigo);

    printf("Codigo do Cliente: ");
    scanf("%d", &locacao.codigoCliente);
    printf("Codigo do Veiculo: ");
    scanf("%d", &locacao.codigoVeiculo);

    while (fread(&veiculoAux, sizeof(Veiculo), 1, arquivoVeiculo))
    {
        if (veiculoAux.codigo == locacao.codigoVeiculo && strcmp(veiculoAux.status, "alugado") == 0)
        {
            veiculoDisponivel = 0;
            printf("Veiculo nao disponivel para locacao.\n");
            break;
        }
    }

    if (veiculoDisponivel)
    {
        printf("Data de Retirada (dd/mm/aaaa): ");
        scanf("%s", locacao.dataRetirada);
        printf("Data de Devolucao (dd/mm/aaaa): ");
        scanf("%s", locacao.dataDevolucao);
        printf("Seguro (0 para nao, 1 para sim): ");
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

    printf("Digite o codigo da locacao para dar baixa: ");
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
                            strcpy(veiculo.status, "disponivel");
                            fseek(arquivoVeiculo, -sizeof(Veiculo), SEEK_CUR);
                            fwrite(&veiculo, sizeof(Veiculo), 1, arquivoVeiculo);
                            break;
                        }
                    }

                    break;
                }
            }

            printf("Locacao finalizada e veiculo disponivel novamente.\n");
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

    printf("Digite o codigo da locacao: ");
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
                printf("Erro ao abrir o arquivo de veiculos.\n");
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
        printf("Valor total da locacao: R$ %.2f\n", valorTotal);
    }
    else
    {
        printf("Locacao nao encontrada.\n");
    }
}

void calcularPontosFidelidade()
{
    int codigoCliente;
    Locacao locacao;
    int pontos = 10;
    FILE *arquivo = fopen("locacoes.bin", "rb");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("Digite o codigo do cliente: ");
    scanf("%d", &codigoCliente);

    while (fread(&locacao, sizeof(Locacao), 1, arquivo))
    {
        if (locacao.codigoCliente == codigoCliente)
        {
            pontos *= locacao.qtdDias;
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
        printf("2. Cadastrar Veiculo\n");
        printf("3. Cadastrar Locacao\n");
        printf("4. Dar Baixa em Locacao\n");
        printf("5. Calcular Valor Total da Locacao\n");
        printf("6. Pesquisar Cliente\n");
        printf("7. Pesquisar Veiculo\n");
        printf("8. Exibir Locacoes de Cliente\n");
        printf("9. Calcular Pontos de Fidelidade\n");
        printf("10. Exibir Relatorio de Veiculos Disponiveis\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
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
            relatorioVeiculos();
            break;
        case 0:
            printf("Saindo do sistema...\n");
            break;
        default:
            printf("Opção invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
