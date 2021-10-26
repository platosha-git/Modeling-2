#include <cmath>

#include "gauss.h"
#include "gnuplot.h"

void FGauss(Gnuplot *plot, const float a, const float b, const float mu, const float sigma2)
{
	for (float x = a; x <= b; x += 0.01) {
		float y = (1 + erf((x - mu) / sqrt(2 * sigma2))) / 2;
		(*plot)(x, y);
	}
}

void fGauss(Gnuplot *plot, const float a, const float b, const float mu, const float sigma2)
{
	float sigma = sqrt(sigma2);

	for (float x = a; x <= b; x += 0.01) {
		float y = 1 / (sigma * sqrt(2 * M_PI)) * exp(-pow(x - mu, 2) / (2 * sigma2));
		(*plot)(x, y);
	}
}

void plotFGauss(const float mu, const float sigma2)
{
	string muStr = "{/Symbol m}=" + std::to_string(mu);
	string sigmaStr = "{/Symbol s}^2=" + std::to_string(sigma2);

	Gnuplot plot;
	plot.initF("Функция распределения Гаусса", muStr, sigmaStr);

	FGauss(&plot, -5, 5, mu, sigma2);
}

void plotfGauss(const float mu, const float sigma2)
{
	string muStr = "{/Symbol m}=" + std::to_string(mu);
	string sigmaStr = "{/Symbol s}^2=" + std::to_string(sigma2);

	Gnuplot plot;
	plot.initf("Функция плотности распределения Гаусса", muStr, sigmaStr);

	fGauss(&plot, -5, 5, mu, sigma2);
}
