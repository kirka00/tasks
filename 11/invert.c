#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 1e-9  

void invert(double **matrix, int n, int m) {
    if (n != m) {
        printf("n/a");
        return;
    }
    double **augmented = (double **)malloc(n * sizeof(double *));
    if (augmented == NULL) {
        printf("n/a");
        return;
    }
    for (int i = 0; i < n; i++) {
        augmented[i] = (double *)malloc(2 * n * sizeof(double));
        if (augmented[i] == NULL) {
            printf("n/a");
            return;
        }
        for (int j = 0; j < n; j++) {
            augmented[i][j] = matrix[i][j];        
            augmented[i][j + n] = (i == j) ? 1.0 : 0.0;  
        }
    }

    for (int i = 0; i < n; i++) {
        if (fabs(augmented[i][i]) < EPSILON) {
            int swap_row = i + 1;
            while (swap_row < n && fabs(augmented[swap_row][i]) < EPSILON) {
                swap_row++;
            }
            if (swap_row == n) {
                printf("n/a");  
                return;
            }
            double *temp = augmented[i];
            augmented[i] = augmented[swap_row];
            augmented[swap_row] = temp;
        }
        double pivot = augmented[i][i];
        if (fabs(pivot) < EPSILON) {
            printf("n/a");
            return;
        }
        for (int j = 0; j < 2 * n; j++) {
            augmented[i][j] /= pivot;
        }
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = augmented[k][i];
                for (int j = 0; j < 2 * n; j++) {
                    augmented[k][j] -= factor * augmented[i][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = augmented[i][j + n];
        }
    }
    for (int i = 0; i < n; i++) {
        free(augmented[i]);
    }
    free(augmented);
}

void input(double ***matrix, int *n, int *m) {
    if (scanf("%d %d", n, m) != 2 || *n <= 0 || *m <= 0) {
        printf("n/a");
        exit(1);
    }
    *matrix = (double **)malloc(*n * sizeof(double *));
    if (*matrix == NULL) {
        printf("n/a");
        exit(1);
    }
    for (int i = 0; i < *n; i++) {
        (*matrix)[i] = (double *)malloc(*m * sizeof(double));
        if ((*matrix)[i] == NULL) {
            printf("n/a");
            exit(1);
        }
        for (int j = 0; j < *m; j++) {
            if (scanf("%lf", &(*matrix)[i][j]) != 1) {
                printf("n/a");
                exit(1);
            }
        }
    }
}

void output(double **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j > 0) {
                printf(" ");
            }
            printf("%.6lf", matrix[i][j]);
        }
        if (i != n - 1) {
            printf("\n");
        }
    }
}

void free_matrix(double **matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    double **matrix;
    int n, m;
    input(&matrix, &n, &m);
    invert(matrix, n, m);
    if (n == m) {
        output(matrix, n, m);
    }
    free_matrix(matrix, n);
    return 0;
}
