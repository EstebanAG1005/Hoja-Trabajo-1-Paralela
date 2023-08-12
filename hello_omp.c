// Ejercicio#1- Paralela
// Esteban Aldana Guerra - 20591

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[])
{
    int N = 10; // valor por defecto

    if (argc > 1)
    {
        N = atoi(argv[1]); // convierte el argumento ingresado en un entero
    }

    omp_set_num_threads(N); // establece el número de threads a usar

#pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int total_threads = omp_get_num_threads();
        printf("Hello from thread %d of %d!\n", thread_id, total_threads);
    }

    return 0;
}
