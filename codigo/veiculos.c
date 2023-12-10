
#include "structure.h"


void cadastrarVeiculo();
void pesquisarVeiculo();
void relatorioVeiculosDisponiveis();

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

    printf("Digite o código do veículo: ");
    scanf("%d", &veiculo.codigo);

    while (fread(&veiculoAux, sizeof(Veiculo), 1, arquivo))
    {
        if (veiculoAux.codigo == veiculo.codigo)
        {
            veiculoExiste = 1;
            printf("Um veículo com este código já existe.\n");
            break;
        }
    }

    if (!veiculoExiste)
    {
        printf("Descrição: ");
        scanf("%s", veiculo.descricao);
        printf("Modelo: ");
        scanf("%s", veiculo.modelo);
        printf("Cor: ");
        scanf("%s", veiculo.cor);
        printf("Placa: ");
        scanf("%s", veiculo.placa);
        printf("Valor da diária: ");
        scanf("%f", &veiculo.valorDiaria);
        printf("Quantidade de ocupantes: ");
        scanf("%d", &veiculo.qtdOcupantes);

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

    printf("Digite o código do veículo: ");
    scanf("%d", &codigoVeiculo);

    while (fread(&veiculo, sizeof(Veiculo), 1, arquivo))
    {
        if (veiculo.codigo == codigoVeiculo)
        {
            encontrado = 1;
            printf("Código: %d\nDescrição: %s\nModelo: %s\nCor: %s\nPlaca: %s\nValor Diária: %.2f\nOcupantes: %d\n",
                   veiculo.codigo, veiculo.descricao, veiculo.modelo, veiculo.cor, veiculo.placa, veiculo.valorDiaria, veiculo.qtdOcupantes);
            break;
        }
    }

    fclose(arquivo);

    if (!encontrado)
    {
        printf("Veículo não encontrado.\n");
    }
}

void relatorioVeiculosDisponiveis()
{
    Veiculo veiculo;
    int veiculosDisponiveis = 0;
    FILE *arquivo = fopen("veiculos.bin", "rb");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("Veículos disponíveis:\n");
    while (fread(&veiculo, sizeof(Veiculo), 1, arquivo))
    {
        if (strcmp(veiculo.status, "disponível") == 0)
        {
            printf("Código: %d, Descrição: %s, Modelo: %s, Cor: %s, Placa: %s\n",
                   veiculo.codigo, veiculo.descricao, veiculo.modelo, veiculo.cor, veiculo.placa);
            veiculosDisponiveis++;
        }
    }

    if (veiculosDisponiveis == 0)
    {
        printf("Não há veículos disponíveis no momento.\n");
    }

    fclose(arquivo);
}
