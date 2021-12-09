#include <iostream>
#include <vector>
#include <random>
#include "generator.h"

using namespace std;

Generator::Generator(const int numMsg, const int numRepeat) :
    numMessages(numMsg), perRepeat(numRepeat),
    generator(rd()),
    a(0), b(0),
    lambda(0)
{

}

void Generator::setEvenDistribution(float _a, float _b)
{
    a = _a;
    b = _b;
}

void Generator::setPoissonDistribution(float _lambda)
{
    lambda = _lambda;
}

double Generator::even()
{
    uniform_real_distribution<double> dist(a, b);
    double num = dist(generator);
    return num;
}

int Generator::poisson()
{
    poisson_distribution<int> dist(lambda);
    int num = dist(generator);
    return num;
}

int Generator::percentage()
{
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(1, 100);
    int num = uni(rng);
    return num;
}

int Generator::eventTime()
{
    int processedMsg = 0;
    int curLen = 0, maxLen = 0;

    double timeGeneration = even();
    double timeProcessing = timeGeneration + poisson();

    while (processedMsg < numMessages) {
        if (timeGeneration <= timeProcessing) {
            curLen++;
            maxLen = max(maxLen, curLen);
            timeGeneration += even();
        }
        else if (timeGeneration >= timeProcessing) {
            if (curLen > 0) {
                curLen--;
                processedMsg++;
                if (percentage() < perRepeat) {
                    curLen++;
                }
            }

            if (curLen > 0) {
                timeProcessing += poisson();
            }
            else {
                timeProcessing = timeGeneration + poisson();
            }
        }
    }

    return maxLen;
}

int Generator::iterTime(double step)
{
    int processedMsg = 0;
    int curLen = 0, maxLen = 0;

    double curTime = step;
    double timeGeneration = even();
    double prevTimeGeneration = timeGeneration;
    double timeProcessing = timeGeneration + poisson();

    while (processedMsg < numMessages) {
        if (curTime > timeGeneration) {
            curLen++;
            maxLen = max(maxLen, curLen);
            prevTimeGeneration = timeGeneration;
            timeGeneration += poisson();
        }

        if (curTime > timeProcessing) {
            if (curLen > 0) {
                curLen--;
                processedMsg++;
                if (percentage() <= perRepeat) {
                    curLen++;
                }
            }

            if (curLen > 0) {
                timeProcessing += poisson();
            }
            else {
                timeProcessing = prevTimeGeneration + poisson();
            }
        }
        curTime += step;
    }

    return maxLen;
}
