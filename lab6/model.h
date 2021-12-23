#ifndef MODEL_H
#define MODEL_H

#include "generator.h"
#include "operator.h"
#include "computer.h"

struct Result
{
    int Service;
    int Refusals;
    int PerRefusals;
};

class Model
{
public:
    Model();
    Result generate(const int numTourists, double step);

private:
    Generator generator;
    std::vector<Operator> lowLifts;
    std::vector<Computer> highLifts;
    std::vector<std::vector<int>> section1, section2;

    std::random_device rd;
    std::default_random_engine gnt;

    bool distributeClient();
    int serveClients(const double step);
    void storageTransfer(const double step);
};

#endif // MODEL_H
