#include "cliente.h"
#include <stdio.h>
#include <string.h>

#define MAX_CLIENTES 100
#define CLIENTES_TXT "clientes.txt"
#define ARQUIVO_CLIENTES "clientes.dat"

int clienteExiste(Cliente clientes[], int totalClientes, int codigo) {
    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].codigo == codigo) {
            return 1; 
        }
    }
    return 0; 
}

int proximoCodigoCliente = 1;

void codigoClientes(Cliente clientes[], int *totalClientes) {
    FILE *arquivo = fopen(CLIENTES_TXT, "a");
    if (arquivo != NULL) {
        while (fread(&clientes[*totalClientes], sizeof(Cliente), 1, arquivo) == 1) {
            (*totalClientes)++;

            // Atualiza o próximo código a ser atribuído
            if (clientes[*totalClientes - 1].codigo >= proximoCodigoCliente) {
                proximoCodigoCliente = clientes[*totalClientes - 1].codigo + 1;
            }
        }
        fclose(arquivo);
    }
}

void cadastrarCliente(Cliente clientes[], int *totalClientes) {
    // Verifica se há espaço para mais clientes
    if (*totalClientes < MAX_CLIENTES) {
        Cliente novoCliente;

        // Atribui automaticamente o próximo código do cliente
        novoCliente.codigo = proximoCodigoCliente++;

        printf("Digite o nome do cliente: ");
        scanf("%s", novoCliente.nome);

        // Limpando o buffer do teclado antes de ler o endereço
        while (getchar() != '\n');

        printf("Digite o endereço do cliente: ");
        fgets(novoCliente.endereco, sizeof(novoCliente.endereco), stdin);
        novoCliente.endereco[strcspn(novoCliente.endereco, "\n")] = '\0';  // Remover o caractere de nova linha

        printf("Digite o telefone do cliente: ");
        scanf("%s", novoCliente.telefone);

        // Inicializa pontos de fidelidade
        novoCliente.pontosFidelidade = 0;

        // Adiciona o novo cliente 
        clientes[*totalClientes] = novoCliente;
        (*totalClientes)++;

        // Grava os clientes no arquivo
        FILE *arquivo = fopen(CLIENTES_TXT, "ab");
        if (arquivo != NULL) {
            fwrite(&novoCliente, sizeof(Cliente), 1, arquivo);
            fclose(arquivo);
        } else {
            printf("Erro ao abrir o arquivo de clientes.\n");
        }

        printf("Cliente cadastrado! Código atribuído: %d\n", novoCliente.codigo);
    } else {
        printf("Sem espaço para novos clientes!\n");
    }
}

void exibirDetalhesCliente(Cliente cliente) {
    printf("Código: %d | Nome: %s | Endereço: %s | Telefone: %s | Pts Fidelidade: %d\n", cliente.codigo, cliente.nome, cliente.endereco, cliente.telefone, cliente.pontosFidelidade);
}

void carregarClientes(Cliente clientes[], int *totalClientes) {
    FILE *arquivo = fopen(CLIENTES_TXT, "a");
    if (arquivo != NULL) {
        while (*totalClientes < MAX_CLIENTES && fread(&clientes[*totalClientes], sizeof(Cliente), 1, arquivo) == 1) {
            (*totalClientes)++;
        }
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo de clientes.\n");
    }
}


void adicionarPontosFidelidade(Cliente clientes[], int totalClientes, int codigoCliente, int diasLocacao) {
    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].codigo == codigoCliente) {
            clientes[i].pontosFidelidade += 10 * diasLocacao;
            printf("Adicionados %d pontos de fidelidade ao cliente %s.\n", 10 * diasLocacao, clientes[i].nome);
            break;
        }
    }
}

int main() {
    Cliente clientes[MAX_CLIENTES];
    int totalClientes = 0;

    // Carrega os clientes do arquivo (se houver)
    carregarClientes(clientes, &totalClientes);

    int opcao;

    do {
        // Exibe o menu
        printf("\n### Menu ###\n");
        printf("1. Cadastrar Cliente\n");
        printf("2. Exibir Detalhes de Cliente\n");
        printf("3. Adicionar Pontos de Fidelidade\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarCliente(clientes, &totalClientes);
                break;
            case 2:
                if (totalClientes > 0) {
                    int codigoCliente;
                    printf("Digite o código do cliente: ");
                    scanf("%d", &codigoCliente);
                    exibirDetalhesCliente(clientes[codigoCliente - 1]);
                } else {
                    printf("Não há clientes cadastrados.\n");
                }
                break;
            case 3:
                if (totalClientes > 0) {
                    int codigoCliente, diasLocacao;
                    printf("Digite o código do cliente: ");
                    scanf("%d", &codigoCliente);
                    printf("Digite a quantidade de dias de locação: ");
                    scanf("%d", &diasLocacao);
                    adicionarPontosFidelidade(clientes, totalClientes, codigoCliente, diasLocacao);
                } else {
                    printf("Não há clientes cadastrados.\n");
                }
                break;
            case 4:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 4);

    return 0;
}