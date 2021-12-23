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
    int curTourists = 0, notFailed = 0, processed = 0,
            failed = numTourists;

    while (curTourists < numTourists) {
        bool tourist = generator.produceTourist(step);
        if (tourist) {
            curTourists++;
        }

        int lowTransferred = lowTransfer(step);
        notFailed += lowTransferred;
        failed -= lowTransferred;
        processed += highTransfer(step);
    }

    while (processed < notFailed) {
        int lowTransferred = lowTransfer(step);
        notFailed += lowTransferred;
        failed -= lowTransferred;
        processed += highTransfer(step);
    }

    cout << "Generated = " << curTourists << endl;
    cout << "Not Failed = " << notFailed << endl;
    cout << "Failed = " << failed << endl;
    cout << "Processed = " << processed << endl;

    Result res;
    res.Service = curTourists;
    res.Refusals = failed;
    res.PerRefusals = (processed) ? failed * 100 / processed : 0;

    return res;
}

int Model::lowTransfer(const double step)
{
    int numTransferred = 0;
    for (size_t i = 0; i < lowLifts.size(); i++) {
        numTransferred += lowLifts[i].liftTourist(step);
    }
    return numTransferred;
}

int Model::highTransfer(const double step)
{
    int numTransferred = 0;
    for (size_t i = 0; i < highLifts.size(); i++) {
        numTransferred += highLifts[i].liftTourist(step);
    }
    return numTransferred;
}
