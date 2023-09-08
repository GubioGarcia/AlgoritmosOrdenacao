#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InsertionSort (int array[], int tamanho) {
    for (int j = 1; j < tamanho; j++) {
        int key = array[j];
        int i = j - 1;

        while (i > -1 && array[i] > key) {
            array[i+1] = array[i];
            i = i - 1;
        }
        array[i + 1] = key;
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
    int tamanho = 5000;
    int array[tamanho];

    clock_t inicio, fim;
    double tempoDecorrido;

    vetorOriginalAleatorio (array, tamanho);

    // Inicio contador
    inicio = clock();

    InsertionSort (array, tamanho);

    // Fim contador
    fim = clock();

    tempoDecorrido = ((fim - inicio) / (double)CLOCKS_PER_SEC);

    vetorOrdenado (array, tamanho);

    printf("\nTEMPO DE ORDENACAO: %f", tempoDecorrido);
}