#ifndef OPERATOR_H
#define OPERATOR_H

#include <iostream>
#include <random>

class Operator
{
public:
    Operator(std::default_random_engine *re, std::vector<int> *_queue);

    void setEvenDistribution(float _a, float _b);
    double even();

    bool isFree();
    void acceptRequest();
    void sendRequest(double dt);

private:
    std::default_random_engine *gnt;
    std::vector<int> *queue;
    double endTime;
    float a, b;
    bool busy;
};

#endif // OPERATOR_H
