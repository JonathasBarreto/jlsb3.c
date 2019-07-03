#include <stdlib.h>
#include <stdio.h>

int **inicializa_matriz(int tamanho);
void destroi_matriz(int **matriz, int tamanho);
void imprime_matriz(int **matriz, int tamanho);

int main() {
    
    int dimencao, i, j;
    printf("\nInforme as dimenções da matriz: \n");
    scanf("%d", &dimencao);
    printf("\nDimenções = %d", dimencao);
    printf("\n\n");
    int **m = inicializa_matriz(dimencao);
    printf("Informe os elementos abaixo: ");
    for (i=0; i<dimencao; i++ ){
  //      printf("\n\nInforme o tamanho da linha: \n");
        
        for ( j=0; j<dimencao; j++ ){
      printf ("\nElemento[%d][%d] = ", i, j);
      scanf ("%d", &m[ i ][ j ]);
      
        }
    }
    imprime_matriz(m, dimencao);
    destroi_matriz(m, dimencao);
    return 0;
}

int **inicializa_matriz(int tamanho) {
    int i;
    int **matriz = (int **) malloc(sizeof(int *) * tamanho);
    for(i = 0; i < tamanho; i++) {
        matriz[i] = (int *) malloc(sizeof(int) * tamanho);
    }
    return matriz;
}

void destroi_matriz(int **matriz, int tamanho) {
    int i;
    for(i = 0; i < tamanho; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void imprime_matriz(int **matriz, int tamanho) {
    int i, j;
    printf("\n\n---------MATRIZ---------\n\n");
    for(i = 0; i < tamanho; i++) {
        for(j = 0; j < tamanho; j++) {
            if(matriz[i][j] < 10){
                printf("|0%d|", matriz[i][j]);
                    
            }else{
                printf("|%d|", matriz[i][j]);
            }
        }
        printf("\n");
    }
}
