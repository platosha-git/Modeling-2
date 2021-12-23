#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
#include <random>

class Computer
{
public:
    Computer(std::default_random_engine *re, std::vector<int> *_queue);

    void setEvenDistribution(const float _a, const float _b);
    double even();
    bool liftTourist(double dt);

private:
    std::default_random_engine *gnt;
    std::vector<int> *queue;
    int maxLen = 0;
    double timer;
    float a, b;
    bool busy;
};

#endif // COMPUTER_H
