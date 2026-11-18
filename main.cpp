// ============================================================
// Algoritmos y estructuras de datos en C++
//
// Programa de demostración con menú interactivo:
//   1. Ordenamientos (burbuja, quicksort y mergesort)
//   2. Búsquedas (lineal y binaria)
//   3. Pila (LIFO)
//   4. Cola (FIFO)
//   5. Lista enlazada
//   6. Grafos (recorridos BFS y DFS)
//   7. Programación dinámica (fibonacci y mochila 0/1)
//
// Compilar:  make          (o bien: g++ -std=c++17 -o algoritmos main.cpp)
// Ejecutar:  ./algoritmos
// Pruebas:   make test     (ejecuta pruebas.cpp con assert)
// ============================================================

#include <iostream>
#include <vector>

#include "ordenamientos.h"
#include "busquedas.h"
#include "estructuras.h"
#include "grafos.h"
#include "dinamica.h"

// Imprime un vector en el formato: [8, 3, 9, 1]
void imprimirVector(const std::vector<int>& v) {
    std::cout << "[";
    for (std::size_t i = 0; i < v.size(); i++) {
        if (i > 0) std::cout << ", ";
        std::cout << v[i];
    }
    std::cout << "]\n";
}

// ---------- Demostración 1: ordenamientos ----------
void demoOrdenamientos() {
    std::vector<int> datos = {8, 3, 9, 1, 7, 2, 5};

    std::cout << "\n--- Ordenamientos ---\n";
    std::cout << "Vector original:  ";
    imprimirVector(datos);

    std::vector<int> conBurbuja = datos;
    ordenamientoBurbuja(conBurbuja);
    std::cout << "Con burbuja:      ";
    imprimirVector(conBurbuja);

    std::vector<int> conQuicksort = datos;
    ordenamientoQuicksort(conQuicksort);
    std::cout << "Con quicksort:    ";
    imprimirVector(conQuicksort);

    std::vector<int> conMezcla = datos;
    ordenamientoMezcla(conMezcla);
    std::cout << "Con mergesort:    ";
    imprimirVector(conMezcla);
}

// ---------- Demostración 2: búsquedas ----------
void demoBusquedas() {
    std::vector<int> datos = {2, 5, 8, 12, 16, 23, 38, 45}; // ya ordenado
    int buscado = 23;

    std::cout << "\n--- Busquedas ---\n";
    std::cout << "Vector (ordenado): ";
    imprimirVector(datos);

    int posLineal = busquedaLineal(datos, buscado);
    std::cout << "Lineal: el " << buscado << " esta en la posicion " << posLineal << "\n";

    int posBinaria = busquedaBinaria(datos, buscado);
    std::cout << "Binaria: el " << buscado << " esta en la posicion " << posBinaria << "\n";

    int ausente = busquedaBinaria(datos, 100);
    std::cout << "Binaria: el 100 devuelve " << ausente << " (no encontrado)\n";
}

// ---------- Demostración 3: pila ----------
void demoPila() {
    std::cout << "\n--- Pila (LIFO: ultimo en entrar, primero en salir) ---\n";
    Pila<int> pila;
    pila.apilar(10);
    pila.apilar(20);
    pila.apilar(30);
    std::cout << "Apile 10, 20 y 30. Tamano: " << pila.tamano() << "\n";
    std::cout << "Tope: " << pila.tope() << "\n";
    std::cout << "Desapilo: " << pila.desapilar() << "\n";
    std::cout << "Desapilo: " << pila.desapilar() << "\n";
    std::cout << "Queda en el tope: " << pila.tope() << "\n";
}

// ---------- Demostración 4: cola ----------
void demoCola() {
    std::cout << "\n--- Cola (FIFO: primero en entrar, primero en salir) ---\n";
    Cola<std::string> cola;
    cola.encolar("Ana");
    cola.encolar("Luis");
    cola.encolar("Marta");
    std::cout << "Encole a Ana, Luis y Marta. Tamano: " << cola.tamano() << "\n";
    std::cout << "Frente: " << cola.frente() << "\n";
    std::cout << "Atiendo (desencolo) a: " << cola.desencolar() << "\n";
    std::cout << "Ahora el frente es: " << cola.frente() << "\n";
}

