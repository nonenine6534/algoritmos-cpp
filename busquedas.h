// ============================================================
// busquedas.h — Algoritmos de búsqueda sobre vector<int>
//
// Ambas funciones devuelven la posición del elemento buscado,
// o -1 si no se encuentra.
//   - Búsqueda lineal: sirve con cualquier vector, O(n).
//   - Búsqueda binaria: exige el vector ORDENADO, O(log n).
// ============================================================
#ifndef BUSQUEDAS_H
#define BUSQUEDAS_H

#include <vector>

// Búsqueda lineal:
// Recorre el vector elemento a elemento hasta encontrar el
// valor. Es la búsqueda más sencilla que existe.
inline int busquedaLineal(const std::vector<int>& v, int valor) {
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (v[i] == valor) {
            return i;
        }
    }
    return -1;
}

// Búsqueda binaria:
// En cada paso mira el elemento del centro y descarta la
// mitad donde el valor no puede estar. Por eso el vector
// tiene que estar ordenado previamente.
inline int busquedaBinaria(const std::vector<int>& v, int valor) {
    int bajo = 0;
    int alto = static_cast<int>(v.size()) - 1;

    while (bajo <= alto) {
        int medio = bajo + (alto - bajo) / 2; // así se evita desbordar int
        if (v[medio] == valor) {
            return medio;
        } else if (v[medio] < valor) {
            bajo = medio + 1;  // el valor está en la mitad derecha
        } else {
            alto = medio - 1;  // el valor está en la mitad izquierda
        }
    }
    return -1;
}

#endif // BUSQUEDAS_H
