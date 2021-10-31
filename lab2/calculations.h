#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include <vector>

struct Pt
{
    std::vector<double> P;
    std::vector<double> Time;
};

Pt calculateTimeSystem(float **matrix, const int numStates);
std::vector<double> getTimeSystem();
std::vector<double> dps(float **matrix, std::vector<double> cur_probabilities, int n);

#endif // CALCULATIONS_H
