#include <iostream>
#include <vector>
#include <random>
#include "generator.h"

using namespace std;

Generator::Generator() :
    a(0), b(0),
    endTime(0),
    gnt(nullptr)
{

}

void Generator::setRnd(default_random_engine *re)
{
    gnt = re;
}

void Generator::setEvenDistribution(float _a, float _b)
{
    a = _a;
    b = _b;
}

double Generator::even()
{
    uniform_real_distribution<double> dist(a, b);
    double num = dist(*gnt);
    return num;
}

bool Generator::produceClient(double dt)
{
    endTime -= dt;

    if (endTime <= 0) {
        endTime = even();
        return true;
    }
    return false;
}
