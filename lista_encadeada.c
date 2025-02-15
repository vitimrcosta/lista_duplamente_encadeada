#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar os dados de cada pessoa
typedef struct Pessoa {
    char nome[100];       // Armazena o nome da pessoa
    char sexo;            // Armazena o sexo da pessoa (M ou F)
    float salario;        // Armazena o salário da pessoa
    struct Pessoa* prox;  // Ponteiro para o próximo nó na lista
    struct Pessoa* ant;   // Ponteiro para o nó anterior na lista
} Pessoa;

// Função para criar um novo nó
Pessoa* criarNo(char nome[], char sexo, float salario) {
    // Aloca memória para um novo nó
    Pessoa* novoNo = (Pessoa*)malloc(sizeof(Pessoa));
    
    // Copia o nome para o nó
    strcpy(novoNo->nome, nome);
    
    // Atribui o sexo e o salário ao nó
    novoNo->sexo = sexo;
    novoNo->salario = salario;
    
    // Inicializa os ponteiros prox e ant como NULL
    novoNo->prox = NULL;
    novoNo->ant = NULL;
    
    // Retorna o novo nó criado
    return novoNo;
}

// Função para inserir um nó na lista
void inserirNo(Pessoa** head, Pessoa* novoNo) {
    // Se a lista estiver vazia, o novo nó se torna o primeiro nó
    if (*head == NULL) {
        *head = novoNo;
    } else {
        // Caso contrário, percorre a lista até o último nó
        Pessoa* temp = *head;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        
        // Insere o novo nó no final da lista
        temp->prox = novoNo;
        novoNo->ant = temp;
    }
}

// Função para exibir a lista em ordem crescente
void exibirCrescente(Pessoa* head) {
    // Inicia do primeiro nó
    Pessoa* temp = head;
    
    // Percorre a lista até o final
    while (temp != NULL) {
        // Exibe os dados do nó atual
        printf("-----------------------------------------------------------------\n");
        printf("Nome: %s\n", temp->nome);
        printf("Sexo: %c\n", temp->sexo);
        printf("Salario: %.2f\n", temp->salario);
        
        // Avança para o próximo nó
        temp = temp->prox;
    }
    printf("-----------------------------------------------------------------\n");
}

// Função para exibir a lista em ordem decrescente
void exibirDecrescente(Pessoa* head) {
    // Inicia do primeiro nó
    Pessoa* temp = head;
    
    // Percorre a lista até o último nó
    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    
    // Agora, percorre a lista de trás para frente
    while (temp != NULL) {
        // Exibe os dados do nó atual
        printf("-----------------------------------------------------------------\n");
        printf("Nome: %s\n", temp->nome);
        printf("Sexo: %c\n", temp->sexo);
        printf("Salario: %.2f\n", temp->salario);
        
        // Retrocede para o nó anterior
        temp = temp->ant;
    }
    printf("-----------------------------------------------------------------\n");
}

// Função para ordenar a lista por nome (ordem crescente)
void ordenarPorNome(Pessoa** head) {
    // Verifica se a lista está vazia ou tem apenas um nó
    if (*head == NULL || (*head)->prox == NULL) {
        return; // Não há nada para ordenar
    }

    int trocou; // Flag para verificar se houve troca durante a iteração
    Pessoa* ptr1;
    Pessoa* lptr = NULL;

    do {
        trocou = 0;
        ptr1 = *head;

        // Percorre a lista
        while (ptr1->prox != lptr) {
            // Compara os nomes dos nós adjacentes
            if (strcmp(ptr1->nome, ptr1->prox->nome) > 0) {
                // Troca os dados dos nós
                char tempNome[100];
                strcpy(tempNome, ptr1->nome);
                strcpy(ptr1->nome, ptr1->prox->nome);
                strcpy(ptr1->prox->nome, tempNome);

                char tempSexo = ptr1->sexo;
                ptr1->sexo = ptr1->prox->sexo;
                ptr1->prox->sexo = tempSexo;

                float tempSalario = ptr1->salario;
                ptr1->salario = ptr1->prox->salario;
                ptr1->prox->salario = tempSalario;

                trocou = 1; // Indica que houve uma troca
            }
            ptr1 = ptr1->prox; // Avança para o próximo nó
        }
        lptr = ptr1; // Marca o último nó ordenado
    } while (trocou); // Repete até que não haja mais trocas
}

int main() {
    FILE *arq;
    Pessoa* head = NULL; // Inicializa a lista como vazia
    char linha[150]; // Buffer para armazenar cada linha do arquivo

    // Abre o arquivo para leitura
    arq = fopen("file example - ed", "r");
    
    // Verifica se o arquivo foi aberto corretamente
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Lê os dados do arquivo e insere na lista
    while (fgets(linha, sizeof(linha), arq) != NULL) {
        char nome[100], sexo;
        float salario;

        // Extrai o nome (posições 1 a 100)
        strncpy(nome, linha, 100);
        nome[100] = '\0'; // Garante que a string termine corretamente

        // Remove espaços em branco no final do nome
        int i = 99;
        while (i >= 0 && (nome[i] == ' ' || nome[i] == '\n')) {
            nome[i] = '\0';
            i--;
        }

        // Extrai o sexo (posição 101)
        sexo = linha[100];

        // Extrai o salário (a partir da posição 102)
        sscanf(linha + 101, "%f", &salario);

        // Insere na lista
        inserirNo(&head, criarNo(nome, sexo, salario));
    }

    // Fecha o arquivo após a leitura
    fclose(arq);

    // Ordena a lista por nome
    ordenarPorNome(&head);

    int opcao;
    do {
        // Exibe o menu de opções
        printf("\nMenu:\n");
        printf("1 - Mostrar dados em ordem crescente\n");
        printf("2 - Mostrar dados em ordem decrescente\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        // Executa a opção escolhida
        switch (opcao) {
            case 1:
                exibirCrescente(head); // Exibe em ordem crescente
                break;
            case 2:
                exibirDecrescente(head); // Exibe em ordem decrescente
                break;
            case 0:
                printf("Saindo...\n"); // Sai do programa
                break;
            default:
                printf("Opcao invalida!\n"); // Opção inválida
        }
    } while (opcao != 0); // Repete até que o usuário escolha sair

    // Libera a memória alocada para a lista
    Pessoa* temp;
    while (head != NULL) {
        temp = head;
        head = head->prox;
        free(temp); // Libera o nó atual
    }

    return 0;
}