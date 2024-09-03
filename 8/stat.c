#include <stdio.h>
#include <stdlib.h> 
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);
void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == -1) {
        printf("n/a\n");
        return 0;
    }

    output(data, n);
    output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
    
    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) != 1 || *n < 1 || *n > NMAX) {
        return -1; 
    }
    
    // Читаем массив с проверкой корректности
    for (int i = 0; i < *n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            return -1; // Некорректный ввод элемента массива
        }
    }
    
    return 0; // Успешно
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int max(int *a, int n) {
    int max_v = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max_v) {
            max_v = a[i];
        }
    }
    return max_v;
}

int min(int *a, int n) {
    int min_v = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min_v) {
            min_v = a[i];
        }
    }
    return min_v;
}

double mean(int *a, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum / n;
}

double variance(int *a, int n) {
    double avg = mean(a, n);
    double sum_squared_diff = 0.0;
    for (int i = 0; i < n; i++) {
        sum_squared_diff += (a[i] - avg) * (a[i] - avg);
    }
    return sum_squared_diff / n;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d\n", max_v);
    printf("%d\n", min_v);
    printf("%.6f\n", mean_v);
    printf("%.6f\n", variance_v);
}