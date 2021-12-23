#ifndef OPERATOR_H
#define OPERATOR_H

#include <iostream>
#include <random>

class Operator
{
public:
    Operator(std::default_random_engine *re,
             std::vector<int> *_queue, std::vector<std::vector<int>> *_queueGroup);

    void setEvenDistribution(float _a, float _b);
    double even();
    bool liftTourist(double step);

private:
    std::default_random_engine *gnt;
    std::vector<int> *queue; int maxQueueLen;
    std::vector<std::vector<int>> *queueGroup;
    double timer;
    float a, b;
    bool busy;

    void addToQueue(const int human);
};

#endif // OPERATOR_H
