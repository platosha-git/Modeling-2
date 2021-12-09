#ifndef GENERATOR_H
#define GENERATOR_H

#include <iostream>
#include <random>

class Generator
{
public:
    Generator(const int numMsg);

    void setEvenDistribution(float _a, float _b);
    double even();

    void setPoissonDistribution(float _lambda);
    int poisson();

    int eventTime(int repeat = 0);
    int iterTime(double step, int repeat = 0);

private:
    int numMessages;
    std::random_device rd;
    std::default_random_engine generator;
    float a, b;
    float lambda;
};

#endif // GENERATOR_H
