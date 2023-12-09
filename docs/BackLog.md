# Backlog do Produto - Projeto LocaMais

## 1. Cadastro de Clientes
   - **Módulo:** `cadastrarCliente`
     - *Descrição*: Implementar a funcionalidade que permite o cadastro de novos clientes no sistema. Critérios de Aceitação: Os clientes devem ter um código único, e as informações incluem nome, endereço e telefone.
   - *Caso de Sucesso*: Cadastrar um novo cliente com informações válidas.
   - *Casos de Teste*:
     - Entrada: 2, Lucas, Rua Ernesto Austin, N/A
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

## 4. Baixa em Locação
   - **Módulo:** `darBaixaLocacao`
     - *Descrição*: Desenvolver a funcionalidade que permite dar baixa em uma locação, alterando o status do veículo e calculando o valor total da locação. Critérios de Aceitação: Deve ser possível calcular multa por atraso na devolução.
   - *Caso de Sucesso*: Dar baixa em uma locação com informações válidas.
   - *Casos de Teste*:
     - Entrada: Informações válidas da locação e veículo.
     - Saída Esperada: Locação encerrada com sucesso.

## 5. Pesquisa de Clientes
   - **Módulo:** `buscarCliente`
     - *Descrição*: Implementar a capacidade de buscar clientes pelo nome ou código. Critérios de Aceitação: A pesquisa deve retornar todas as informações relevantes do cliente.
   - *Caso de Sucesso*: Encontrar as informações do cliente com o código especificado.
   - *Casos de Teste*:
     - Entrada: 1 (Código do cliente existente).
     - Saída Esperada: Informações do cliente com o código 1.

## 6. Pesquisa de Veículos
   - **Módulo:** `buscarVeiculo`
     - *Descrição*: Desenvolver a funcionalidade que permite buscar veículos pelo modelo, placa ou código. Critérios de Aceitação: A pesquisa deve retornar todas as informações relevantes do veículo.
   - *Caso de Sucesso*: Encontrar as informações do veículo com o código especificado.
   - *Casos de Teste*:
     - Entrada: 1 (Código do veículo existente).
     - Saída Esperada: Informações do veículo com o código 1.

## 7. Visualizar Locações de Cliente
   - **Módulo:** `mostrarLocacoesCliente`
     - *Descrição*: Criar a funcionalidade que exibe todas as locações de um cliente, com base no nome ou código do cliente. Critérios de Aceitação: A visualização deve incluir todas as informações relevantes das locações.
   - *Caso de Sucesso*: Exibir corretamente todas as locações do cliente com base no nome ou código.
   - *Casos de Teste*:
     - Entrada: Lucas (Nome do cliente existente).
     - Saída Esperada: Lista de locações do cliente Lucas.

## 8. Programa de Fidelidade
   - **Módulo:** `calcularPontosFidelidade`
     - *Descrição*: Implementar o programa de fidelidade que calcula pontos para clientes com base na quantidade de dias de locação. Critérios de Aceitação: Os clientes ganham 10 pontos por dia de locação.
   - *Caso de Sucesso*: Calcular corretamente os pontos de fidelidade de um cliente.
   - *Casos de Teste*:
     - Entrada: 1 (Código do cliente existente).
     - Saída Esperada: Quantidade correta de pontos de fidelidade.

## 9. Premiação por Fidelidade
   - **Módulo:** `premiarPorFidelidade`
     - *Descrição*: Criar a funcionalidade que premia clientes com mais de 500 pontos no programa de fidelidade. Critérios de Aceitação: Os clientes premiados recebem um kit da LocaMais.
   - *Caso de Sucesso*: Premiar corretamente clientes com mais de 500 pontos.
   - *Casos de Teste*:
     - Entrada: Cliente com 600 pontos.
     - Saída Esperada: Cliente premiado com um kit.

## 10. Função Extra - Relatórios Gerenciais
   - **Módulo:** `gerarRelatoriosGerenciais`
     - *Descrição*: Implementar uma função extra que forneça relatórios gerenciais sobre as locações, clientes e veículos. Critérios de Aceitação: Os relatórios devem ser detalhados e fornecer informações úteis para a tomada de decisão.
   - *Caso de Sucesso*: Gerar relatórios detalhados e úteis.
   - *Casos de Teste*:
     - Entrada: Dados válidos de locações, clientes e veículos.
     - Saída Esperada: Relatórios gerenciais detalhados.

