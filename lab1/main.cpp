#include <iostream>
#include "uniform.h"

using namespace std;

void inputInterval(int &a, int &b)
{
    cout << "Input interval:" << endl;
    
    cout << "a = ";
    cin >> a;

    cout << "b = ";
    cin >> b;
}


int main()
{
    int a = 0, b = 0;
    inputInterval(a, b);

    plotFUniform(a, b);
    plotfUniform(a, b);

    return 0;
}