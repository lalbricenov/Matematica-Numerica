#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<cs50.h>

const double h = 0.000000001;
typedef struct Trace{
    string nombre;
    int N;
    double *x;// Apuntador: posicion de memoria de la variable x
    double *y;
} Trace;

void printTrace(Trace trace)
{
    printf("Trace: %s\n", trace.nombre);
    printf("x\ty\n");
    for(int i = 0; i < trace.N; i++)
    {
        printf("%.3f\t%.3f\n", trace.x[i], trace.y[i]);
    }
}
void plot(string plotName, Trace *traces, int nTraces )
{
    if(nTraces > 0)
    {
        FILE *gnuplot = fopen(plotName, "w");
        fprintf(gnuplot, "set terminal png\n");
        fprintf(gnuplot, "set output \"%s.png\"\n", plotName);
        fprintf(gnuplot, "plot ");
        for (int n = 0; n < nTraces; n++)
        {
            fprintf(gnuplot, "'-' with lines linewidth 2 ");
            fprintf(gnuplot, "title \"%s\"", traces[n].nombre);

            if(n == nTraces -1) fprintf(gnuplot, "\n");
            else fprintf(gnuplot, ", ");
        }
        for (int n = 0; n < nTraces; n++)
        {
            for (int i = 0; i < traces[n].N; i++)
            {
                fprintf(gnuplot, "%g %g\n", traces[n].x[i], traces[n].y[i]);
            }
            fprintf(gnuplot, "e\n");
        }
        fclose(gnuplot);
        // fflush(gnuplot);
    }
}
double f(double x)
{
    return 2*pow(x,3)-pow(x,2);
}
double dF(double x)
{
    return (f(x+h) - f(x))/h;
}
int main(void)
{
    int N = 1000;
    double xMin, xMax, step;
    do
    {
        xMin = get_double("Ingrese el x minimo: ");
        xMax = get_double("Ingrese el x maximo: ");
    }while(xMin >= xMax);
    step = (xMax - xMin)/(N-1);
    double x[N];
    double y[N];
    double yP[N];
    double xVal = xMin;
    for(int n = 0; n < N; n++)
    {
        x[n] = xVal;
        y[n] = f(xVal);
        yP[n] = dF(xVal);
        xVal += step;
    }

    Trace func, derivada;
    func.nombre = "f(x)";
    derivada.nombre = "f'(x)";
    func.N = N;
    derivada.N = N;

    func.x = x;
    derivada.x = x;
    func.y = y;
    derivada.y = yP;
    // printTrace(func);
    // printTrace(derivada);
    Trace data[2] = {func, derivada};
    plot("Quarta", data, 2);
    printf("hola");
    // Trace derivada;
    // derivada.nombre = "Derivada";

    // printf("Derivada de x*x:\n");
    // system("python testPlot.py");
}