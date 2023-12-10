#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAXA_SEGURO 20.0

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
    char descricao[100];
    char modelo[50];
    char descricao[50];
    char modelo[20];
    char cor[20];
    char placa[10];
    float valorDiaria;
    int qtdOcupantes;
    char status[15];
    float valor_diaria;
    int ocupantes;
    char status[20]; // alugado, disponível, em manutenção
} Veiculo;


typedef struct {
    int codigo;
    int codigoCliente;
    int codigoVeiculo;
    char dataRetirada[10];
    char dataDevolucao[10];
    int seguro; // 0= nao 1= sim
    int qtdDias;
    char data_retirada[11];
    char data_devolucao[11];
    int seguro;
    int qtd_dias;
    int codigo_cliente;
    int codigo_veiculo;
} Locacao;

#endif