#ifndef GENERATOR_H
#define GENERATOR_H

#include <iostream>
#include <random>

class Generator
{
public:
    Generator();

    void setEvenDistribution(float _a, float _b);
    double even();

    void setNormalDistribution(double _mu, double _sigma);
    double normal();

    int eventTime(int total_tasks, int repeat);
    int stepTime(int total_tasks, int repeat, double step);

private:
    std::random_device rd;
    std::default_random_engine generator;
    float a, b;
    double mu, sigma;
};

#endif // GENERATOR_H
