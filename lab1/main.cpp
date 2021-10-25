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

void inputParameters(float &mu, float &sigma)
{
    cout << "Input parameters:" << endl;

    cout << "mu = ";
    cin >> mu;

    cout << "sigma = ";
    cin >> sigma;
}


int main()
{
//Uniform
    float a = 0, b = 0;
    inputInterval(a, b);

    plotFUniform(a, b);
    plotfUniform(a, b);


//Gauss
    float mu = 0, sigma = 0;
    inputParameters(mu, sigma);

    plotFGauss(mu, sigma);
    plotfGauss(mu, sigma);   

    return 0;
}