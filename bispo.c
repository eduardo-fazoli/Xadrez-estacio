#include <stdio.h>

#define TAMANHO_TABULEIRO 9 //define o tamanho do tabuleiro


void tabuleiro(int x, int y) {
    for (int i = 1; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 1; j < TAMANHO_TABULEIRO; j++) {
            if (i == x && j == y) {
                printf("B "); 
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

//validar se o movimento do bispo vai ser na diagonal usando a diferença, ele so pode mover nas casas aonde a diferença da coluna e linha seja igual da casa que ele esta
//por exemplo de 1 1 (0) para 2 2(0), ele nao consiguiria ir para 2 1(1) ou para 4 1(3)
int valido(int xatualbispo, int yatualbispo, int xnovobispo, int ynovobispo) {
    int diferencaxbispo = xnovobispo - xatualbispo;
    int diferencaybispo = ynovobispo - yatualbispo;
    
    if (diferencaxbispo == diferencaybispo || diferencaxbispo == -diferencaybispo) {
        return 1;
    } else {
        return 0;
    }
    }


int main() {


    int x = 1, y = 3;  // Posição do bispo
    int xnovobispo, ynovobispo; // posição para onde o bispo vai ir
    char continuar;
    int cont = 0;
    do {
        if(cont == 0){
        tabuleiro(x, y);
        cont++;
        }

        printf("digite a nova linha em que a bispo vai estar (de 1 a 8): \n");
        scanf("%d", &xnovobispo);
        printf("digite a nova coluna em que a bispo vai estar (de 1 a 8): \n");
        scanf("%d", &ynovobispo);
        
        // verifica se o movimento é válido
        if (x - y == xnovobispo - ynovobispo || x + y == xnovobispo + ynovobispo) {
            x = xnovobispo;
            y = ynovobispo;

        } else {
            printf("Movimento inválido! o bispo só pode se mover na diagonal!\n");
        }
        
        tabuleiro(x, y);
        printf("Deseja continuar? (s/n): "); //S para continuar N ou qlqr outra tecla para finalizar o jogo.
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');
    return 0;
}


