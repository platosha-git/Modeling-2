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
    void setSection(std::vector<std::vector<int>> *_queue);

    double even();
    bool produceTourist(double dt);
    void addClientToQueue();

private:
    float a, b;
    double timer;
    int human;
    std::vector<std::vector<int>> *queue;
    std::default_random_engine *gnt;
};

#endif // GENERATOR_H
