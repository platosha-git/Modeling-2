#include <iostream>

#include "uniform.h"
#include "poisson.h"

using namespace std;

void inputInterval(float &a, float &b)
{
	cout << "Input interval:" << endl;
	
	cout << "a = ";
	cin >> a;

	cout << "b = ";
	cin >> b;
}

void inputParameters(float &lambda)
{
	cout << "Input parameter:" << endl;

	cout << "lambda = ";
	cin >> lambda;
}


int main()
{
//Uniform
	float a = 0, b = 0;
	inputInterval(a, b);

	plotFUniform(a, b);
	plotfUniform(a, b);

//Gauss
	float lambda = 0;
	inputParameters(lambda);

	plotFPoisson(lambda);
	plotfPoisson(lambda);   

	return 0;
}