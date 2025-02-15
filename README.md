# Lista Duplamente Encadeada - Programa em C

Este é um programa em C que implementa uma lista duplamente encadeada para armazenar informações sobre pessoas, como nome, sexo e salário. O programa permite a leitura desses dados a partir de um arquivo texto e oferece opções para exibir os dados da lista em ordem crescente ou decrescente.

## Funcionalidades

- **Leitura de dados:** O programa lê dados de um arquivo texto e armazena informações sobre as pessoas.
- **Exibição de dados:** O usuário pode visualizar os dados das pessoas na lista em ordem crescente ou decrescente.
- **Ordenação por nome:** A lista pode ser ordenada em ordem crescente com base no nome das pessoas.

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


Exemplo:


2. **Compile e execute o programa:**

Para compilar o programa, use o compilador C (por exemplo, `gcc`):

```bash
gcc -o lista_encadeada lista_encadeada.c.c

./lista_encadeada.c
