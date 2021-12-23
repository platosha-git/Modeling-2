#include <iostream>
#include <vector>
#include <random>
#include "generator.h"

using namespace std;

Generator::Generator() :
    a(0), b(0),
    timer(0),
    human(-1),
    queue(nullptr),
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

void Generator::setQueue(vector<vector<int>> *_queue)
{
    human = -1;
    queue = _queue;
}

double Generator::even()
{
    uniform_real_distribution<double> dist(a, b);
    double num = dist(*gnt);
    return num;
}

bool Generator::produceClient(double dt)
{
    timer -= dt;

    if (timer <= 0) {
        timer = even();
        addClientToQueue();
        return true;
    }
    return false;
}

void Generator::addClientToQueue()
{
    size_t minLen = (*queue)[0].size();
    int minIdx = 0;

    for (size_t i = 1; i < queue->size(); i++) {
        if ((*queue)[i].size() < minLen) {
            minLen = (*queue)[i].size();
            minIdx = i;
        }
    }

    human++;
    (*queue)[minIdx].push_back(human);
}
