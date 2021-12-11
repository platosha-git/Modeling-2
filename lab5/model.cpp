#include <vector>
#include "model.h"

using namespace std;

Model::Model() :
    gnt(rd())
{
    generator.setEvenDistribution(8, 12);
    generator.setRnd(&gnt);

    queue1 = vector<int> (0);
    queue2 = vector<int> (0);
    Operator operator1(&gnt, &queue1), operator2(&gnt, &queue1), operator3(&gnt, &queue2);
    operator1.setEvenDistribution(15, 25);
    operator2.setEvenDistribution(30, 50);
    operator3.setEvenDistribution(20, 60);
    operators = {operator1, operator2, operator3};

    Computer computer1(&gnt, &queue1), computer2(&gnt, &queue2);
    computer1.setTime(15);
    computer2.setTime(30);
    computers = {computer1, computer2};
}

Result Model::generate(const int numClients, double step)
{
    int curClients = 0, numServed = 0, numRefusals = 0;

    while (curClients < numClients) {
        bool client = generator.produceClient(step);
        if (client) {
            curClients++;
            numRefusals += distributeClient();
        }

        updateOperators(step);
        numServed += serveClients(step);
    }

    while (numRefusals + numServed < numClients) {
        updateOperators(step);
        numServed += serveClients(step);
    }

    Result res;
    res.Generated = curClients;
    res.Lost = numRefusals;
    res.Processed = numServed;

    return res;
}

//
void Model::updateOperators(const double step)
{
    for (size_t i = 0; i < operators.size(); i++) {
        operators[i].updateTime(step);
    }
}

//Обслуживание клиента компьютерами
int Model::serveClients(const double step)
{
    int numProceesed = 0;
    for (size_t i = 0; i < computers.size(); i++) {
        numProceesed += computers[i].updateTime(step);
    }

    return numProceesed;
}

//Распределение клиента по операторам
bool Model::distributeClient()
{
    size_t i = 0;
    for (; i < operators.size(); i++) {
        if (!operators[i].isBusy()) {
            operators[i].acceptRequest();
            break;
        }
    }

    if (i == operators.size()) {
        return true;
    }
    return false;
}
