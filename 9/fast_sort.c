#include <stdio.h>
#define NMAX 10

int input(int *a, int n);
void output(int *a, int n);
void quicksort(int *a, int left, int right);
void heapsort(int *a, int n);
void heapify(int *a, int n, int i);

int main() {
    int data[NMAX];
    int n = 10;
    if (input(data, n) == -1) {
        printf("n/a\n");
        return 0;
    }
    
    int quick_data[NMAX];
    for (int i = 0; i < n; i++) quick_data[i] = data[i];
    quicksort(quick_data, 0, n - 1);
    output(quick_data, n);

    int heap_data[NMAX];
    for (int i = 0; i < n; i++) heap_data[i] = data[i];
    heapsort(heap_data, n);
    output(heap_data, n);

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
    printf("\n");
}

void quicksort(int *a, int left, int right) {
    if (left < right) {
        int pivot = a[right];
        int i = left - 1;
        for (int j = left; j < right; j++) {
            if (a[j] <= pivot) {
                i++;
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        int temp = a[i + 1];
        a[i + 1] = a[right];
        a[right] = temp;
        int pivot_index = i + 1;

        quicksort(a, left, pivot_index - 1);
        quicksort(a, pivot_index + 1, right);
    }
}

void heapsort(int *a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
    }
}

void heapify(int *a, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest]) {
        largest = left;
    }
    if (right < n && a[right] > a[largest]) {
        largest = right;
    }
    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a, n, largest);
    }
}