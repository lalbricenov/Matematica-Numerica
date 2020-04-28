// Programa que implementa el metodo de biseccion
#include <stdio.h>
#include <cs50.h>
#include <math.h>

double f(double x){
    return pow(x,2)-2;
}

int main(void)
{
    // Escoger valores iniciales de xA y xB

    // buscar el punto medio: xC = (xA + xB)/2

    // Si ya llegue a la solucion detenerme
    // Si no:
        // revisar cual intervalo descartar:
        // Si f(xC) tiene el mismo signo que f(xA): descartar el intervalo ( xA,  xC)
        // en otro caso: descartar el intervalo (xC, xB)
    // Volver a la linea 13

    double xA = 0;
    double xB = 5;
    double xC;
    double tolerancia = 0.00001;
    int pasosMax = 10000;
    int nPasos = 0;
    while(1)// 1 corresponde a verdadero siempre
    {
        xC = (xA + xB) / 2;
        if( fabs(f(xC)) < tolerancia)
        {
            printf("La solucion es: %f\n", xC);
            break;
        }
        if(nPasos >= pasosMax){
            printf("No se encontro solucion despues de %d pasos.\n", nPasos);
            break;
        }
        printf("%f\t%f\t%f\t%f\n",xA, xB, xC, f(xC) );
        // Si f(xC) tiene el mismo signo que f(xA): descartar el intervalo ( xA,  xC)
        if( f(xC) * f(xA) > 0)
        {
            xA = xC;
        }
        else
        {
            xB = xC;
        }
        nPasos++;
    }
}