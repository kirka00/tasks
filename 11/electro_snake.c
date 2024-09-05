#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void input(int ***matrix, int *n, int *m) {
    if (scanf("%d %d", n, m) != 2 || *n <= 0 || *m <= 0) {
        printf("n/a");
        exit(1);
    }
    *matrix = (int **)malloc(*n * sizeof(int *));
    if (*matrix == NULL) {
        printf("n/a");
        exit(1);
    }
    for (int i = 0; i < *n; i++) {
        (*matrix)[i] = (int *)malloc(*m * sizeof(int));
        if ((*matrix)[i] == NULL) {
            printf("n/a");
            exit(1);
        }
        for (int j = 0; j < *m; j++) {
            if (scanf("%d", &(*matrix)[i][j]) != 1) {
                printf("n/a");
                exit(1);
            }
        }
    }
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j != 0) {
                printf(" ");
            }
            printf("%d", matrix[j][i]);
        }
        if (i != n - 1) {
            printf("\n");
        }
    }
}

void sort_vertical(int **matrix, int n, int m, int **result_matrix) {
    int *temp = (int *)malloc(n * m * sizeof(int));
    if (temp == NULL) {
        printf("n/a");
        exit(1);
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[k++] = matrix[i][j];
        }
    }
    qsort(temp, n * m, sizeof(int), cmp);
    k = 0;
    for (int j = 0; j < m; j++) {
        if (j % 2 == 0) {
            for (int i = 0; i < n; i++) {
                result_matrix[i][j] = temp[k++];
            }
        } else {
            for (int i = n - 1; i >= 0; i--) {
                result_matrix[i][j] = temp[k++];
            }
        }
    }
    free(temp);
}

void sort_horizontal(int **matrix, int n, int m, int **result_matrix) {
    int *temp = (int *)malloc(n * m * sizeof(int));
    if (temp == NULL) {
        printf("n/a");
        exit(1);
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[k++] = matrix[i][j];
        }
    }
    qsort(temp, n * m, sizeof(int), cmp);
    k = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; j++) {
                result_matrix[i][j] = temp[k++];
            }
        } else {
            for (int j = m - 1; j >= 0; j--) {
                result_matrix[i][j] = temp[k++];
            }
        }
    }
    free(temp);
}

void free_matrix(int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int **matrix, **result;
    int n, m;
    int flag = 0;
    input(&matrix, &n, &m);
    result = (int **)malloc(n * sizeof(int *));
    if (result == NULL) {
        printf("n/a");
        flag = 0;
    }
    for (int i = 0; i < n; i++) {
        result[i] = (int *)malloc(m * sizeof(int));
        if (result[i] == NULL) {
            printf("n/a");
            flag = 0;
        }
    }
    sort_horizontal(matrix, n, m, result);
    output(result, n, m);
    printf("\n\n");
    sort_vertical(matrix, n, m, result);
    output(result, n, m);
    free_matrix(matrix, n);
    free_matrix(result, n);
    return flag;
}
