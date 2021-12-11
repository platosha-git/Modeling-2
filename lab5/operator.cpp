#include "operator.h"

using namespace std;

Operator::Operator(vector<int> *_queue, default_random_engine *re) :
    queue(_queue),
    a(0), b(0),
    busy(false),
    finishTime(0),
    gnt(re)
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
    finishTime = even();
}

void Operator::updateTime(double dt)
{
    finishTime -= dt;

    if (busy && finishTime <= 1e-5) {
        busy = false;
        (*queue).push_back(1);
    }
}
