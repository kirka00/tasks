#include <stdio.h>

void input(int *buffer, int *length, int *shift);
void output(int *buffer, int length);
void left_rotate(int *buffer, int length, int shift);
void right_rotate(int *buffer, int length, int shift);

int main() {
    int length;
    int buffer[10];  
    int shift;

    input(buffer, &length, &shift);
    if (length < 1 || length > 10) {
        printf("n/a\n");
        return 0; 
    }

    if (shift > 0) {
        left_rotate(buffer, length, shift);
    } else if (shift < 0) {
        right_rotate(buffer, length, -shift);
    }

    output(buffer, length);
    return 0;
}

void input(int *buffer, int *length, int *shift) {
    printf("Enter the length of the array (max 10): ");
    scanf("%d", length);
    if (*length < 1 || *length > 10) {
        *length = 0;
        return;
    }
    printf("Enter %d integers:\n", *length);
    for (int i = 0; i < *length; i++) {
        scanf("%d", &buffer[i]);
    }
    printf("Enter the shift value (can be negative): ");
    scanf("%d", shift);
}

void output(int *buffer, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");
}

void left_rotate(int *buffer, int length, int shift) {
    shift = shift % length; 
    if (shift < 0) return;
    int temp[10];
    for (int i = 0; i < length; i++) {
        temp[i] = buffer[(i + shift) % length];
    }
    for (int i = 0; i < length; i++) {
        buffer[i] = temp[i];
    }
}

void right_rotate(int *buffer, int length, int shift) {
    shift = shift % length;  
    if (shift < 0) return; 
    int temp[10];
    for (int i = 0; i < length; i++) {
        temp[i] = buffer[(i - shift + length) % length];
    }
    for (int i = 0; i < length; i++) {
        buffer[i] = temp[i];
    }
}