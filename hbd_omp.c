// Ejercicio#2- Paralela
// Esteban Aldana Guerra - 20591
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Por favor, especifique la cantidad de threads (su edad) como argumento.\n");
        return 1;
    }

    int threads = atoi(argv[1]);
    omp_set_num_threads(threads); // Seteamos la cantidad de threads.

#pragma omp parallel
    {
        int id = omp_get_thread_num();             // Obtenemos el ID del thread.
        int total_threads = omp_get_num_threads(); // Obtenemos el total de threads.

        if (id % 2 == 0)
        {
            printf("Saludos del hilo %d\n", id);
        }
        else
        {
            printf("Feliz cumpleaños número %d!\n", total_threads);
        }
    }

    return 0;
}
