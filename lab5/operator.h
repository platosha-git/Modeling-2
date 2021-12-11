#ifndef OPERATOR_H
#define OPERATOR_H

#include <iostream>
#include <random>

class Operator
{
public:
    Operator(std::vector<int> *_queue, std::default_random_engine *re);

    void setEvenDistribution(float _a, float _b);
    double even();

    bool isBusy();
    void acceptRequest();
    void updateTime(double dt);

private:
    std::vector<int> *queue;
    float a, b;
    bool busy;
    double finishTime;
    std::default_random_engine *gnt;
};

#endif // OPERATOR_H
