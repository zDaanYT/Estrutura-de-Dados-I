#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int dado[MAX];
    int inicio;
    int final;
    int qtd;
} FILA_CIRCULAR;

void inicializar(FILA_CIRCULAR *fc) {
	fc->inicio = 0;
    fc->final = 0;
    fc->qtd = 0;
}

int estaCheia(FILA_CIRCULAR *fc) {
    return (fc -> qtd == MAX);
}

int estaVazia(FILA_CIRCULAR *fc) {
    return (fc -> qtd == 0);
}

void enqueue(FILA_CIRCULAR *fc, int valor) {
    if (estaCheia(fc)) {
        printf("Fila cheia! Nao foi possivel inserir o valor %d.\n", valor);
        return;
    }
    fc -> dado[fc->final] = valor;
    fc -> final = (fc->final + 1) % MAX;
    fc -> qtd++;
}

int dequeue(FILA_CIRCULAR *fc) {
    if (estaVazia(fc)) {
        printf("Fila vazia! Nao ha elementos para remover.\n");
        return -1;
    }

    int valor = fc -> dado[fc->inicio];
    fc -> inicio = (fc -> inicio + 1) % MAX;
    fc -> qtd--;
    return valor;
}

int first(FILA_CIRCULAR *fc) {
    if (estaVazia(fc)) {
        printf("Fila vazia!\n");
        return -1;
    }
    return fc->dado[fc->inicio];
}

void imprime(FILA_CIRCULAR *fc) {
    printf("Fila: \n");
    printf("--------------------------\n");

    for (int i = 0; i < fc -> qtd; i++) {
        int index = (fc -> inicio + i) % MAX;
        printf("%d ", fc -> dado[index]);
    }

    printf("\n");
    printf("--------------------------");
}

int main() {
    int opcao = -1;
    int valor = 0;

    FILA_CIRCULAR fc;

    inicializar(&fc);

    while(opcao != 0) { // 0 é sair
        printf("\n----------------------------------------\n");
        printf("  1. ENQUEUE\n");
        printf("  2. DEQUEUE (remove o primeiro adicionado) \n");
        printf("  3. FIRST (mostra o começo da fila)\n");
        printf("  4. PRINT (mostra a fila inteira)\n");
        printf("  5. DEQUEUE ALL (remove todos os elementos)\n");
        printf("  0. SAIR\n");
        printf("----------------------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Insira um valor: ");
                scanf("%d", &valor);
                enqueue(&fc, valor);

                printf("Valor adicionado com sucesso!\n");
                break;

            case 2: {
                int elemento_removido = dequeue(&fc);
                printf("Valor removido: %d\n", elemento_removido);
                imprime(&fc);
                break;
            }

            case 3: {
                int primeiro = first(&fc);
                if (primeiro != -1)
                    printf("Primeiro da fila: %d\n", primeiro);
                break;
            }

            case 4:
                imprime(&fc);
                break;

            case 5:
                while(!estaVazia(&fc)) {
                    int removido = dequeue(&fc);
                    if (removido != -1)
                        printf("Valor removido: %d\n", removido);
                }

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    }

    return 0;
}