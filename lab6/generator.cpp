#include <iostream>
#include <vector>
#include <random>
#include "generator.h"

using namespace std;

Generator::Generator() :
    a(0), b(0),
    timer(0),
    section(nullptr),
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

void Generator::setSection(vector<vector<int>> *_section)
{
    section = _section;
}

double Generator::even()
{
    uniform_real_distribution<double> dist(a, b);
    double num = dist(*gnt);
    return num;
}

bool Generator::produceTourist(double dt)
{
    timer -= dt;

    if (timer <= 0) {
        timer = even();
        queueTourist();
        return true;
    }
    return false;
}

void Generator::queueTourist()
{
    size_t minLen = (*section)[0].size();
    int minIdx = 0;

    for (size_t i = 1; i < section->size(); i++) {
        if ((*section)[i].size() < minLen) {
            minLen = (*section)[i].size();
            minIdx = i;
        }
    }
    (*section)[minIdx].push_back(1);
}
