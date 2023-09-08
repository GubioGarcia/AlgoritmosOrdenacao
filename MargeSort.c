#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge (int array[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int leftArray[n1], rightArray[n2];

    for (int i = 0; i < n1; i++) leftArray[i] = array[left + i];
    for (int j = 0; j < n2; j++) rightArray[j] = array[middle + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort (int array[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        merge(array, left, middle, right);
    }
}

void vetorOriginalAleatorio (int array[], int tamanho) {
    // Preenchendo o array com numeros aleatorios
    srand(time(NULL));
    for (int x = 0; x < tamanho; x++) {
        array[x] = rand() % 100;
    }

    // Impressao vetor aleatorio
    printf("\nVETOR ORIGINAL: ");
    for (int j = 0; j < tamanho; j++) printf("%d ", array[j]);
}

void vetorOrdenado (int array[], int tamanho) {
    // Impressao do vetor ordenado
    printf("\n\nVETOR ORDENADO: ");
    for (int j = 0; j < tamanho; j++) printf("%d ", array[j]);
}

int main () {
    int tamanho = 9500;
    int array[tamanho];

    clock_t inicio, fim;
    double tempoDecorrido;

    vetorOriginalAleatorio(array, tamanho);

    // Inicio contador
    inicio = clock();

    mergeSort(array, 0, tamanho - 1);

    // Fim contador
    fim = clock();

    tempoDecorrido = ((double)(fim - inicio) / CLOCKS_PER_SEC);

    vetorOrdenado(array, tamanho);

    printf("\nTempo de Ordenacao: %f", tempoDecorrido);

    return 0;
}