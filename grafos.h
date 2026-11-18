// ============================================================
// grafos.h — Recorridos de grafos: BFS y DFS
//
// El grafo se representa con una LISTA DE ADYACENCIA:
// grafo[nodo] es la lista de sus vecinos. Por ejemplo:
//
//     grafo = { {1, 2}, {0, 3}, {0} }
//
// significa: el nodo 0 se conecta con 1 y 2, el 1 con 0 y 3,
// y el 2 solo con 0.
//
// Ambas búsquedas devuelven el ORDEN en que se visitan los
// nodos empezando desde "inicio" (así se pueden comprobar en
// las pruebas sin imprimir nada).
// ============================================================
#ifndef GRAFOS_H
#define GRAFOS_H

#include <vector>

#include "estructuras.h" // se reutiliza la Cola del proyecto

// ------------------------------------------------------------
// BFS — Búsqueda en anchura (Breadth-First Search)
//
// Visita primero el nodo de inicio, luego a TODOS sus vecinos,
// luego a los vecinos de los vecinos, y así sucesivamente:
// avanza "por capas", como las ondas de una piedra en el agua.
// Para lograrlo se usa una COLA: los nodos se visitan en el
// mismo orden en que se descubren. Complejidad: O(V + E).
// ------------------------------------------------------------
inline std::vector<int> busquedaBFS(
    const std::vector<std::vector<int>>& grafo, int inicio) {
    std::vector<int> orden;                          // resultado
    std::vector<bool> visitado(grafo.size(), false); // nadie visitado aún
    Cola<int> cola;

    visitado[inicio] = true;
    cola.encolar(inicio);

    while (!cola.vacia()) {
        int nodo = cola.desencolar();
        orden.push_back(nodo);
        // Sus vecinos aún no vistos pasan a la cola
        for (int vecino : grafo[nodo]) {
            if (!visitado[vecino]) {
                visitado[vecino] = true; // se marca AL ENCOLAR,
                cola.encolar(vecino);    // no al visitar: así nadie entra dos veces
            }
        }
    }
    return orden;
}

// ------------------------------------------------------------
// DFS — Búsqueda en profundidad (Depth-First Search)
//
// Avanza por un camino hasta el fondo antes de retroceder:
// entra en un vecino, luego en un vecino de ese vecino, y
// solo cuando no puede seguir, vuelve atrás (backtracking).
// Se implementa con RECURSIVIDAD: la pila de llamadas hace el
// papel de la pila de nodos pendientes. Complejidad: O(V + E).
// ------------------------------------------------------------
inline void dfsRecursivo(const std::vector<std::vector<int>>& grafo,
                         int nodo, std::vector<bool>& visitado,
                         std::vector<int>& orden) {
    visitado[nodo] = true;
    orden.push_back(nodo);
    for (int vecino : grafo[nodo]) {
        if (!visitado[vecino]) {
            dfsRecursivo(grafo, vecino, visitado, orden);
        }
    }
}

inline std::vector<int> busquedaDFS(
    const std::vector<std::vector<int>>& grafo, int inicio) {
    std::vector<int> orden;
    std::vector<bool> visitado(grafo.size(), false);
    dfsRecursivo(grafo, inicio, visitado, orden);
    return orden;
}

#endif // GRAFOS_H
