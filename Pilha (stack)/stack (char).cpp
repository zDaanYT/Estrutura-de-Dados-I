#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

char pilha[MAX][50];
int topo = -1;

int push(char valor[]) {
    if (topo >= MAX - 1) {
        printf("ERRO: Pilha cheia!\n");
        return -1;
    }

    topo++;
    strcpy(pilha[topo], valor);
    return topo;
}

char* pop() {
    if (topo < 0) {
        printf("ERRO: Pilha vazia!\n");
        return NULL;
    }

    return pilha[topo--];
}

char* peek() {
    if (topo < 0) {
        printf("Pilha vazia!\n");
        return NULL;
    }

    return pilha[topo];
}

void imprime() {
    int i = 0;

    printf("--------------------\n");

    while (i <= topo) {
        printf("  %s\n", pilha[i]);
        i++;
    }

    printf("--------------------\n");
}

void inicializar() {
    topo = -1;
    memset(pilha, 0, sizeof(pilha));
}

int main() {
    int opcao = -1;
    char elemento[50];

    inicializar();

    while(opcao != 0) { // 0 é sair
        printf("\n----------------------------------------\n");
        printf("  1. PUSH\n");
        printf("  2. POP (remove o ultimo adicionado) \n");
        printf("  3. PEEK (mostra o topo da pilha)\n");
        printf("  4. PRINT (mostra a pilha inteira)\n");
        printf("  0. SAIR\n");
        printf("----------------------------------------\n\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite uma palavra: ");
                scanf("%s", elemento);
                push(elemento);
                break;

            case 2: {
                char* elemento_removido = pop();
                if (elemento_removido != NULL)
                    printf("Elemento removido: %s\n", elemento_removido);
                break;
            }

            case 3: {
                char* elemento_topo = peek();
                if (elemento_topo != NULL)
                    printf("Topo da pilha: %s\n", elemento_topo);
                break;
            }

            case 4:
                imprime();
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    }

    return 0;
}