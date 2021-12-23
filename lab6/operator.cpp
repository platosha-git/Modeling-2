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

bool Operator::processExam(double step)
{
    timer -= step;
    if (queue->size() > maxQueueLen) {
        maxQueueLen = queue->size();
    }

    if (!busy && queue->size() != 0) {
        busy = true;
        timer = even();
    }

    if (busy && timer <= 0) {
        if (random() % 100 < 70) {
            int human = (*queue)[0];
            (*queue).erase((*queue).begin());
            addToQueue(human);
            busy = false;
            return true;
        }
        else {
            (*queue).erase((*queue).begin());
            busy = false;
            return false;
        }
    }

    return false;
}

void Operator::addToQueue(const int human)
{
    size_t minLen = (*queueGroup)[0].size();
    int minIdx = 0;

    for (size_t i = 1; i < queueGroup->size(); i++) {
        if ((*queueGroup)[i].size() < minLen) {
            minLen = (*queueGroup)[i].size();
            minIdx = i;
        }
    }

    (*queueGroup)[minIdx].push_back(human);
}
