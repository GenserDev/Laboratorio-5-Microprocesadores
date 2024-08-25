#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 131072

// Funcion para contar apariciones de key en el arreglo usando descomposicion de tareas
long count_key_recursive(long *a, long start, long end, long key) {
    long count = 0;
    if (end - start <= 10000) { 
        for (long i = start; i < end; i++)
            if (a[i] == key) count++;
    } else {
        long mid = (start + end) / 2;
        #pragma omp task shared(count)
        {
            count += count_key_recursive(a, start, mid, key);
        }
        #pragma omp task shared(count)
        {
            count += count_key_recursive(a, mid, end, key);
        }
        #pragma omp taskwait
    }
    return count;
}

int main() {
    long a[N], key = 42, nkey = 0;
    
    // Inicializar el generador de numeros aleatorios 
    srand(0);  

    // Llenar el arreglo con valores aleatorios
    for (long i = 0; i < N; i++) a[i] = rand() % N;
    
    // Insertar el valor key en tres posiciones especificas
    a[N % 43] = key; 
    a[N % 73] = key; 
    a[N % 3] = key;
    
    // Contar las apariciones de key en el arreglo 
    #pragma omp parallel
    {
        #pragma omp single
        {
            nkey = count_key_recursive(a, 0, N, key);
        }
    }
    
    printf("Numero de veces que [key] aparece: %ld\n", nkey);

    return 0;
}
