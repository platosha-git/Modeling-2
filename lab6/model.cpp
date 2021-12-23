#include <vector>
#include "model.h"

using namespace std;

Model::Model() :
    gnt(rd())
{
    section1 = vector<vector<int>>(3, vector<int>());
    section2 = vector<vector<int>>(2, vector<int>());

    generator.setEvenDistribution(25, 35);
    generator.setRnd(&gnt);
    generator.setSection(&section1);

    Operator lowLift1(&gnt, &section1[0], &section2),
             lowLift2(&gnt, &section1[1], &section2),
             lowLift3(&gnt, &section1[2], &section2);

    lowLift1.setEvenDistribution(100, 140);
    lowLift2.setEvenDistribution(120, 180);
    lowLift3.setEvenDistribution(90, 110);
    lowLifts = {lowLift1, lowLift2, lowLift3};

    Computer highLift1(&gnt, &section2[0]),
             highLift2(&gnt, &section2[1]);

    highLift1.setEvenDistribution(155, 185);
    highLift2.setEvenDistribution(150, 170);
    highLifts = {highLift1, highLift2};
}

Result Model::generate(const int numTourists, double step)
{
    int notFailed = 0, generated = 0, processed = 0,
            failed = numTourists;

    while (generated < numTourists) {
        bool tourist = generator.produceTourist(step);
        if (tourist) {
            generated++;
        }

        for (size_t i = 0; i < lowLifts.size(); i++) {
            bool res = lowLifts[i].processExam(step);
            if (res) {
                notFailed++;
                failed--;
            }
        }

        for (size_t i = 0; i < highLifts.size(); i++) {
            bool res = highLifts[i].serveClient(step);
            if (res == 1) {
                processed++;
            }
        }
    }

    while (processed < notFailed) {
        for (size_t i = 0; i < lowLifts.size(); i++) {
            bool res = lowLifts[i].processExam(step);
            if (res) {
                notFailed++;
                failed--;
            }
        }

        for (size_t i = 0; i < highLifts.size(); i++) {
            bool res = highLifts[i].serveClient(step);
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
