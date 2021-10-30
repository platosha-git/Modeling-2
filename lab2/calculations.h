#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include <vector>

std::vector<float> calculateTimeSystem(float **matrix, const int numStates);
std::vector<float> gauss(float **a, std::vector<float> y, int n);

#endif // CALCULATIONS_H
