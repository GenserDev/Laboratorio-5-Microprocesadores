//Ejecutar el programa usando:

// g++ -fopenmp Inciso3.c -o Inciso3
// ./Inciso3

#include <stdio.h>
#include <omp.h>

// Función para calcular el factorial
void factorial() {
    int n = 10;  // Valor para calcular el factorial
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    printf("Factorial de %d es %llu\n", n, result);
}

// Función para generar la serie de Fibonacci hasta un número
void fibonacci() {
    int n = 100;  // Valor para la serie de Fibonacci
    int a = 0, b = 1, c;
    printf("Serie de Fibonacci hasta %d: ", n);
    while (a <= n) {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
}

// Función para encontrar el valor máximo en un arreglo
void max_in_array() {
    int arr[] = {5,2,8,2,54,276,2545,26,436,5438};  // Valores del arreglo
    int size = sizeof(arr) / sizeof(arr[0]);
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("El valor maximo en el arreglo es %d\n", max);
}

int main() {
    #pragma omp parallel
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                factorial();
            }
            #pragma omp section
            {
                fibonacci();
            }
            #pragma omp section
            {
                max_in_array();
            }
        }

        // Sincronización para asegurar que todas las secciones se impriman en orden
        #pragma omp barrier
    }

    return 0;
}
