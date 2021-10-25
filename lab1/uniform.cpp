#include "uniform.h"
#include "gnuplot.h"

void fUniform(Gnuplot *plot, const float a, const float b)
{
    for (float i = a - 1; i < a; i += 0.01) {
        (*plot)(i, 0);
    }

    for (float i = a; i < b; i += 0.01) {
        float x = i; 
        float y = 1.0 / (b - a);
        (*plot)(x, y);
    }

    for (float i = b; i < b + 1; i += 0.01) {
        (*plot)(i, 0);
    }
}

void plotfUniform(const float a, const float b)
{
    Gnuplot plot;

    plot("set title 'Функция плотности равномерного распределения'");

    string aStr = "a=" + std::to_string(a);
    string bStr = "b=" + std::to_string(b);
    plot("set label '" + aStr + "' at 3.2,1");
    plot("set label '" + bStr + "' at 3.2,0.9");
    
    plot("set xlabel 'x'");
    plot("set ylabel 'f(x)'");

    plot("set grid");
    plot("set yrange [-0.1:1.1]");

    plot("plot '-' using 1:2 notitle with lines");

    fUniform(&plot, a, b);
}

void FUniform(Gnuplot *plot, const float a, const float b)
{
    for (float x = a - 1; x < a; x += 0.01) {
        (*plot)(x, 0);
    }

    for (float x = a; x < b; x += 0.01) {
        float y = (x - a) / (b - a);
        (*plot)(x, y);
    }

    for (float x = b; x < b + 1; x += 0.01) {
        (*plot)(x, 1);
    }
}

void plotFUniform(const float a, const float b)
{
    Gnuplot plot;

    plot("set title 'Функция равномерного распределения'");

    string aStr = "a=" + std::to_string(a);
    string bStr = "b=" + std::to_string(b);
    plot("set label '" + aStr + "' at 3.2,0.1");
    plot("set label '" + bStr + "' at 3.2,0");
    
    plot("set xlabel 'x'");
    plot("set ylabel 'F(x)'");
    
    plot("set grid");
    plot("set yrange [-0.1:1.1]");
    
    plot("plot '-' using 1:2 notitle with lines");

    FUniform(&plot, a, b);
}