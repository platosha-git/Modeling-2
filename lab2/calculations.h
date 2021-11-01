#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include <vector>

struct Pt
{
    std::vector<double> P;
    std::vector<double> Time;

    std::vector<double> dP;
    std::vector<double> dTime;
};

Pt calculateTimeSystem(float **matrix, const int numStates);
std::vector<double> getTimeSystem(float **system, std::vector<double> P, const int numStates);
std::vector<double> dp(float **system, std::vector<double> Pcur, const int n);
void getDeltas(std::vector<double> &dP, std::vector<double> &dTimes, float **system, const int numStates);

#endif // CALCULATIONS_H
