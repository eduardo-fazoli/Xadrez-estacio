#include <stdio.h>

#define TAMANHO_TABULEIRO 9 //define o tamanho do tabuleiro


void tabuleiro(int x, int y) {
    for (int i = 1; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 1; j < TAMANHO_TABULEIRO; j++) {
            if (i == x && j == y) {
                printf("R "); 
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

//usa o mesmo codigo que o bispo para identificar se o movimento vai ser na diagonal
int valido(int xatualrainha, int yatualrainha, int xnovorainha, int ynovorainha) {
    int diferencaxrainha = xnovorainha - xatualrainha;
    int diferencayrainha = ynovorainha - yatualrainha;
    
    if (diferencaxrainha == diferencayrainha || diferencaxrainha == -diferencayrainha) {
        return 1;
    } else {
        return 0;
    }
    }
//rainha

int main() {

//rainha
    int x = 1, y = 4;  // Posição da rainha
    int xnovorainha, ynovorainha; // posição para onde a rainha vai ir
    char continuar;
    int cont = 0;
    do {
        if(cont == 0){
        tabuleiro(x, y);
        cont++;
        }

        printf("Digite a nova linha em que a rainha vai estar (de 1 a 8): \n");
        scanf("%d", &xnovorainha);
        printf("Digite a nova coluna em que a rainha vai estar (de 1 a 8): \n");
        scanf("%d", &ynovorainha);
    
        if (x - y == xnovorainha - ynovorainha || x + y == xnovorainha + ynovorainha || (xnovorainha == x || ynovorainha == y)) { 
            x = xnovorainha;
            y = ynovorainha;
  //ele junta os movimentos da torre(linha reta) com os movimentos do bispo(diagonal)

        } else {
            printf("Movimento inválido! a rainha não pode se mover para lá!\n");
        }

        tabuleiro(x, y);
        printf("Deseja continuar? (s/n): ");//S para continuar N ou qlqr outra tecla para sair 
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');
    return 0;
}


