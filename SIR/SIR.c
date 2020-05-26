// Programa que utiliza el modelo SIR para modelar una infeccion en una
// poblacion
#include <stdio.h>
#include <cs50.h>

double beta, gamma;
int N;

const double h = 0.1;

double dSdt(double S, double I, double R)
{
    return -beta * I * S / N;
}
double dIdt(double S, double I, double R)
{
    return beta * I * S / N - gamma * I;
}
double dRdt(double S, double I, double R)
{
    return gamma * I;
}

int main(void)
{
    beta = get_double("Ingrese beta: ");
    gamma = get_double("Ingrese gamma: ");
    N = get_int("Ingrese N: ");

    // avanzar al siguiente punto usando Runge Kutta
    // Calculo de K para todas las variables S, I, R
    double S = N - 1;
    double I = 1;
    double R = 0;
    for(int i = 0; i < 100; i++)
    {
         // k1
        double kI1, kS1, kR1;
        kS1 = h * dSdt(S, I, R);
        kI1 = h * dIdt(S, I, R);
        kR1 = h * dRdt(S, I, R);
        // k2
        double kI2, kS2, kR2;
        kS2 = h * dSdt(S + kS1/2, I + kI1/2, R + kR1/2);
        kI2 = h * dIdt(S + kS1/2, I + kI1/2, R + kR1/2);
        kR2 = h * dRdt(S + kS1/2, I + kI1/2, R + kR1/2);
        // k3
        double kI3, kS3, kR3;
        kS3 = h * dSdt(S + kS2/2, I + kI2/2, R + kR2/2);
        kI3 = h * dIdt(S + kS2/2, I + kI2/2, R + kR2/2);
        kR3 = h * dRdt(S + kS2/2, I + kI2/2, R + kR2/2);
        // k4
        double kI4, kS4, kR4;
        kS4 = h * dSdt(S + kS3, I + kI3, R + kR3);
        kI4 = h * dIdt(S + kS3, I + kI3, R + kR3);
        kR4 = h * dRdt(S + kS3, I + kI3, R + kR3);
        // Nuevos S, I, R
        S = S + (kS1 + 2*kS2 + 2*kS3 + kS4)/6;
        I = I + (kI1 + 2*kI2 + 2*kI3 + kI4)/6;
        R = R + (kR1 + 2*kR2 + 2*kR3 + kR4)/6;
        printf("%f\t%f\t%f\n", S, I, R);
    }
}