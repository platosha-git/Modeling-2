#include <iostream>
#include "gnuplot.h"

int main()
{
    Gnuplot plot;

    plot("plot sin(x)");
    std::cin.get();

    plot("plot cos(x)");
    std::cin.get();
}