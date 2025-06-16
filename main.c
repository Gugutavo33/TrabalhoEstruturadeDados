#include <stdio.h>   // Biblioteca padrão para entrada e saída
#include <string.h>  // Biblioteca para manipulação de strings
#include <stdlib.h>  // Biblioteca para funções gerais como system()

#define MAX_TAREFAS 100   // Define o tamanho máximo da lista de tarefas
#define TAM_TAREFA 100    // Define o tamanho máximo de caracteres de cada tarefa

// Declaração da lista de tarefas (array de strings)
char tarefas[MAX_TAREFAS][TAM_TAREFA];

// Contador de tarefas atuais na lista
int totalTarefas = 0;

// Função para adicionar uma nova tarefa
void adicionarTarefa() {
    if (totalTarefas == MAX_TAREFAS) {   // Verifica se a lista está cheia
        printf("Lista cheia! Nao e possivel adicionar mais tarefas.\n");
        return;                          // Sai da função se estiver cheia
    }
    printf("Digite a tarefa: ");
    fgets(tarefas[totalTarefas], TAM_TAREFA, stdin);   // Lê a tarefa do usuário
    tarefas[totalTarefas][strcspn(tarefas[totalTarefas], "\n")] = 0; // Remove o '\n' final
    totalTarefas++;                     // Incrementa o número de tarefas
    printf("Tarefa adicionada com sucesso!\n");
}

// Função para listar todas as tarefas
void listarTarefas() {
    if (totalTarefas == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
        return;
    }
    printf("Lista de tarefas:\n");
    for (int i = 0; i < totalTarefas; i++) {
        printf("%d - %s\n", i + 1, tarefas[i]);   // Mostra índice e a tarefa
    }
}

// Função para remover uma tarefa pelo número
void removerTarefa() {
    if (totalTarefas == 0) {
        printf("Nenhuma tarefa para remover.\n");
        return;
    }
    int num;
    printf("Digite o numero da tarefa para remover: ");
    scanf("%d", &num);
    getchar(); // Limpa o buffer do teclado após scanf

    if (num < 1 || num > totalTarefas) {    // Verifica se o número é válido
        printf("Numero invalido.\n");
        return;
    }

    // Move todas as tarefas após a removida uma posição para trás
    for (int i = num - 1; i < totalTarefas - 1; i++) {
        strcpy(tarefas[i], tarefas[i + 1]);
    }
    totalTarefas--;   // Decrementa o número de tarefas
    printf("Tarefa removida com sucesso!\n");
}

// Função para editar uma tarefa
void editarTarefa() {
    if (totalTarefas == 0) {
        printf("Nenhuma tarefa para editar.\n");
        return;
    }
    int num;
    printf("Digite o numero da tarefa para editar: ");
    scanf("%d", &num);
    getchar(); // Limpa o buffer

    if (num < 1 || num > totalTarefas) {
        printf("Numero invalido.\n");
        return;
    }

    printf("Digite a nova descricao da tarefa: ");
    fgets(tarefas[num - 1], TAM_TAREFA, stdin);
    tarefas[num - 1][strcspn(tarefas[num - 1], "\n")] = 0; // Remove '\n'

    printf("Tarefa editada com sucesso!\n");
}

// Função principal do programa
int main() {
    int opcao;

    do {
        // Mostra o menu
        printf("\nLista de Tarefas\n");
        printf("1. Adicionar tarefa\n");
        printf("2. Remover tarefa\n");
        printf("3. Editar tarefa\n");
        printf("4. Listar tarefas\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        // Executa a ação conforme a opção
        switch (opcao) {
            case 1:
                adicionarTarefa();
                break;
            case 2:
                removerTarefa();
                break;
            case 3:
                editarTarefa();
                break;
            case 4:
                listarTarefas();
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);  // Enquanto não escolher sair

    return 0;  // Finaliza o programa
}
