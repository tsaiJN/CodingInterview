#include<stdio.h>
#include<stdlib.h>

void printMatrix(int** matrix, int N) {
    int x, y;
    for (x=0; x<N; x++) {
        for (y=0; y<N; y++){
            printf("%d ", matrix[x][y]);
        }
        printf("\n");
    }
}

void rotate90(int** matrix, int N) {
    int layer = 0;
    for (layer=0; layer < N/2; layer++) {
        int start = layer;
        int end = N - 1 - layer;
        int x;
        for (x=start; x<end; x++) {
            int temp = matrix[layer][x];
            matrix[layer][x] = matrix[N-x-1][layer];
            matrix[N-x-1][layer] = matrix[end][N-x-1];
            matrix[end][N-x-1] = matrix[x][end];
            matrix[x][end] = temp;
        }
    }
}


int main() {
    int matrix[5][5] = {{1,2,3,4,5},
                        {6,7,8,9,10},
                        {11,12,13,14,15},
                        {16,17,18,19,20},
                        {21,22,23,24,25}};
    int** intermedia;
    int i=0;
    for (i=0; i<5; i++) {
        intermedia[i] = matrix[i];
    }

    printMatrix(intermedia, 5);
    rotate90(intermedia, 5);
    printf("\n\n");
    printMatrix(intermedia, 5);
    return 0;
}

