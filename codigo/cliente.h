#ifndef CLIENTE_H
#define CLIENTE_H

#include "structure.h"

int clienteExiste(Cliente clientes[], int totalClientes, int codigo);
void cadastrarCliente(Cliente clientes[], int *totalClientes);
void carregarClientes(Cliente clientes[], int *totalClientes);
void exibirDetalhesCliente(Cliente cliente);


#endif