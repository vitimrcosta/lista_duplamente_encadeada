# Lista Duplamente Encadeada - Programa em C

Este é um programa em C que carrega dados de um arquivo texto em uma lista duplamente encadeada e permite exibir os dados em ordem crescente ou decrescente de nome. O programa foi desenvolvido como parte de um exercício de programação.

## Funcionalidades

- Carrega dados de um arquivo texto.
- Armazena os dados em uma lista duplamente encadeada.
- Ordena os dados por nome.
- Exibe os dados em ordem crescente ou decrescente.
- Interface simples com menu interativo.

## Estrutura do Arquivo de Entrada

O arquivo de entrada (`file example - ed`) deve seguir o formato abaixo:

Nome Completo SexoSalario
Olivia Davis F000000345
William Garcia M000006789
Ava Rodriguez F000000001
James Wilson M000123456
Sophia Anderson F000098765
Benjamin Thomas M000000009
Mia Jackson F000000010
Ethan White M000000789
Charlotte Harris F000001234
Daniel Martin M000045678

## Estrutura de Dados

O programa utiliza uma **lista duplamente encadeada** para armazenar os dados das pessoas. Cada nó da lista contém os seguintes campos:

- **Nome:** Nome da pessoa.
- **Sexo:** Sexo da pessoa (representado por um caractere: 'M' ou 'F').
- **Salário:** Salário da pessoa (um número decimal).

Cada nó também contém dois ponteiros:

- **prox:** Aponta para o próximo nó na lista.
- **ant:** Aponta para o nó anterior na lista.

## Como Usar

1. **Abra o arquivo `file example - ed`** contendo os dados das pessoas no formato:

2. **Compile e execute o programa:**

Para compilar o programa, use o compilador C (por exemplo, `gcc`):

gcc -o lista_encadeada lista_encadeada.c.c

./lista_encadeada.c

## Exemplo Saída:

-----------------------------------------------------------------
Nome: Ava Rodriguez
Sexo: F
Salario: 1.00
-----------------------------------------------------------------
Nome: Benjamin Thomas
Sexo: M
Salario: 9.00
-----------------------------------------------------------------
Nome: Charlotte Harris
Sexo: F
Salario: 1234.00
-----------------------------------------------------------------

## Estrutura do Código

1. **main.c:** Contém a função principal do programa, a leitura do arquivo e a interface do menu.

2. **Lista Duplamente Encadeada:** Implementada usando a estrutura Pessoa, com ponteiros para o próximo e anterior nó.

3. **Ordenação:** Utiliza o algoritmo Bubble Sort para ordenar os dados por nome.



