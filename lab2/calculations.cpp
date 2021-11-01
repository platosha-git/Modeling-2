#include <iostream>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <cstring>
#include "gauss.h"
#include "memory.h"
#include "calculations.h"

using namespace std;

const static double eps = 1e-3;

vector<double> dp(float **system, vector<double> Pcur, const int n)
{
    vector<double> DPcur(n, 0);

    for (int i = 0; i < n; i++) {
        double s = 0;
        for (int j = 0; j < n; j++) {
            s += Pcur[j] * system[i][j];
        }
        DPcur[i] = s * eps;
    }

    return DPcur;
}

void getDeltas(vector<double> &dP, vector<double> &dTimes, float **system, const int numStates)
{
    vector<double> Pcur(numStates, 0);
    Pcur[0] = 1;

    double curTime = 0;

    while (curTime < 5) {
        dP.insert(dP.end(), Pcur.begin(), Pcur.end());
        vector<double> DPcur = dp(system, Pcur, numStates);
        for (int i = 0; i < numStates; i++) {
            Pcur[i] += DPcur[i];
        }
        curTime += eps;

        dTimes.push_back(curTime);

    }
}

vector<double> getTimeSystem(float **system, vector<double> P, const int numStates)
{
    vector<double> Pcur(numStates, 0);
    Pcur[0] = 1;

    double curTime = 0;
    vector<double> times(numStates, 0);

    while(find(times.begin(), times.end(), 0.0) != times.end()) {
        vector<double> DPcur = dp(system, Pcur, numStates);

        for (int i = 0; i < numStates; i++) {
            if (abs(Pcur[i] - P[i]) <= eps and
                DPcur[i] <= eps and
                times[i] == 0) {
                 times[i] = curTime;
            }
            Pcur[i] += DPcur[i];
        }
        curTime += eps;
    }

    return times;
}

Pt calculateTimeSystem(float **matrix, const int numStates)
{
    vector<float> sumIntensity(numStates, 0);
    for (int i = 0; i < numStates; i++) {
        for (int j = 0; j < numStates; j++) {
            sumIntensity[i] += matrix[i][j];
        }
    }

    float **system = nullptr;
    allocateMatrix(&system, numStates);

    for (int i = 0; i < numStates; i++) {
        for (int j = 0; j < numStates; j++) {
            if (i == j) {
                system[i][j] = -sumIntensity[i];
            }
            else {
                system[i][j] = matrix[j][i];
            }
        }
    }

    //system normalization
    float **systemNorm = nullptr;
    allocateMatrix(&systemNorm, numStates);
    copyMatrix(&systemNorm, system, numStates);

    for (int j = 0; j < numStates; j++) {
        systemNorm[numStates - 1][j] = 1;
    }
    vector<float> states(numStates - 1, 0);
    states.push_back(1);

    //system solution
    vector<double> x = gauss(systemNorm, states, numStates);
    freeMatrix(&systemNorm, numStates);

    //time calculation
    vector<double> times = getTimeSystem(system, x, numStates);

    //delta calculation
    vector<double> dP, dTimes;
    getDeltas(dP, dTimes, system, numStates);

    freeMatrix(&system, numStates);

    Pt pt;
    pt.P = x; pt.Time = times;
    pt.dP = dP; pt.dTime = dTimes;

    return pt;
}
