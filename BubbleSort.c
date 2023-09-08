#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort (int vetor[], int tam) {
    for (int fim = tam-1; fim > 0; fim--) {
        for (int i = 0; i < fim; i++) {
            if (vetor[i] > vetor[i+1]) {
                int aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
            }
        }
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
    int tamanho = 95000;
    int array[tamanho];

    clock_t inicio, fim;
    double tempoDecorrido;

    vetorOriginalAleatorio (array, tamanho);

    // Inicio contador
    inicio = clock();

    BubbleSort(array, tamanho);

    // Fim contador
    fim = clock();

    tempoDecorrido = ((fim - inicio) / (double)CLOCKS_PER_SEC);

    vetorOrdenado (array, tamanho);

    printf("\nTEMPO DE ORDENACAO: %f", tempoDecorrido);    
}