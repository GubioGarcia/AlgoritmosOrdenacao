#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Estrutura para representar uma aresta ponderada
struct Aresta {
    int origem, destino, peso;
};

// Função para comparar arestas com base em seus pesos
bool compararArestas(const Aresta& a, const Aresta& b) {
    return a.peso < b.peso;
}

// Função para encontrar o conjunto de um vértice
int encontrarConjunto(int vertice, vector<int>& conjuntos) {
    if (conjuntos[vertice] == -1)
        return vertice;
    return encontrarConjunto(conjuntos[vertice], conjuntos);
}

// Função para unir dois conjuntos
void unirConjuntos(int conjunto_origem, int conjunto_destino, vector<int>& conjuntos) {
    conjuntos[conjunto_origem] = conjunto_destino;
}

// Função principal para o algoritmo de Kruskal
vector<Aresta> kruskal(vector<Aresta>& arestas, int numVertices) {
    vector<Aresta> arvoreGeradoraMinima;
    vector<int> conjuntos(numVertices, -1);

    // Passo 1: Ordenar todas as arestas em ordem crescente
    sort(arestas.begin(), arestas.end(), compararArestas);

    // Passo 2: Iterar sobre as arestas ordenadas
    for (const auto& aresta : arestas) {
        int conjuntoOrigem = encontrarConjunto(aresta.origem, conjuntos);
        int conjuntoDestino = encontrarConjunto(aresta.destino, conjuntos);

        // Passo 3: Verificar se a adição da aresta forma um ciclo
        if (conjuntoOrigem != conjuntoDestino) {
            // Passo 4: Adicionar a aresta à árvore geradora mínima
            arvoreGeradoraMinima.push_back(aresta);

            // Passo 5: Unir os conjuntos dos vértices origem e destino
            unirConjuntos(conjuntoOrigem, conjuntoDestino, conjuntos);
        }
    }

    return arvoreGeradoraMinima;
}

int main() {
    // Número de vértices no grafo
    int numVertices;
    cout << "Digite o número de vértices: ";
    cin >> numVertices;

    // Número de arestas no grafo
    int numArestas;
    cout << "Digite o número de arestas: ";
    cin >> numArestas;

    // Leitura das arestas
    vector<Aresta> arestas(numArestas);
    cout << "Digite as arestas (origem destino peso):" << endl;
    for (int i = 0; i < numArestas; ++i) {
        cin >> arestas[i].origem >> arestas[i].destino >> arestas[i].peso;
    }

    // Chamar a função de Kruskal para obter a árvore geradora mínima
    vector<Aresta> arvoreGeradoraMinima = kruskal(arestas, numVertices);

    // Imprimir a árvore geradora mínima
    cout << "Arestas na árvore geradora mínima:" << endl;
    for (const auto& aresta : arvoreGeradoraMinima) {
        cout << aresta.origem << " - " << aresta.destino << " Peso: " << aresta.peso << endl;
    }

    return 0;
}
