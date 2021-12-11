#ifndef MODEL_H
#define MODEL_H

#include "generator.h"
#include "operator.h"
#include "processor.h"

class Model
{
public:
    Model();
    void generate(const int numRequests, double step);

private:
    std::vector<int> queue1, queue2;
    Generator generator;
    std::vector<Operator> operators;
    std::vector<Processor> processors;

    std::random_device rd;
    std::default_random_engine gnt;

    double even(const float a, const float b);
};

#endif // MODEL_H
