//Ejecutar el programa usando:

// g++ -fopenmp Inciso4.c -o Inciso4
// ./Inciso4

#include <stdio.h>
#include <omp.h>

int main() {
    int variable1 = 0;   // Variable compartida
    int variable2;       // Variable privada
    int i;

    //Directiva para usar Shares y Private
    #pragma omp parallel shared(variable1) private(variable2)
    {
        #pragma omp for
        for (i = 0; i < 10; ++i) {
            variable2 = i * 2;   // Modificación de variable2 (privada)
            variable1 += i;      // Modificación de variable1 (compartida)
            #pragma omp critical
            {
                printf("Hilo %d: variable 1 = %d, variable 2 = %d\n", omp_get_thread_num(), variable1, variable2);
            }
        }
    }

    return 0;
}
