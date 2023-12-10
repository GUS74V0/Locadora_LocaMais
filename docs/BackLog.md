# Backlog do Produto - Projeto LocaMais

## 1. Cadastro de Clientes
   - **Módulo:** `cadastrarCliente`
     - *Descrição*: Implementar a funcionalidade que permite o cadastro de novos clientes no sistema. Critérios de Aceitação: Os clientes devem ter um código único, e as informações incluem nome, endereço e telefone.
   - *Caso de Sucesso*: Cadastrar um novo cliente com informações válidas.
   - *Casos de Teste*:
     - Entrada: 2, Gabriel, Rua Ernesto Austin, 9999-9999
     - Saída Esperada: Novo cliente cadastrado com sucesso.

## 2. Cadastro de Veículos
   - **Módulo:** `cadastrarVeiculo`
     - *Descrição*: Desenvolver a capacidade de cadastrar novos veículos no sistema. Critérios de Aceitação: Os veículos devem ter um código único, e as informações incluem descrição, modelo, cor, placa, valor da diária, quantidade de ocupantes e status.
   - *Caso de Sucesso*: Cadastrar um novo veículo com informações válidas.
   - *Casos de Teste*:
     - Entrada: Informações válidas do veículo.
     - Saída Esperada: Novo veículo cadastrado com sucesso.

## 3. Cadastro de Locações
   - **Módulo:** `cadastrarLocacao`
     - *Descrição*: Implementar a funcionalidade de cadastro de locações, considerando a associação com clientes e veículos. Critérios de Aceitação: Locações devem incluir data de retirada, data de devolução, seguro, quantidade de dias, código do cliente e código do veículo.
   - *Caso de Sucesso*: Registrar uma nova locação com informações válidas.
   - *Casos de Teste*:
     - Entrada: 1, 18/11/2023, 25/11/2023, Sim, 1, 1 
     - Saída Esperada: Locação registrada com sucesso.

## 4. Pesquisa de Cliente

- **Módulo:** `pesquisarCliente`
  - *Descrição*: Adicionar a capacidade de pesquisar um cliente pelo código.
- *Caso de Sucesso*: Encontrar e exibir informações do cliente pelo código.
- *Casos de Teste*:
  - Entrada: Código existente de um cliente.
  - Saída Esperada: Exibir informações do cliente.

---

## 5. Pesquisa de Veículo

- **Módulo:** `pesquisarVeiculo`
  - *Descrição*: Desenvolver a funcionalidade de pesquisar um veículo pelo código.
- *Caso de Sucesso*: Encontrar e exibir informações do veículo pelo código.
- *Casos de Teste*:
  - Entrada: Código existente de um veículo.
  - Saída Esperada: Exibir informações do veículo.

---

## 6. Exibição de Locações de Cliente

- **Módulo:** `exibirLocacoesCliente`
  - *Descrição*: Implementar a funcionalidade de exibir todas as locações de um cliente pelo código.
- *Caso de Sucesso*: Exibir as locações do cliente corretamente.
- *Casos de Teste*:
  - Entrada: Código existente de um cliente com locações.
  - Saída Esperada: Exibir informações das locações do cliente.

---

## 7. Dar Baixa em Locação

- **Módulo:** `darBaixaLocacao`
  - *Descrição*: Adicionar a funcionalidade de dar baixa em uma locação pelo código.
- *Caso de Sucesso*: Finalizar a locação e marcar o veículo como disponível.
- *Casos de Teste*:
  - Entrada: Código existente de uma locação.
  - Saída Esperada: Locação finalizada e veículo disponível novamente.

---

## 8. Calcular Valor Total da Locação

- **Módulo:** `calcularValorTotal`
  - *Descrição*: Implementar a funcionalidade de calcular o valor total de uma locação com base nas diárias, valor da diária do veículo e seguro, se aplicável.
- *Caso de Sucesso*: Calcular o valor total corretamente.
- *Casos de Teste*:
  - Entrada: Código existente de uma locação.
  - Saída Esperada: Exibir o valor total da locação.

---

## 9. Calcular Pontos de Fidelidade

- **Módulo:** `calcularPontosFidelidade`
  - *Descrição*: Adicionar a capacidade de calcular os pontos de fidelidade de um cliente com base nas locações realizadas.
- *Caso de Sucesso*: Calcular os pontos corretamente.
- *Casos de Teste*:
  - Entrada: Código existente de um cliente com locações.
  - Saída Esperada: Exibir o total de pontos de fidelidade do cliente.

---

## 10. Premiação por Fidelidade
   - **Módulo:** `calcularPontosFidelidade`
     - *Descrição*: Criar a funcionalidade que premia clientes com mais de 500 pontos no programa de fidelidade. Critérios de Aceitação: Os clientes premiados recebem um kit da LocaMais.
   - *Caso de Sucesso*: Premiar corretamente clientes com mais de 500 pontos.
   - *Casos de Teste*:
     - Entrada: Cliente com 600 pontos.
     - Saída Esperada: Cliente premiado com um parabens.
---

## 11. Exibição de Relatório de Veículos Disponíveis

- **Módulo:** `relatorioVeiculos`
  - *Descrição*: Implementar a funcionalidade de exibir um relatório dos veículos disponíveis no momento.
- *Caso de Sucesso*: Exibir o relatório corretamente.
- *Casos de Teste*:
  - Entrada: Sistema com veículos disponíveis.
  - Saída Esperada: Exibir relatório de veículos disponíveis.

---


