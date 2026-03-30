#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>

#define ROWS 100
#define COLS 100

void matrix_multiplication(int first[100][100], int second[100][100], int result[100][100]) {

    int i, k, j;

    #pragma omp parallel for private(j, k)
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j< COLS; j++) {
            int dot_product = 0;
            for (k = 0; k < COLS; k++) {
                dot_product += first[i][k] * second[k][j];
            }
            result[i][j] = dot_product;
        }
    }
}

void print_matrix(int mat[100][100], int limit) {
    printf("Printing the first %d x %d elements:\n", limit, limit);
    for (int i = 0; i < limit; i++) {
        for (int j = 0; j < limit; j++) {
            printf("%4d ", mat[i][j]);
        }
        printf("\n");
    }
}



int main(int argc, char *argv[]) {
    int a[100][100];
    int b[100][100];
    int result[100][100];

    for (int i = 0; i<100; i++) {
        for (int j = 0; j < 100; j++) {
            a[i][j] = 1;
            b[i][j] = 1;
            result[i][j] = 0;
        }
    }

    matrix_multiplication(a, b, result);
    print_matrix(result, 100);
}