#include <iostream>

#include "uniform.h"
#include "gauss.h"

using namespace std;

void inputInterval(float &a, float &b)
{
	cout << "Input interval:" << endl;
	
	cout << "a = ";
	cin >> a;

	cout << "b = ";
	cin >> b;
}

void inputParameters(float &mu, float &sigma2)
{
	cout << "Input parameters:" << endl;

	cout << "mu = ";
	cin >> mu;

	cout << "sigma^2 = ";
	cin >> sigma2;
}


int main()
{
//Uniform
	float a = 0, b = 0;
	inputInterval(a, b);

	plotFUniform(a, b);
	plotfUniform(a, b);

//Gauss
	float mu = 0, sigma2 = 0;
	inputParameters(mu, sigma2);

	plotFGauss(mu, sigma2);
	plotfGauss(mu, sigma2);   

	return 0;
}