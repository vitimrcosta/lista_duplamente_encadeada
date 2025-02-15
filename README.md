# Lista Duplamente Encadeada - Programa em C

Este é um programa em C que implementa uma lista duplamente encadeada para armazenar informações sobre pessoas, como nome, sexo e salário. O programa permite a leitura desses dados a partir de um arquivo e oferece opções para exibir os dados da lista em ordem crescente ou decrescente.

## Funcionalidades

- Carrega dados de um arquivo texto.
- Armazena os dados em uma lista duplamente encadeada.
- Ordena os dados por nome.
- Exibe os dados em ordem crescente ou decrescente.
- Interface simples com menu interativo.

## Estrutura de Dados

O programa utiliza uma **lista duplamente encadeada** para armazenar os dados das pessoas. Cada nó da lista contém os seguintes campos:

- **Nome:** Nome da pessoa.
- **Sexo:** Sexo da pessoa (representado por um caractere: 'M' ou 'F').
- **Salário:** Salário da pessoa (um número decimal).

Cada nó também contém dois ponteiros:

- **prox:** Aponta para o próximo nó na lista.
- **ant:** Aponta para o nó anterior na lista.

## Estrutura do Código

1. **main.c:** Contém a função principal do programa, a leitura do arquivo e a interface do menu.

2. **Lista Duplamente Encadeada:** Implementada usando a estrutura Pessoa, com ponteiros para o próximo e anterior nó.

3. **Ordenação:** Utiliza o algoritmo Bubble Sort para ordenar os dados por nome.


## Como Usar

1. **Abra o arquivo `file example - ed`** contendo os dados das pessoas no formato:

2. **Compile e execute o programa:**

Para compilar o programa, use o compilador C (por exemplo, `gcc`):

```bash
gcc -o lista_encadeada lista_encadeada.c.c

./lista_encadeada.c
