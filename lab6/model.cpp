#include <vector>
#include "model.h"

using namespace std;

Model::Model() :
    gnt(rd())
{
    storage1 = {{}, {}, {}};
    storage2 = {{}, {}};

    generator.setEvenDistribution(1, 9);
    generator.setRnd(&gnt);
    generator.setQueue(&storage1);

    Operator operator1(&gnt, &storage1[0], &storage2),
             operator2(&gnt, &storage1[1], &storage2),
             operator3(&gnt, &storage1[2], &storage2);

    operator1.setEvenDistribution(10, 20);
    operator2.setEvenDistribution(13, 19);
    operator3.setEvenDistribution(9, 17);
    operators = {operator1, operator2, operator3};

    Computer computer1(&gnt, &storage2[0]), computer2(&gnt, &storage2[1]);
    computer1.setTime(5);
    computer2.setTime(50);
    computers = {computer1, computer2};
}

Result Model::generate(const int numClients, double step)
{
    int notFailed = 0, generated = 0, processed = 0,
            failed = numClients;

    while (generated < numClients) {
        bool client = generator.produceClient(step);
        if (client) {
            generated++;
        }

        for (size_t i = 0; i < operators.size(); i++) {
            bool res = operators[i].processExam(step);
            if (res) {
                notFailed++;
                failed--;
            }
        }

        for (size_t i = 0; i < computers.size(); i++) {
            bool res = computers[i].serveClient(step);
            if (res == 1) {
                processed++;
            }
        }
    }

    while (processed < notFailed) {
        for (size_t i = 0; i < operators.size(); i++) {
            bool res = operators[i].processExam(step);
            if (res) {
                notFailed++;
                failed--;
            }
        }

        for (size_t i = 0; i < computers.size(); i++) {
            bool res = computers[i].serveClient(step);
            if (!res) {
                processed++;
            }
        }
    }

    cout << "Generated = " << generated << endl;
    cout << "Not Failed = " << notFailed << endl;
    cout << "Failed = " << failed << endl;
    cout << "Processed = " << processed << endl;

    Result res;
    res.Service = generated;
    res.Refusals = failed;
    res.PerRefusals = (processed) ? failed * 100 / processed : 0;

    return res;
}
