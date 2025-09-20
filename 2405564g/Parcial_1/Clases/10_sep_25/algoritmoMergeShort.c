#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

void merge(int A[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int A[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid + 1, right);
        merge(A, left, mid, right);
    }
}

void mostrarArray(int A[], int longitud) {
    for (int i = 0; i < longitud; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int A[100];
    int longitud=0;
    printf("ingrese el numero de elementos a ordenar (max 100), (uno por linea): ");
    scanf("%d", &longitud);

    printf("ingrese la cadena de numeros para ordenar:\n");
    for(int i = 0; i < longitud; i++) {
        scanf("%d", &A[i]);
        printf("Quedan %d numeros por ingresar\n", longitud -i - 1);
    }

    printf("Arreglo original: \n"); mostrarArray(A, longitud);

    mergeSort(A, 0, longitud - 1);

    printf("\nArreglo ordenado: \n"); mostrarArray(A, longitud);

    return 0;
}
