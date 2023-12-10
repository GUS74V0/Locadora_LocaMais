#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAXA_SEGURO 20.0

#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

typedef struct
{
    int codigo;
    char nome[50];
    char endereco[100];
    char telefone[15];
} Cliente;

typedef struct
{
    int codigo;
    char descricao[100];
    char modelo[50];
    char cor[20];
    char placa[10];
    float valorDiaria;
    int qtdOcupantes;
    char status[15];
} Veiculo;

typedef struct
{
    int codigo;
    int codigoCliente;
    int codigoVeiculo;
    char dataRetirada[10];
    char dataDevolucao[10];
    int seguro; // 0= nao 1= sim
    int qtdDias;
} Locacao;

#endif
