#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int pilha[MAX];
int topo = -1; // Pilha vazia

int push(int valor) {
    if (topo >= MAX - 1) {   // Pilha cheia
        printf("ERRO: Pilha cheia!\n");
        return -1;
    }

    pilha[++topo] = valor;
    return topo;
}

int pop() {
    if (topo < 0) {   // Pilha vazia
        printf("ERRO: Pilha vazia!\n");
        return -1;
    }

    return pilha[topo--];
}

int peek() {
    if (topo < 0) {
        printf("Pilha vazia!\n");
        return -1;
    }

    return pilha[topo];
}

void imprime(){
	int i = 0;
	
	printf("-----\n");
	
		while(i <= MAX - 1){
			printf ("  %d\n", pilha[i]);
			i++;
		}
		
	printf("-----\n");
			
}

void inicializar() {
    topo = -1;
    memset(pilha, 0, sizeof(pilha));
}

int main() {
	
    int opcao = -1, valor;

    inicializar();

    while(opcao != 0)   // 0 é sair
    {
        printf("\n----------------------------------------\n");
        printf("  1. PUSH\n"); 
        printf("  2. POP (remove o ultimo adicionado) \n");
        printf("  3. PEEK (mostra o topo da pilha)\n");
        printf("  4. PRINT (mostra a pilha inteira)\n");
        printf("  0. SAIR\n");
        printf("----------------------------------------\n\n");
        printf("Escolha uma das opcoes: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                push(valor);
                break;

            case 2:
                valor = pop();
                if (valor != -1)
                    printf("Valor removido: %d\n", valor);
                break;

            case 3:
                valor = peek();
                if (valor != -1)
                    printf("Topo da pilha: %d\n", valor);
                break;

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
