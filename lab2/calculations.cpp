#include <vector>
#include "calculations.h"

using namespace std;

void calculateTimeSystem(const float **Matrix, const int numStates)
{
    //coef = numpy.zeros((n, n))
    //sum = numpy.zeros(n)
    float coef[10][10];
    vector<float> sum(numStates);

    for (int i = 0; i < numStates; i++) {
        for (int j = 0; j < numStates; j++) {
            sum[i] += Matrix[i][j];
            coef[i][j] = Matrix[i][j];
        }
        coef[i][i] = -sum[i];

        vector<float> m(numStates);
        m[numStates - 1] = 1;

        for (int i = 0; i < numStates; i++) {
            coef[numStates - 1][i] = 1;
        }

        vector<float> out(numStates);

        float coefrev[10][10];
        coefrev = coef.inverse();
        //out = numpy.linalg.solve(coef, m)

        vector<float> time(numStates);
        for (int i = 0; i < numStates; i++) {
            time[i] = (1 - out[i]) / out[i] / sum[i];
        }

        return out, time
}
