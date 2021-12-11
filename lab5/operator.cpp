#include "operator.h"

using namespace std;

Operator::Operator(default_random_engine *re, vector<int> *_queue) :
    gnt(re),
    queue(_queue),
    endTime(0),
    a(0), b(0),
    busy(false)
{

}

void Operator::setEvenDistribution(float _a, float _b)
{
    a = _a;
    b = _b;
}

double Operator::even()
{
    uniform_real_distribution<double> dist(a, b);
    double num = dist(*gnt);
    return num;
}

bool Operator::isBusy()
{
    return busy;
}

void Operator::acceptRequest()
{
    busy = true;
    endTime = even();
}

void Operator::updateTime(double dt)
{
    endTime -= dt;

    if (busy && endTime <= 0) {
        busy = false;
        (*queue).push_back(1);
    }
}
