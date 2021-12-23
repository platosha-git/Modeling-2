#ifndef GENERATOR_H
#define GENERATOR_H

#include <iostream>
#include <random>

class Generator
{
public:
    Generator();

    void setRnd(std::default_random_engine *re);
    void setEvenDistribution(const float _a, const float _b);
    void setSection(std::vector<std::vector<int>> *_section);

    double even();
    bool produceTourist(double dt);

private:
    float a, b;
    double timer;
    std::vector<std::vector<int>> *section;
    std::default_random_engine *gnt;

    void queueTourist();
};

#endif // GENERATOR_H
