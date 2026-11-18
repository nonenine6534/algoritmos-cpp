// ============================================================
// estructuras.h — Estructuras de datos básicas
//
//   - Pila (stack): el último en entrar es el primero en
//     salir (LIFO). Plantilla: sirve para cualquier tipo.
//   - Cola (queue): el primero en entrar es el primero en
//     salir (FIFO). Plantilla: sirve para cualquier tipo.
//   - ListaEnlazada: nodos unidos por punteros, para int.
// ============================================================
#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include <vector>
#include <deque>
#include <stdexcept> // std::out_of_range
#include <iostream>

// ------------------------------------------------------------
// PILA (LIFO) — por dentro usa un vector como almacén
// ------------------------------------------------------------
template <typename T>
class Pila {
private:
    std::vector<T> datos;

public:
    // Mete un elemento en el tope de la pila
    void apilar(const T& valor) {
        datos.push_back(valor);
    }

    // Saca y devuelve el elemento del tope
    T desapilar() {
        if (vacia()) {
            throw std::out_of_range("La pila esta vacia");
        }
        T valor = datos.back();
        datos.pop_back();
        return valor;
    }

    // Mira el elemento del tope sin sacarlo
    T tope() const {
        if (vacia()) {
            throw std::out_of_range("La pila esta vacia");
        }
        return datos.back();
    }

    bool vacia() const { return datos.empty(); }
    std::size_t tamano() const { return datos.size(); }
};

// ------------------------------------------------------------
// COLA (FIFO) — por dentro usa una deque como almacén
// ------------------------------------------------------------
template <typename T>
class Cola {
private:
    std::deque<T> datos;

public:
    // Mete un elemento al final de la cola
    void encolar(const T& valor) {
        datos.push_back(valor);
    }

    // Saca y devuelve el elemento del frente
    T desencolar() {
        if (vacia()) {
            throw std::out_of_range("La cola esta vacia");
        }
        T valor = datos.front();
        datos.pop_front();
        return valor;
    }

    // Mira el elemento del frente sin sacarlo
    T frente() const {
        if (vacia()) {
            throw std::out_of_range("La cola esta vacia");
        }
        return datos.front();
    }

    bool vacia() const { return datos.empty(); }
    std::size_t tamano() const { return datos.size(); }
};

// ------------------------------------------------------------
// LISTA ENLAZADA simple (para enteros)
//
// Cada nodo guarda un valor y un puntero al siguiente nodo.
// La lista solo recuerda el primer nodo (la "cabeza"); para
// llegar a los demás hay que recorrer la cadena.
// ------------------------------------------------------------
class ListaEnlazada {
private:
    struct Nodo {
        int valor;
        Nodo* siguiente;
        Nodo(int v, Nodo* s) : valor(v), siguiente(s) {}
    };

    Nodo* cabeza = nullptr;

public:
    // El destructor libera la memoria de todos los nodos
    ~ListaEnlazada() { limpiar(); }

    // Inserta un nodo nuevo al principio (es O(1))
    void insertarAlFrente(int valor) {
        cabeza = new Nodo(valor, cabeza);
    }

    // Inserta un nodo nuevo al final (hay que recorrer: O(n))
    void insertarAlFinal(int valor) {
        Nodo* nuevo = new Nodo(valor, nullptr);
        if (cabeza == nullptr) {
            cabeza = nuevo;
            return;
        }
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }

    // Busca un valor recorriendo la lista
    bool buscar(int valor) const {
        for (Nodo* actual = cabeza; actual != nullptr; actual = actual->siguiente) {
            if (actual->valor == valor) {
                return true;
            }
        }
        return false;
    }

    // Elimina la primera aparición del valor.
    // Devuelve true si lo encontró y lo eliminó.
    bool eliminar(int valor) {
        Nodo* actual = cabeza;
        Nodo* anterior = nullptr;
        while (actual != nullptr && actual->valor != valor) {
            anterior = actual;
            actual = actual->siguiente;
        }
        if (actual == nullptr) {
            return false; // no estaba en la lista
        }
        if (anterior == nullptr) {
            cabeza = actual->siguiente; // se elimina la cabeza
        } else {
            anterior->siguiente = actual->siguiente;
        }
        delete actual;
        return true;
    }

    // Muestra la lista en el formato: 3 -> 7 -> 9 -> fin
    void mostrar() const {
        for (Nodo* actual = cabeza; actual != nullptr; actual = actual->siguiente) {
            std::cout << actual->valor << " -> ";
        }
        std::cout << "fin\n";
    }

    // Borra todos los nodos y deja la lista vacía
    void limpiar() {
        while (cabeza != nullptr) {
            Nodo* borrar = cabeza;
            cabeza = cabeza->siguiente;
            delete borrar;
        }
    }
};

#endif // ESTRUCTURAS_H
