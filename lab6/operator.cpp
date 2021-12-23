#include "operator.h"

using namespace std;

Operator::Operator(default_random_engine *re,
                   vector<int> *_queue, vector<vector<int>> *_queueGroup) :
    gnt(re),
    queue(_queue), maxQueueLen(0),
    queueGroup(_queueGroup),
    timer(0),
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

bool Operator::liftTourist(double step)
{
    timer -= step;

    int curLen = queue->size();
    if (curLen > maxQueueLen) {
        maxQueueLen = curLen;
    }

    if (!busy && curLen != 0) {
        busy = true;
        timer = even();
    }

    if (busy && timer <= 0) {
        if (random() % 100 <= 40) {
            (*queue).erase((*queue).begin());
            busy = false;
            return false;
        }
        else {
            (*queue).erase((*queue).begin());
            queueTourist();
            busy = false;
            return true;
        }
    }

    return false;
}

void Operator::queueTourist()
{
    size_t minLen = (*queueGroup)[0].size();
    int minIdx = 0;

    for (size_t i = 1; i < queueGroup->size(); i++) {
        if ((*queueGroup)[i].size() < minLen) {
            minLen = (*queueGroup)[i].size();
            minIdx = i;
        }
    }
    (*queueGroup)[minIdx].push_back(1);
}
