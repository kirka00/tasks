#include <stdio.h>
#include <stdlib.h>

int input(int *a, int n);
void output(int *a, int n);
void sort(int *a, int n);

int main() {
    int n;

    // Считывание длины массива
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("n/a");
        return 0;
    }

    // Динамическое выделение памяти для массива
    int *data = (int *)malloc(n * sizeof(int));
    if (data == NULL) {
        printf("n/a");
        return 0;
    }

    // Считывание данных в массив
    if (input(data, n) == -1) {
        free(data);  // Освобождение памяти в случае ошибки
        printf("n/a");
        return 0;
    }

    sort(data, n);
    output(data, n);

    free(data);  // Освобождение памяти после использования
    return 0;
}

int input(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            return -1;
        }
    }
    return 0;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

void sort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}
