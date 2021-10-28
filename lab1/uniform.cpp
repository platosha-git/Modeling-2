#include "uniform.h"
#include "gnuplot.h"

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

void fUniform(Gnuplot *plot, const float a, const float b)
{
	for (float i = a - 1; i < a; i += 0.01) {
		(*plot)(i, 0);
	}

	for (float i = a; i <= b; i += 0.01) {
		float x = i; 
		float y = 1.0 / (b - a);
		(*plot)(x, y);
	}

	for (float i = b + 0.01; i < b + 1; i += 0.01) {
		(*plot)(i, 0);
	}
}

void plotFUniform(const float a, const float b)
{
	string aStr = "a=" + std::to_string(a);
	string bStr = "b=" + std::to_string(b);

	Gnuplot plot;
	plot.initF("Функция равномерного распределения", aStr, bStr);

	FUniform(&plot, a, b);
}

void plotfUniform(const float a, const float b)
{
	string aStr = "a=" + std::to_string(a);
	string bStr = "b=" + std::to_string(b);

	Gnuplot plot;
	plot.initf("Функция плотности равномерного распределения", aStr, bStr);

	fUniform(&plot, a, b);
}
