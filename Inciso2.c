//Ejecutar el programa usando:

// g++ -fopenmp Inciso2.c -o Inciso2
// ./Inciso2

#include <stdio.h>
#include <omp.h>

int main() {
    const int N = 1000000;  // Constante N definida como 1000000
    int sum = 0;
    double start_time, end_time;

    start_time = omp_get_wtime();  // Inicio de medición del tiempo

    // Ciclo for paralelo con reducción
    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i <= N; i++) {
        sum += i;
    }

    end_time = omp_get_wtime();  // Fin de medición del tiempo

    printf("El resultado de la suma es: %d\n", sum);
    printf("El tiempo del proceso es: %f segundos\n", end_time - start_time);

    return 0;
}
