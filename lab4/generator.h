#ifndef GENERATOR_H
#define GENERATOR_H

#include <iostream>
#include <random>

class Generator
{
public:
    Generator(const int numMsg, const int numRepeat);

    void setEvenDistribution(float _a, float _b);
    double even();

    void setPoissonDistribution(float _lambda);
    int poisson();

    int percentage();
    int eventTime();
    int iterTime(double step);

private:
    int numMessages, perRepeat;
    std::random_device rd;
    std::default_random_engine generator;
    float a, b;
    float lambda;
};

#endif // GENERATOR_H
