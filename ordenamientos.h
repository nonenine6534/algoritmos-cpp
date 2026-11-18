// ============================================================
// ordenamientos.h — Algoritmos de ordenamiento sobre vector<int>
//
//   - Ordenamiento burbuja: sencillo de entender, O(n^2).
//   - Quicksort: divide y vencerás, O(n log n) en promedio.
//   - Ordenamiento por mezcla (mergesort): divide y vencerás,
//     siempre O(n log n); usa un vector auxiliar de memoria.
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

// ------------------------------------------------------------
// Ordenamiento por mezcla (mergesort)
//
// Idea: partir el vector en dos mitades, ordenar cada mitad
// (recursivamente) y después MEZCLAR las dos mitades ya
// ordenadas en una sola pasada. Mezclar dos listas ordenadas
// es fácil: en cada paso se toma el menor de los dos frentes.
// ------------------------------------------------------------

// Mezcla v[bajo..medio] y v[medio+1..alto], que ya están
// ordenadas por separado, dejándolas ordenadas en v[bajo..alto].
// Se apoya en un vector auxiliar para no perder datos.
inline void mezclar(std::vector<int>& v, int bajo, int medio, int alto) {
    std::vector<int> auxiliar;
    auxiliar.reserve(alto - bajo + 1);

    int i = bajo;       // recorre la mitad izquierda
    int j = medio + 1;  // recorre la mitad derecha
    while (i <= medio && j <= alto) {
        if (v[i] <= v[j]) {
            auxiliar.push_back(v[i++]);
        } else {
            auxiliar.push_back(v[j++]);
        }
    }
    // Copia lo que quede de la mitad que no se agotó
    while (i <= medio) auxiliar.push_back(v[i++]);
    while (j <= alto) auxiliar.push_back(v[j++]);

    // Vuelca el resultado mezclado sobre el vector original
    for (int k = 0; k < static_cast<int>(auxiliar.size()); k++) {
        v[bajo + k] = auxiliar[k];
    }
}

// Parte recursiva: divide el rango [bajo, alto] en dos mitades
inline void mergesortRecursivo(std::vector<int>& v, int bajo, int alto) {
    if (bajo >= alto) return; // 0 o 1 elemento: ya está ordenado
    int medio = bajo + (alto - bajo) / 2;
    mergesortRecursivo(v, bajo, medio);
    mergesortRecursivo(v, medio + 1, alto);
    mezclar(v, bajo, medio, alto);
}

// Mergesort: función cómoda que se llama con solo el vector
inline void ordenamientoMezcla(std::vector<int>& v) {
    if (!v.empty()) {
        mergesortRecursivo(v, 0, static_cast<int>(v.size()) - 1);
    }
}

#endif // ORDENAMIENTOS_H
