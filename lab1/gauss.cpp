#include <cmath>

#include "gauss.h"
#include "gnuplot.h"

void fGauss(Gnuplot *plot, const float a, const float b, const float mu, const float sigma)
{
    for (float x = a; x <= b; x += 0.01) {
        float y = 1 / (sigma * sqrt(2 * M_PI)) * exp(-pow(x - mu, 2) / (2 * pow(sigma, 2)));
        (*plot)(x, y);
    }
}

void plotfGauss(const float mu, const float sigma)
{
	Gnuplot plot;

    plot("set title 'Функция плотности распределения Гаусса'");
    
    plot("set xlabel 'x'");
    plot("set ylabel 'f(x)'");

    plot("set grid");
    plot("set yrange [-0.1:1.1]");

    plot("plot '-' using 1:2 notitle with lines");

    fGauss(&plot, -5, 5, mu, sigma);
}

void FGauss(Gnuplot *plot, const float a, const float b, const float mu, const float sigma)
{
    for (float x = a; x <= b; x += 0.01) {
        float y = (1 + erf((x - mu) / (sigma * sqrt(2)))) / 2;
        (*plot)(x, y);
    }
}

void plotFGauss(const float mu, const float sigma)
{
    Gnuplot plot;

    plot("set title 'Функция распределения Гаусса'");
    
    plot("set xlabel 'x'");
    plot("set ylabel 'F(x)'");
    
    plot("set grid");
    plot("set yrange [-0.1:1.1]");
    
    plot("plot '-' using 1:2 notitle with lines");

    FGauss(&plot, -5, 5, mu, sigma);
}