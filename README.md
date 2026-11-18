# Algoritmos y Estructuras de Datos — C++

Colección de algoritmos y estructuras de datos clásicas en **C++17**,
con un programa de demostración interactivo por menú. Cada algoritmo
está comentado paso a paso para poder explicarlo en una entrevista.

## Qué incluye

- **Ordenamientos** (`ordenamientos.h`)
  - Burbuja — O(n²), sencillo de entender.
  - Quicksort — divide y vencerás, O(n log n) en promedio.
- **Búsquedas** (`busquedas.h`)
  - Lineal — sirve con cualquier vector, O(n).
  - Binaria — exige el vector ordenado, O(log n).
- **Estructuras de datos** (`estructuras.h`)
  - `Pila` (LIFO) y `Cola` (FIFO), como plantillas (`template`)
    reutilizables con cualquier tipo.
  - `ListaEnlazada` de enteros con nodos y punteros: insertar al
    frente y al final, buscar, eliminar y mostrar, con destructor
    que libera la memoria.

## Cómo compilarlo y ejecutarlo

Requisitos: un compilador de C++ con soporte de C++17 (por ejemplo
`g++`) y `make`.

```bash
make        # compila y genera el ejecutable ./algoritmos
make run    # compila y ejecuta directamente
./algoritmos
```

Sin `make`, también se puede compilar a mano:

```bash
g++ -std=c++17 -Wall -Wextra -O2 -o algoritmos main.cpp
./algoritmos
```

Al ejecutarlo aparece un menú: elige una opción (1-5) para ver cada
demostración y 0 para salir.

## Estructura del proyecto

```
algoritmos-cpp/
├── main.cpp          # programa principal: menú y demostraciones
├── ordenamientos.h   # burbuja y quicksort
├── busquedas.h       # búsqueda lineal y binaria
├── estructuras.h     # Pila, Cola y ListaEnlazada
├── Makefile          # reglas de compilación (make / run / clean)
└── README.md
```

## Conceptos que practica este proyecto

- Complejidad algorítmica (notación O grande) aplicada a casos reales.
- Recursividad (quicksort) y partición con pivote.
- Plantillas de clase (`template <typename T>`).
- Punteros y memoria dinámica (`new` / `delete`) en la lista enlazada.
- Organización de un proyecto C++ en varios archivos con cabeceras
  (`.h`) y guardas de inclusión.
