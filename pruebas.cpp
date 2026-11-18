// ============================================================
// pruebas.cpp — Pruebas automáticas con assert
//
// Comprueba que los algoritmos y estructuras del proyecto
// devuelven lo esperado. Si alguna comprobación falla, el
// programa se detiene en esa línea y muestra un error; si
// todo va bien, termina imprimiendo "Todas las pruebas pasaron".
//
// Compilar y ejecutar:
//   make test
//   o a mano: g++ -std=c++17 -o pruebas pruebas.cpp && ./pruebas
//
// OJO: assert se desactiva si se compila con -DNDEBUG; por eso
// el Makefile y CMake compilan este archivo sin esa opción.
// ============================================================

#include <cassert>
#include <iostream>
#include <vector>

#include "ordenamientos.h"
#include "busquedas.h"
#include "estructuras.h"
#include "grafos.h"
#include "dinamica.h"

// Grafo de ejemplo usado en las pruebas de BFS y DFS:
//
//     0 se conecta con 1 y 2
//     1 se conecta con 0, 3 y 4
//     2 se conecta con 0 y 5
//     3 se conecta con 1
//     4 se conecta con 1 y 5
//     5 se conecta con 2 y 4
//
// Lista de adyacencia (cada nodo con sus vecinos):
static const std::vector<std::vector<int>> GRAFO = {
    {1, 2},    // 0
    {0, 3, 4}, // 1
    {0, 5},    // 2
    {1},       // 3
    {1, 5},    // 4
    {2, 4},    // 5
};

void probarOrdenamientos() {
    const std::vector<int> esperado = {1, 2, 3, 5, 7, 8, 9};

    std::vector<int> a = {8, 3, 9, 1, 7, 2, 5};
    ordenamientoBurbuja(a);
    assert(a == esperado);

    std::vector<int> b = {8, 3, 9, 1, 7, 2, 5};
    ordenamientoQuicksort(b);
    assert(b == esperado);

    std::vector<int> c = {8, 3, 9, 1, 7, 2, 5};
    ordenamientoMezcla(c);
    assert(c == esperado);

    // Casos borde: vacío, un elemento, duplicados y negativos
    std::vector<int> vacio;
    ordenamientoMezcla(vacio);
    assert(vacio.empty());

    std::vector<int> uno = {42};
    ordenamientoQuicksort(uno);
    assert((uno == std::vector<int>{42}));

    std::vector<int> repetidos = {4, -1, 4, 0, -1};
    ordenamientoBurbuja(repetidos);
    assert((repetidos == std::vector<int>{-1, -1, 0, 4, 4}));

    std::cout << "  ordenamientos (burbuja, quicksort, mergesort) OK\n";
}

void probarBusquedas() {
    const std::vector<int> datos = {2, 5, 8, 12, 16, 23, 38, 45};
    assert(busquedaLineal(datos, 23) == 5);
    assert(busquedaBinaria(datos, 23) == 5);
    assert(busquedaBinaria(datos, 2) == 0);   // primer elemento
    assert(busquedaBinaria(datos, 45) == 7);  // último elemento
    assert(busquedaLineal(datos, 100) == -1); // no está
    assert(busquedaBinaria(datos, 100) == -1);
    std::cout << "  busquedas (lineal y binaria) OK\n";
}

void probarEstructuras() {
    // Pila: sale en orden inverso al que entró (LIFO)
    Pila<int> pila;
    pila.apilar(10);
    pila.apilar(20);
    pila.apilar(30);
    assert(pila.tamano() == 3);
    assert(pila.tope() == 30);
    assert(pila.desapilar() == 30);
    assert(pila.desapilar() == 20);
    assert(!pila.vacia());

    // Cola: sale en el mismo orden en que entró (FIFO)
    Cola<int> cola;
    cola.encolar(1);
    cola.encolar(2);
    cola.encolar(3);
    assert(cola.frente() == 1);
    assert(cola.desencolar() == 1);
    assert(cola.desencolar() == 2);
    assert(cola.tamano() == 1);

    // Lista enlazada: insertar, buscar y eliminar
    ListaEnlazada lista;
    lista.insertarAlFinal(3);
    lista.insertarAlFinal(7);
    lista.insertarAlFrente(1);
    assert(lista.buscar(7));
    assert(!lista.buscar(4));
    assert(lista.eliminar(7));
    assert(!lista.buscar(7));
    assert(!lista.eliminar(99)); // eliminar algo que no está

    std::cout << "  estructuras (pila, cola, lista enlazada) OK\n";
}

void probarGrafos() {
    // BFS desde 0: por capas -> 0, sus vecinos 1 y 2, luego 3, 4 y 5
    std::vector<int> bfs = busquedaBFS(GRAFO, 0);
    assert((bfs == std::vector<int>{0, 1, 2, 3, 4, 5}));

    // DFS desde 0: se hunde por un camino -> 0, 1, 3, 4, 5, 2
    std::vector<int> dfs = busquedaDFS(GRAFO, 0);
    assert((dfs == std::vector<int>{0, 1, 3, 4, 5, 2}));

    std::cout << "  grafos (BFS y DFS) OK\n";
}

void probarDinamica() {
    assert(fibonacciMemo(0) == 0);
    assert(fibonacciMemo(1) == 1);
    assert(fibonacciMemo(10) == 55);
    assert(fibonacciMemo(20) == 6765);
    assert(fibonacciMemo(50) == 12586269025LL); // imposible sin memo en tiempo razonable

    // Mochila clásica: objetos (peso, valor) = (1,1) (3,4) (4,5) (5,7),
    // capacidad 7 -> lo mejor es meter los de peso 3 y 4: valor 4 + 5 = 9
    int mejor = mochila01({1, 3, 4, 5}, {1, 4, 5, 7}, 7);
    assert(mejor == 9);
    // Sin capacidad no cabe nada
    assert(mochila01({2, 3}, {3, 4}, 0) == 0);

    std::cout << "  programacion dinamica (fibonacci y mochila 0/1) OK\n";
}

int main() {
    std::cout << "Ejecutando pruebas...\n";
    probarOrdenamientos();
    probarBusquedas();
    probarEstructuras();
    probarGrafos();
    probarDinamica();
    std::cout << "Todas las pruebas pasaron.\n";
    return 0;
}
