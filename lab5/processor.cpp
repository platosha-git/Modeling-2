#include "processor.h"

using namespace std;

Processor::Processor(vector<int> *_queue, default_random_engine *re) :
    queue(_queue),
    a(0), b(0),
    busy(false),
    finishTime(0),
    gnt(re)
{
    cout << "queue " << queue->size() << endl;
}

void Processor::setEvenDistribution(float _a, float _b)
{
    a = _a;
    b = _b;
}

double Processor::even()
{
    uniform_real_distribution<double> dist(a, b);
    double num = dist(*gnt);
    return num;
}

int Processor::updateTime(double dt)
{
    finishTime -= dt;

    if (busy && finishTime <= 1e-5) {
        busy = false;
        return 1;
    }

    if (!busy && (*queue).size() != 0) {
        (*queue).erase((*queue).begin());
        finishTime = even();
        busy = true;
        return 2;
    }

    return 0;
}
