#include <stdio.h>
#include <stdlib.h> // Para malloc y free

// Función para fusionar dos sub-arreglos de arr[]
// El primer sub-arreglo es arr[l..m]
// El segundo sub-arreglo es arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Crear arreglos temporales
    int L[n1], R[n2];

    // Copiar datos a los arreglos temporales L[] y R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // --- Inicia la fusión ---
    i = 0; // Índice inicial del primer sub-arreglo
    j = 0; // Índice inicial del segundo sub-arreglo
    k = l; // Índice inicial del arreglo fusionado (en el arreglo original)

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

    // Copiar los elementos restantes de L[], si hay alguno
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[], si hay alguno
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Función principal de mergeSort que ordena arr[l..r]
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Encuentra el punto medio para evitar desbordamiento (overflow)
        int m = l + (r - l) / 2;

        // Ordena la primera y la segunda mitad
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Fusiona las mitades ordenadas
        merge(arr, l, m, r);
    }
}

// Función de utilidad para imprimir un arreglo
void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// Función principal para probar el algoritmo
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Arreglo original: \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nArreglo ordenado: \n");
    printArray(arr, arr_size);
    return 0;
}