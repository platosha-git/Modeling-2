#ifndef MODEL_H
#define MODEL_H

#include "generator.h"
#include "operator.h"
#include "computer.h"

struct Result
{
    int Generated;
    int Lost;
    int Processed;
};

class Model
{
public:
    Model();
    Result generate(const int numRequests, double step);

private:
    std::vector<int> queue1, queue2;
    Generator generator;
    std::vector<Operator> operators;
    std::vector<Computer> computers;

    std::random_device rd;
    std::default_random_engine gnt;

    bool distributeClient();
    int serveClients(const double step);
    void updateOperators(const double step);
};

#endif // MODEL_H