// ---------- Demostración 5: lista enlazada ----------
void demoLista() {
    std::cout << "\n--- Lista enlazada ---\n";
    ListaEnlazada lista;
    lista.insertarAlFinal(3);
    lista.insertarAlFinal(7);
    lista.insertarAlFinal(9);
    lista.insertarAlFrente(1);
    std::cout << "Lista: ";
    lista.mostrar();
    std::cout << "Buscar 7: " << (lista.buscar(7) ? "encontrado" : "no esta") << "\n";
    std::cout << "Buscar 4: " << (lista.buscar(4) ? "encontrado" : "no esta") << "\n";
    lista.eliminar(7);
    std::cout << "Tras eliminar el 7: ";
    lista.mostrar();
}

// ---------- Demostración 6: recorridos de grafos ----------
void demoGrafos() {
    // Mismo grafo de ejemplo que usan las pruebas:
    // 0 se conecta con 1 y 2; 1 con 0, 3 y 4; 2 con 0 y 5;
    // 3 solo con 1; 4 con 1 y 5; 5 con 2 y 4.
    const std::vector<std::vector<int>> grafo = {
        {1, 2}, {0, 3, 4}, {0, 5}, {1}, {1, 5}, {2, 4},
    };

    std::cout << "\n--- Grafos: recorridos desde el nodo 0 ---\n";
    std::cout << "BFS (en anchura, por capas):  ";
    imprimirVector(busquedaBFS(grafo, 0));
    std::cout << "DFS (en profundidad, al fondo): ";
    imprimirVector(busquedaDFS(grafo, 0));
}

// ---------- Demostración 7: programación dinámica ----------
void demoDinamica() {
    std::cout << "\n--- Programacion dinamica ---\n";
    std::cout << "fibonacciMemo(20) = " << fibonacciMemo(20)
              << " (con memoizacion es instantaneo)\n";
    std::cout << "fibonacciMemo(50) = " << fibonacciMemo(50)
              << " (sin guardar resultados tardaria siglos)\n";

    // Mochila: objetos (peso, valor), capacidad 7
    int mejor = mochila01({1, 3, 4, 5}, {1, 4, 5, 7}, 7);
    std::cout << "Mochila 0/1 (capacidad 7): valor maximo = " << mejor
              << " (objetos de peso 3 y 4)\n";
}

// ---------- Programa principal: menú ----------
int main() {
    int opcion = -1;

    while (opcion != 0) {
        std::cout << "\n=====================================\n";
        std::cout << "  ALGORITMOS Y ESTRUCTURAS EN C++\n";
        std::cout << "=====================================\n";
        std::cout << "1. Ordenamientos (burbuja, quicksort y mergesort)\n";
        std::cout << "2. Busquedas (lineal y binaria)\n";
        std::cout << "3. Pila\n";
        std::cout << "4. Cola\n";
        std::cout << "5. Lista enlazada\n";
        std::cout << "6. Grafos (BFS y DFS)\n";
        std::cout << "7. Programacion dinamica\n";
        std::cout << "0. Salir\n";
        std::cout << "Elige una opcion: ";

        if (!(std::cin >> opcion)) {
            // Si el usuario escribe algo que no es un número,
            // limpiamos el error y salimos para no ciclar.
            std::cout << "Entrada no valida. Adios.\n";
            return 0;
        }

        switch (opcion) {
            case 1: demoOrdenamientos(); break;
            case 2: demoBusquedas(); break;
            case 3: demoPila(); break;
            case 4: demoCola(); break;
            case 5: demoLista(); break;
            case 6: demoGrafos(); break;
            case 7: demoDinamica(); break;
            case 0: std::cout << "Adios.\n"; break;
            default: std::cout << "Opcion no valida, intentalo de nuevo.\n"; break;
        }
    }

    return 0;
}
