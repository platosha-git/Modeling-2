#include <cmath>

#include "gauss.h"
#include "gnuplot.h"

void fGauss(Gnuplot *plot, const float a, const float b, const float mu, const float sigma2)
{
    float sigma = sqrt(sigma2);

    for (float x = a; x <= b; x += 0.01) {
        float y = 1 / (sigma * sqrt(2 * M_PI)) * exp(-pow(x - mu, 2) / (2 * sigma2));
        (*plot)(x, y);
    }
}

void plotfGauss(const float mu, const float sigma2)
{
	Gnuplot plot;

    plot("set title 'Функция плотности распределения Гаусса'");
    
    string muStr = "{/Symbol m}=" + std::to_string(mu);
    string sigmaStr = "{/Symbol s}^2=" + std::to_string(sigma2);
    plot("set label '" + muStr + "' at 3,1");
    plot("set label '" + sigmaStr + "' at 3,0.9");
    
    plot("set xlabel 'x'");
    plot("set ylabel 'f(x)'");

    plot("set grid");
    plot("set yrange [-0.1:1.1]");

    plot("plot '-' using 1:2 notitle with lines");

    fGauss(&plot, -5, 5, mu, sigma2);
}

void FGauss(Gnuplot *plot, const float a, const float b, const float mu, const float sigma2)
{
    for (float x = a; x <= b; x += 0.01) {
        float y = (1 + erf((x - mu) / sqrt(2 * sigma2))) / 2;
        (*plot)(x, y);
    }
}

void plotFGauss(const float mu, const float sigma2)
{
    Gnuplot plot;

    plot("set title 'Функция распределения Гаусса'");

    string muStr = "{/Symbol m}=" + std::to_string(mu);
    string sigmaStr = "{/Symbol s}^2=" + std::to_string(sigma2);
    plot("set label '" + muStr + "' at 3,0.1");
    plot("set label '" + sigmaStr + "' at 3,0");
    
    plot("set xlabel 'x'");
    plot("set ylabel 'F(x)'");
    
    plot("set grid");
    plot("set yrange [-0.1:1.1]");
    
    plot("plot '-' using 1:2 notitle with lines");

    FGauss(&plot, -5, 5, mu, sigma2);
}