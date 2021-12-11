#ifndef GENERATOR_H
#define GENERATOR_H

#include <iostream>
#include <random>

class Generator
{
public:
    Generator();

    void setRnd(std::default_random_engine *re);
    void setEvenDistribution(float _a, float _b);
    double even();
    bool updateTime(double dt);

private:
    float a, b;
    double finishTime;
    std::default_random_engine *gnt;
};

#endif // GENERATOR_H
