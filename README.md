# Algoritmos y Estructuras de Datos — C++

Colección de algoritmos y estructuras de datos clásicas en **C++17**,
con un programa de demostración interactivo por menú y **pruebas
automáticas**. Cada algoritmo está comentado paso a paso para poder
explicarlo en una entrevista.

## Características

- **3 algoritmos de ordenamiento** comentados con su complejidad.
- **2 algoritmos de búsqueda** (lineal y binaria).
- **3 estructuras de datos** propias: pila y cola como plantillas
  genéricas, y lista enlazada con punteros y gestión manual de memoria.
- **Recorridos de grafos**: BFS (en anchura) y DFS (en profundidad)
  sobre lista de adyacencia.
- **Programación dinámica**: Fibonacci con memoización y el problema
  de la mochila 0/1 con tabla.
- **Pruebas automáticas** con `assert` que verifican cada algoritmo,
  incluidas en el Makefile (`make test`) y en CMake (`ctest`).
- Dos formas de compilar: **Makefile** y **CMakeLists.txt**.

## Contenido

- **Ordenamientos** (`ordenamientos.h`)
  - Burbuja — O(n²), sencillo de entender.
  - Quicksort — divide y vencerás, O(n log n) en promedio.
  - Mergesort (por mezcla) — divide y vencerás, siempre O(n log n).
- **Búsquedas** (`busquedas.h`)
  - Lineal — sirve con cualquier vector, O(n).
  - Binaria — exige el vector ordenado, O(log n).
- **Estructuras de datos** (`estructuras.h`)
  - `Pila` (LIFO) y `Cola` (FIFO), como plantillas (`template`)
    reutilizables con cualquier tipo.
  - `ListaEnlazada` de enteros con nodos y punteros: insertar al
    frente y al final, buscar, eliminar y mostrar, con destructor
    que libera la memoria.
- **Grafos** (`grafos.h`)
  - BFS: recorre por capas usando una cola (reutiliza la `Cola`
    del propio proyecto).
  - DFS: recursivo, avanza hasta el fondo antes de retroceder.
  - Ambos devuelven el orden de visita, lo que permite probarlos.
- **Programación dinámica** (`dinamica.h`)
  - Fibonacci con memoización: de O(2^n) a O(n) guardando resultados.
  - Mochila 0/1: tabla `dp[i][c]` con el mejor valor por capacidad.

## Tecnologías

- **C++17** (compilador `g++` o compatible).
- **Make** y **CMake** como sistemas de compilación.
- Solo librería estándar: `vector`, `deque`, `cassert`, etc.

## Cómo compilarlo y ejecutarlo

Con Make:

```bash
make        # compila y genera el ejecutable ./algoritmos
make run    # compila y ejecuta directamente
./algoritmos
```

Con CMake:

```bash
cmake -S . -B build
cmake --build build
./build/algoritmos
```

Sin herramientas, también se puede compilar a mano:

```bash
g++ -std=c++17 -Wall -Wextra -O2 -o algoritmos main.cpp
./algoritmos
```

Al ejecutarlo aparece un menú: elige una opción (1-7) para ver cada
demostración y 0 para salir.

## Cómo correr las pruebas

```bash
make test               # con Make
# o con CMake:
cd build && ctest       # tras compilar con CMake
```

Las pruebas (`pruebas.cpp`) comprueban los ordenamientos (incluidos
casos borde: vacío, duplicados, negativos), las búsquedas, las tres
estructuras, el orden exacto de visita de BFS y DFS sobre un grafo de
ejemplo, Fibonacci hasta el término 50 y el caso clásico de la
mochila. Si todo está bien imprimen: «Todas las pruebas pasaron».

## Estructura del proyecto

```
algoritmos-cpp/
├── main.cpp          # programa principal: menú y demostraciones
├── ordenamientos.h   # burbuja, quicksort y mergesort
├── busquedas.h       # búsqueda lineal y binaria
├── estructuras.h     # Pila, Cola y ListaEnlazada
├── grafos.h          # recorridos BFS y DFS
├── dinamica.h        # fibonacci con memoización y mochila 0/1
├── pruebas.cpp       # pruebas automáticas con assert
├── Makefile          # make / run / test / clean
├── CMakeLists.txt    # compilación alternativa con CMake + ctest
└── README.md
```

## Qué practica este proyecto

- Complejidad algorítmica (notación O grande) aplicada a casos reales.
- **Divide y vencerás**: quicksort y mergesort, con sus diferencias
  (partición con pivote frente a mezcla de mitades ordenadas).
- Recursividad en varios sabores: quicksort, mergesort y DFS.
- **Programación dinámica**: memoización (de arriba hacia abajo) y
  tabulación (de abajo hacia arriba) en la mochila.
- Grafos con lista de adyacencia y recorridos BFS/DFS.
- Plantillas de clase (`template <typename T>`).
- Punteros y memoria dinámica (`new` / `delete`) en la lista enlazada.
- Organización de un proyecto C++ en varios archivos con cabeceras
  (`.h`) y guardas de inclusión, compilable con Make y con CMake.
- Verificación automática del código con pruebas basadas en `assert`.
