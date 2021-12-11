#ifndef PROCESSOR_H
#define PROCESSOR_H


#include <iostream>
#include <random>

class Processor
{
public:
    Processor(std::vector<int> *_queue, std::default_random_engine *re);

    void setEvenDistribution(float _a, float _b);
    double even();
    int updateTime(double dt);

private:
    std::vector<int> *queue;
    float a, b;
    bool busy;
    double finishTime;
    std::default_random_engine *gnt;
};

#endif // PROCESSOR_H
