#include <stdio.h>
#include <math.h>

#define MAX_NUMBERS 30

// Функции для обработки данных
int input(int *array, int *size);
double calculate_mean(int *array, int size);
double calculate_variance(int *array, int size, double mean);
int find_valid_number(int *array, int size, double mean, double variance);

int main() {
    int numbers[MAX_NUMBERS];
    int size;

    // Чтение входных данных
    if (input(numbers, &size) == -1) {
        printf("n/a\n");
        return 0;
    }

    // Вычисление средней и дисперсии
    double mean = calculate_mean(numbers, size);
    double variance = calculate_variance(numbers, size, mean);

    // Поиск подходящего числа
    int result = find_valid_number(numbers, size, mean, variance);
    printf("%d\n", result);
    
    return 0;
}

// Функция для ввода данных
int input(int *array, int *size) {
    if (scanf("%d", size) != 1 || *size < 1 || *size > MAX_NUMBERS) {
        return -1; // Некорректный ввод
    }
    
    for (int i = 0; i < *size; i++) {
        if (scanf("%d", &array[i]) != 1) {
            return -1; // Некорректный ввод
        }
    }
    return 0; // Успех
}

// Функция для вычисления среднего
double calculate_mean(int *array, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}

// Функция для вычисления дисперсии
double calculate_variance(int *array, int size, double mean) {
    double sum_squared_diff = 0.0;
    for (int i = 0; i < size; i++) {
        sum_squared_diff += (array[i] - mean) * (array[i] - mean);
    }
    return sum_squared_diff / size; // Обратите внимание, что эта формула не для выборочного, а для генерального момента
}

// Функция для поиска подходящего числа
int find_valid_number(int *array, int size, double mean, double variance) {
    double threshold = mean + 3 * sqrt(variance); // Три сигма
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 0 &&           // Четное
            array[i] >= mean &&           // >= mean
            array[i] <= threshold &&       // <= mean + 3 * std_dev
            array[i] != 0) {               // Не равно нулю
            return array[i];               // Вернуть подходящее число
        }
    }
    return 0; // Если ничего не найдено
}