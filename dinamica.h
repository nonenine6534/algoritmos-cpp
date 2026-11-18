// ============================================================
// dinamica.h — Programación dinámica (PD)
//
// La idea de la programación dinámica: si un problema se
// resuelve combinando problemas más pequeños que se REPITEN,
// se guarda cada resultado pequeño una sola vez y se reutiliza.
// Dos ejemplos clásicos:
//
//   - Fibonacci con memoización: sin guardar resultados, la
//     recursión tarda O(2^n) porque recalcula lo mismo miles
//     de veces; con una tabla (memo) baja a O(n).
//   - Mochila 0/1: decidir qué objetos meter en una mochila de
//     capacidad limitada para maximizar el valor. Cada objeto
//     se mete entero o no se mete (de ahí el "0/1").
// ============================================================
#ifndef DINAMICA_H
#define DINAMICA_H

#include <vector>
#include <algorithm> // std::max

// ------------------------------------------------------------
// Fibonacci con memoización (de arriba hacia abajo)
//
// La tabla "memo" guarda -1 en lo no calculado todavía. Antes
// de calcular fib(n) se mira la tabla: si ya está, se devuelve
// sin recalcular. fib(0) = 0, fib(1) = 1.
// Con long long se puede llegar hasta fib(92) sin desbordar.
// ------------------------------------------------------------
inline long long fibMemoRecursivo(int n, std::vector<long long>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n]; // ya calculado: se reutiliza
    memo[n] = fibMemoRecursivo(n - 1, memo) + fibMemoRecursivo(n - 2, memo);
    return memo[n];
}

inline long long fibonacciMemo(int n) {
    std::vector<long long> memo(n + 1, -1);
    return fibMemoRecursivo(n, memo);
}

// ------------------------------------------------------------
// Mochila 0/1 (de abajo hacia arriba, con tabla)
//
// Se construye una tabla dp[i][c] = valor máximo usando solo
// los primeros i objetos y una capacidad c. Para cada objeto
// hay dos opciones y se toma la mejor:
//   - NO meterlo: el valor es dp[i-1][c] (el de antes).
//   - Meterlo (si cabe): su valor + dp[i-1][c - peso].
// La respuesta final está en dp[n][capacidad].
// Complejidad: O(n * capacidad).
// ------------------------------------------------------------
inline int mochila01(const std::vector<int>& pesos,
                     const std::vector<int>& valores,
                     int capacidad) {
    int n = static_cast<int>(pesos.size());
    // Tabla de (n+1) x (capacidad+1), llena de ceros
    std::vector<std::vector<int>> dp(n + 1,
                                     std::vector<int>(capacidad + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int c = 0; c <= capacidad; c++) {
            dp[i][c] = dp[i - 1][c]; // opción 1: no meter el objeto i
            int peso = pesos[i - 1];
            if (peso <= c) {         // opción 2: meterlo, si cabe
                int conObjeto = valores[i - 1] + dp[i - 1][c - peso];
                dp[i][c] = std::max(dp[i][c], conObjeto);
            }
        }
    }
    return dp[n][capacidad];
}

#endif // DINAMICA_H
