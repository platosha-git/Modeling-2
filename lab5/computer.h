#ifndef COMPUTER_H
#define COMPUTER_H


#include <iostream>
#include <random>

class Computer
{
public:
    Computer(std::default_random_engine *re, std::vector<int> *_queue);

    void setTime(const double _time);
    bool updateTime(double dt);

private:
    std::default_random_engine *gnt;
    std::vector<int> *queue;
    double time, endTime;
    bool busy;
};

#endif // COMPUTER_H
