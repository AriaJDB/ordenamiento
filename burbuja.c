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

int main(){
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

    //printf("\n%d",numero);

    return 0;
    //como generar números random
}