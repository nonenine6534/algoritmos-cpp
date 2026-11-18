// ============================================================
// ordenamientos.h — Algoritmos de ordenamiento sobre vector<int>
//
//   - Ordenamiento burbuja: sencillo de entender, O(n^2).
//   - Quicksort: divide y vencerás, O(n log n) en promedio.
// ============================================================
#ifndef ORDENAMIENTOS_H
#define ORDENAMIENTOS_H

#include <vector>
#include <algorithm> // std::swap

// Ordenamiento burbuja:
// Compara cada par de vecinos y los intercambia si están en
// desorden. Tras cada pasada completa, el mayor elemento
// "flota" hasta el final, como una burbuja.
inline void ordenamientoBurbuja(std::vector<int>& v) {
    int n = static_cast<int>(v.size());
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                std::swap(v[j], v[j + 1]);
            }
        }
    }
}

// Partición de quicksort: coloca el pivote (último elemento)
// en su posición final, dejando a su izquierda los menores
// y a su derecha los mayores. Devuelve la posición del pivote.
inline int particionQuicksort(std::vector<int>& v, int bajo, int alto) {
    int pivote = v[alto];
    int i = bajo - 1; // último elemento ya confirmado como "menor"
    for (int j = bajo; j < alto; j++) {
        if (v[j] <= pivote) {
            i++;
            std::swap(v[i], v[j]);
        }
    }
    std::swap(v[i + 1], v[alto]);
    return i + 1;
}

// Parte recursiva: ordena cada mitad por separado
inline void quicksortRecursivo(std::vector<int>& v, int bajo, int alto) {
    if (bajo < alto) {
        int p = particionQuicksort(v, bajo, alto);
        quicksortRecursivo(v, bajo, p - 1);
        quicksortRecursivo(v, p + 1, alto);
    }
}

// Quicksort: función cómoda que se llama con solo el vector
inline void ordenamientoQuicksort(std::vector<int>& v) {
    if (!v.empty()) {
        quicksortRecursivo(v, 0, static_cast<int>(v.size()) - 1);
    }
}

#endif // ORDENAMIENTOS_H
