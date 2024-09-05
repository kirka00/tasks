#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 1e-9  

double det(double **matrix, int n, int m) {
    if (n != m) {
        return NAN;  
    }
    double determinant = 1.0;
    for (int i = 0; i < n; i++) {
        if (fabs(matrix[i][i]) < EPSILON) {
            int swap_row = i + 1;
            while (swap_row < n && fabs(matrix[swap_row][i]) < EPSILON) {
                swap_row++;
            }
            if (swap_row == n) {
                return 0.0;  
            }
            double *temp = matrix[i];
            matrix[i] = matrix[swap_row];
            matrix[swap_row] = temp;
            determinant = -determinant;  
        }
        for (int j = i + 1; j < n; j++) {
            if (fabs(matrix[j][i]) > EPSILON) {
                double factor = matrix[j][i] / matrix[i][i];
                for (int k = i; k < n; k++) {
                    matrix[j][k] -= factor * matrix[i][k];
                }
            }
        }
        determinant *= matrix[i][i];
    }

    return determinant;
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

void output(double det) {
    if (isnan(det)) {
        printf("n/a");
    } else {
        printf("%.6lf", det);
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
    double determinant = det(matrix, n, m);
    output(determinant);
    free_matrix(matrix, n);
    return 0;
}
