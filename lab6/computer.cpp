#include "computer.h"

using namespace std;

Computer::Computer(default_random_engine *re, vector<int> *_queue) :
    gnt(re),
    queue(_queue), maxQueueLen(0),
    timer(0),
    a(0), b(0),
    busy(false)
{

}

void Computer::setEvenDistribution(const float _a, const float _b)
{
    a = _a;
    b = _b;
}

double Computer::even()
{
    uniform_real_distribution<double> dist(a, b);
    double num = dist(*gnt);
    return num;
}

bool Computer::liftTourist(double dt)
{
    timer -= dt;

    updateMaxQueueLen();

    if (busy && timer <= 0) {
        busy = false;
        return true;
    }

    if (!busy && queue->size() != 0) {
        (*queue).erase((*queue).begin());
        timer = even();
        busy = true;
        return false;
    }

    return false;
}

void Computer::updateMaxQueueLen()
{
    if (static_cast<int>(queue->size()) > maxQueueLen) {
        maxQueueLen = queue->size();
    }
}

int Computer::getMaxQueueLen()
{
    return maxQueueLen;
}
