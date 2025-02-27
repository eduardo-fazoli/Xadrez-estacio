#include <stdio.h>

#define TAMANHO_TABULEIRO 9 //define o tamanho do tabuleiro


void tabuleiro(int x, int y) {
    for (int i = 1; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 1; j < TAMANHO_TABULEIRO; j++) {
            if (i == x && j == y) {
                printf("T ");   //torre
            } else {
                printf(". ");   //tabuleiro
            }
        }
        printf("\n");
    }
}

int main() {
    int x = 1, y = 1;  // Posição da torre
    int novoXtorre, novoYtorre; // posição para onde a torre vai ir 
    char continuar;
    int cont = 0;
    do {
        if(cont == 0){
            tabuleiro(x, y);
        }
        
        printf("digite a nova linha em que a torre vai estar (de 1 a 8): \n");
        scanf("%d", &novoXtorre);
        printf("digite a nova coluna em que a torre vai estar (de 1 a 8): \n");
        scanf("%d", &novoYtorre);
        
        // para verificar se o movimento é valido
        if (novoXtorre == x || novoYtorre == y) {   //limita o movimento da torre para somente em linha reta(ex: de 1 1 pra 1 4 // de 1 1 pra 4 1.)
            x = novoXtorre;
            y = novoYtorre;
        } else {
            printf("Movimento inválido! A torre só pode andar em linha reta!\n");
        }
        
        tabuleiro(x, y);
        printf("Deseja continuar? (s/n): "); //confirmação para se a pessoa quer terminar, S para continuar, qlqr outra tecla para terminar o programa
        scanf(" %c", &continuar);
        cont++;

    } while (continuar == 's' || continuar == 'S');
    
    return 0;
}


