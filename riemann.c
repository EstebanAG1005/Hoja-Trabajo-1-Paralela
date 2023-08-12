// Ejercicio#6- Paralela
// Esteban Aldana Guerra - 20591

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Función para integrar x^2
double f1(double x)
{
    return x * x;
}

// Función para integrar 2x^3
double f2(double x)
{
    return 2 * x * x * x;
}

// Función para integrar sin(x)
double f3(double x)
{
    return sin(x);
}

// Función que implementa la regla del trapezoide
double trapezoides(double (*func)(double), double a, double b, int n)
{
    // Calcula el tamaño de paso
    double h = (b - a) / n;

    // Inicializa el resultado con los valores de los extremos
    double result = 0.5 * (func(a) + func(b));

    // Suma las áreas de los trapezoides
    for (int i = 1; i < n; i++)
    {
        result += func(a + i * h);
    }

    // Multiplica por el tamaño de paso para obtener la suma total
    result *= h;

    return result;
}

int main(int argc, char **argv)
{
    // Verifica que se haya proporcionado el número correcto de argumentos
    if (argc != 3)
    {
        printf("Usage: %s <a> <b>\n", argv[0]);
        return 1;
    }

    // Convierte los argumentos de línea de comando a valores numéricos
    double a = atof(argv[1]);
    double b = atof(argv[2]);

    // Define el número de trapezoides
    int n = 10000000; // 10e6

    // Imprime los resultados de las integraciones
    printf("Con n = %d trapezides, nuestra aproximacion de la integral de %lf a %lf de x^2 es %lf\n",
           n, a, b, trapezoides(f1, a, b, n));
    printf("Con n = %d trapezides, nuestra aproximacion de la integral de %lf a %lf de 2x^3 es %lf\n",
           n, a, b, trapezoides(f2, a, b, n));
    printf("Con n = %d trapezides, nuestra aproximacion de la integral de %lf a %lf de sin(x) es %lf\n",
           n, a, b, trapezoides(f3, a, b, n));

    return 0;
}
