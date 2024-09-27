#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(void **data, int first, int second) {
    void *temp = data[first];
    data[first] = data[second];
    data[second] = temp;
}

void quicksort(void **data, int first, int last, int (*compare)(void *, void *)) {
    if (first >= last) return;

    int lower = first + 1, upper = last;
    swap(data, first, (first + last) / 2);
    void *bound = data[first];

    while (lower <= upper) {
        while (lower <= upper && compare(data[lower], bound) <= 0) {
            lower++;
        }
        while (compare(data[upper], bound) > 0) {
            upper--;
        }
        if (lower < upper) {
            swap(data, lower++, upper--);  
        }
    }
    swap(data, upper, first); 

    if (first < upper - 1) quicksort(data, first, upper - 1, compare);
    if (upper + 1 < last) quicksort(data, upper + 1, last, compare);
}

// Función de quicksort principal
void quicksort_main(void **data, int length, int (*compare)(void *, void *)) {
    if (length < 2) return;

    int max = 0;

    for (int i = 1; i < length; i++) {
        if (compare(data[max], data[i]) < 0) {
            max = i;
        }
    }

    swap(data, length - 1, max);

    quicksort(data, 0, length - 2, compare);
}

int compareInt(void *a, void *b) {
    int int_a = *(int *)a;
    int int_b = *(int *)b;
    return (int_a > int_b) - (int_a < int_b);
}

// Función para imprimir el array de enteros

int main() {
    void *data[10];
    int n = sizeof(data) / sizeof(data[0]);
    int numero;
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        int *numero = malloc(sizeof(int));  // Reservar memoria para un entero
        *numero = rand() % 200 + 20;
        data[i] = numero;
    }

    printf("Array antes de ordenar: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(int *)data[i]);  // Desreferenciar y convertir el puntero a entero
    }

    quicksort_main(data, n, compareInt);

    printf("\nArray despues de ordenar: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(int *)data[i]);  // Desreferenciar y convertir el puntero a entero
    }

    return 0;
}
