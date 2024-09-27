#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[],int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp =arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

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
void printArrayQuick(void **data, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", *(int *)data[i]);
    }
    printf("\n");
}

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;  
    j = 0;  
    k = left;  

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void printArrayMerge(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void burbuja1() {
    printf("------- Algoritmo burbuja ------\n");
    int arr[30];
    int n=sizeof(arr)/sizeof(arr[0]);
    int numero;
    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        numero=rand() % 200 + 20;
        arr[i]=numero;
    }

    bubbleSort(arr,n);

    printf("Arreglo ordenado: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }

}

void quicksort2() {
    printf("------ Algoritmo de quicksort ------\n");
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
}

void merge3() {
    printf("------ Algoritmo de merge ------\n");
    int arr[10];
    int n=sizeof(arr)/sizeof(arr[0]);
    int numero;
    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        numero=rand() % 200 + 20;
        arr[i]=numero;
    }

    printf("Array original: ");
    printArrayMerge(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("\nArray ordenado: ");
    printArrayMerge(arr, n);
}



int main() {
    int opcion;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Burbuja\n");
        printf("2. Quicksort\n");
        printf("3. Merge\n");
        printf("4. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                burbuja1();
                break;
            case 2:
                quicksort2();
                break;
            case 3:
                merge3();
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Inténtalo de nuevo.\n");
        }
    } while(opcion != 4);

    return 0;
}
