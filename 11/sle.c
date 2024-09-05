#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 1e-9  

int sle(double **matrix, int n, int m, double *roots) {
    if (n + 1 != m) {
        return 0;  
    }
    for (int i = 0; i < n; i++) {
        if (fabs(matrix[i][i]) < EPSILON) {
            int swap_row = i + 1;
            while (swap_row < n && fabs(matrix[swap_row][i]) < EPSILON) {
                swap_row++;
            }
            if (swap_row == n) {
                return 0;  
            }
            double *temp = matrix[i];
            matrix[i] = matrix[swap_row];
            matrix[swap_row] = temp;
        }
        double pivot = matrix[i][i];
        for (int j = i; j < m; j++) {
            matrix[i][j] /= pivot;
        }
        for (int k = i + 1; k < n; k++) {
            double factor = matrix[k][i];
            for (int j = i; j < m; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        roots[i] = matrix[i][n];  
        for (int j = i + 1; j < n; j++) {
            roots[i] -= matrix[i][j] * roots[j];
        }
        if (fabs(matrix[i][i]) < EPSILON) {
            return 0;  
        }
    }
    return 1; 
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

void output_roots(double *roots, int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%.6lf", roots[i]);
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
    double *roots;
    int n, m;
    input(&matrix, &n, &m);
    roots = (double *)malloc(n * sizeof(double));
    if (roots == NULL) {
        printf("n/a");
        free_matrix(matrix, n);
        exit(1);
    }
    if (sle(matrix, n, m, roots)) {
        output_roots(roots, n);  
    } else {
        printf("n/a");  
    }
    free(roots);
    free_matrix(matrix, n);
    return 0;
}
