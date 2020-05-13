// Programa que implementa la integracion con sumas de Riemann. Rectangulos.
#include<stdio.h>
#include<math.h>
#include<cs50.h>

// Crear variable suma=0
// desde el primer rectangulo, calcular base*altura
// sumar este area a la suma
// repetir para el siguiente rectangulo

double f(double x)
{
    return pow(x,2);// x al cuadrado
}

int main(void)
{
    double suma = 0;
    int N = 10000000;
    // La integral va entre a y b
    double a = 0;
    double b = 1;
    double base = (b-a) / N;
    for(int i = 0; i < N; i++)
    {
        // base * altura
        suma =  suma + base * f(a + base * i);
    }
    printf("Integral: %.15f\n", suma);
}