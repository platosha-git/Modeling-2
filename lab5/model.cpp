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
    Operator operator1(&queue1, &gnt), operator2(&queue1, &gnt), operator3(&queue2, &gnt);
    operator1.setEvenDistribution(15, 25);
    operator2.setEvenDistribution(30, 50);
    operator3.setEvenDistribution(20, 60);
    operators = {operator1, operator2, operator3};

    Processor processor1(&queue1, &gnt), processor2(&queue2, &gnt);
    processor1.setEvenDistribution(15, 15);
    processor2.setEvenDistribution(30, 30);
    processors = {processor1, processor2};
}

void Model::generate(const int numRequests, double step)
{
    int generated = 0, lost = 0, processed = 0;
    while (generated < numRequests) {
        bool request = generator.updateTime(step);
        if (request) {
            generated++;

            size_t i = 0;
            for (; i < operators.size(); i++) {
                if (!operators[i].isBusy()) {
                    operators[i].acceptRequest();
                    break;
                }
            }

            if (i == operators.size()) {
                lost++;
            }
        }

        for (size_t i = 0; i < operators.size(); i++) {
            operators[i].updateTime(step);
        }

        for (size_t i = 0; i < processors.size(); i++) {
            int res = processors[i].updateTime(step);
            if (res == 1) {
                processed++;
            }
        }
    }

    while (lost + processed < numRequests) {
        for (size_t i = 0; i < operators.size(); i++) {
            operators[i].updateTime(step);
        }

        for (size_t i = 0; i < processors.size(); i++) {
            int res = processors[i].updateTime(step);
            if (res == 1) {
                processed++;
            }
        }
    }

    cout << "generated: " << generated << endl;
    cout << "lost: " << lost << endl;
    cout << "processed: " << processed << endl;

}
