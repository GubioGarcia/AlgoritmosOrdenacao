#include <iostream>
using namespace std;

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int metade(int *arr, int low, int high) {
    int pivot = arr[high];
    cout<<"Pivot: "<<pivot<<endl;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            troca(&arr[i], &arr[j]);
        }
    }
    troca(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int pi = metade(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int *arr, int n) {

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 1, 8, 9, 5, 7};
    int n = 6;

    cout << "Vetor original:" << endl;
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    std::cout << "Vetor ordenado:" << std::endl;
    printArray(arr, n);

    return 0;
}
