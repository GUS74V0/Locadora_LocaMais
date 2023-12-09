

#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

// Definição das estruturas de dados
typedef struct {
    int codigo;
    char nome[50];
    char endereco[100];
    char telefone[15];
    int pontosFidelidade;
} Cliente;

typedef struct {
    int codigo;
    char descricao[50];
    char modelo[20];
    char cor[20];
    char placa[10];
    float valor_diaria;
    int ocupantes;
    char status[20]; // alugado, disponível, em manutenção
} Veiculo;

typedef struct {
    int codigo;
    char data_retirada[11];
    char data_devolucao[11];
    int seguro;
    int qtd_dias;
    int codigo_cliente;
    int codigo_veiculo;
} Locacao;

#endif