#include <iostream>
#include "gnuplot.h"

using namespace std;

void inputInterval(int &a, int &b)
{
    cout << "Input interval:" << endl;
    
    cout << "a = ";
    cin >> a;

    cout << "b = ";
    cin >> b;
}

void plotfUniform(const int a, const int b)
{
    Gnuplot plot;

    plot("set title 'Функция плотности равномерного распределения'");
    
    plot("set xlabel 'x'");
    plot("set ylabel 'f(x)'");

    plot("set grid");
    plot("set yrange [-0.1:1.1]");

    plot("plot '-' using 1:2 notitle with lines");
    
    for (float i = a - 1; i < a; i += 0.01) {
        plot(i, 0);
    }

    for (float i = a; i < b; i += 0.01) {
        float x = i; 
        float y = 1.0 / (b - a);
        plot(x, y);
    }

    for (float i = b; i < b + 1; i += 0.01) {
        plot(i, 0);
    }
}

void plotFUniform(const int a, const int b)
{
    Gnuplot plot;

    plot("set title 'Функция равномерного распределения'");
    
    plot("set xlabel 'x'");
    plot("set ylabel 'F(x)'");
    
    plot("set grid");
    plot("set yrange [-0.1:1.1]");
    
    plot("plot '-' using 1:2 notitle with lines");
    
    for (float i = a - 1; i < a; i += 0.01) {
        plot(i, 0);
    }

    for (float i = a; i < b; i += 0.01) {
        float x = i; 
        float y = (i - a) / (b - a);
        plot(x, y);
    }

    for (float i = b; i < b + 1; i += 0.01) {
        plot(i, 1);
    }
}

int main()
{
    int a = 0, b = 0;
    inputInterval(a, b);

    plotFUniform(a, b);
    plotfUniform(a, b);

    return 0;
}