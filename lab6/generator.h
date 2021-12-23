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
    void setQueue(std::vector<std::vector<int>> *_queue);

    double even();
    bool produceClient(double dt);
    void addClientToQueue();

private:
    float a, b;
    double timer;
    int human;
    std::vector<std::vector<int>> *queue;
    std::default_random_engine *gnt;
};

#endif // GENERATOR_H
