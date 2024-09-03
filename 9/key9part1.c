#include <stdio.h>

void input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int* buffer, int length, int number, int* numbers);

int main() {
    int length;
    int buffer[10]; 
    int even_sum;

    input(buffer, &length);
    even_sum = sum_numbers(buffer, length);

    if (even_sum == 0) {
        printf("n/a\n");
        return 0;  
    }

    int numbers[10]; 
    int new_length = find_numbers(buffer, length, even_sum, numbers);

    printf("%d\n", even_sum);
    output(numbers, new_length);

    return 0;
}

void input(int *buffer, int *length) {
    scanf("%d", length);
    if (*length < 1 || *length > 10) {
        *length = 0; 
        return;
    }
    for (int i = 0; i < *length; i++) {
        scanf("%d", &buffer[i]);
    }
}

void output(int *buffer, int length) {
    if (length == 0) {
        return;
    }
    for (int i = 0; i < length; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");
}

int sum_numbers(int *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) { 
            sum += buffer[i];
        }
    }

    return sum;
}

int find_numbers(int* buffer, int length, int number, int* numbers) {
    int new_length = 0;  

    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && number % buffer[i] == 0) {  
            numbers[new_length++] = buffer[i];  
        }
    }

    return new_length;  
}