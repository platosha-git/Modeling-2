#include <cmath>

#include "poisson.h"
#include "gnuplot.h"

void FPoisson(Gnuplot *plot, const float lambda)
{
	for (int x = 0; x <= 20; x++) {
		float y = 0;
		for (int i = 0; i <= x; i++) {
			y += exp(-lambda) * pow(lambda, i) / tgamma(i + 1);
		}
		(*plot)(x, y);
	}
}

void fPoisson(Gnuplot *plot, const float lambda)
{
	for (int x = 0; x <= 20; x++) {
		float y = exp(-lambda) * pow(lambda, x) / tgamma(x + 1);
		(*plot)(x, y);
	}
}

void plotFPoisson(const float lambda)
{
	string lmbdStr = "{/Symbol l}=" + std::to_string(lambda);

	Gnuplot plot;
	plot.initF("Функция распределения Пуассона", lmbdStr);

	FPoisson(&plot, lambda);	
}

void plotfPoisson(const float lambda)
{
	string lmbdStr = "{/Symbol l}=" + std::to_string(lambda);

	Gnuplot plot;
	plot.initf("Функция плотности распределения Пуассона", lmbdStr);

	fPoisson(&plot, lambda);
}
