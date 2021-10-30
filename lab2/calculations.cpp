#include <iostream>
#include "memory.h"
#include "calculations.h"

using namespace std;

const double eps = 0.00001;

vector<float> gauss(float **a, vector<float> y, int n)
{
    vector<float> x(n);

    int k = 0;
    while (k < n) {
        float max = abs(a[k][k]);
        int index = k;

        for (int i = k + 1; i < n; i++) {
            if (abs(a[i][k]) > max) {
                max = abs(a[i][k]);
                index = i;
            }
        }

        for (int j = 0; j < n; j++) {
            float temp = a[k][j];
            a[k][j] = a[index][j];
            a[index][j] = temp;
        }

        float temp = y[k];
        y[k] = y[index];
        y[index] = temp;

        for (int i = k; i < n; i++) {
            double temp = a[i][k];
            if (abs(temp) < eps) continue;

            for (int j = 0; j < n; j++) {
                a[i][j] = a[i][j] / temp;
            }

            y[i] = y[i] / temp;
            if (i == k)  continue;

            for (int j = 0; j < n; j++) {
                a[i][j] = a[i][j] - a[k][j];
            }

            y[i] = y[i] - y[k];
        }
        k++;
    }

    for (k = n - 1; k >= 0; k--) {
        x[k] = y[k];
        for (int i = 0; i < k; i++) {
            y[i] = y[i] - a[i][k] * x[k];
        }
    }

    return x;
}

vector<float> calculateTimeSystem(float **matrix, const int numStates)
{
    vector<int> sum(numStates);
    for (int i = 0; i < numStates; i++) {
        sum[i] = 0;
        for (int j = 0; j < numStates; j++) {
            sum[i] += matrix[i][j];
        }
    }

    float **system = nullptr;
    allocateMatrix(&system, numStates);

    for (int i = 0; i < numStates; i++) {
        for (int j = 0; j < numStates; j++) {
            if (i == j) {
                system[i][j] = -sum[i];
            }
            else {
                system[i][j] = matrix[j][i];
            }
        }
    }

    //system normalization
    for (int j = 0; j < numStates; j++) {
        system[numStates - 1][j] = 1;
    }
    vector<float> states(numStates - 1, 0);
    states.push_back(1);

    vector<float> x = gauss(system, states, numStates);

    freeMatrix(&system, numStates);

    vector<float> time(numStates);
    for (int i = 0; i < numStates; i++) {
        time[i] = (1 - x[i]) / (x[i] * sum[i]);
    }

    return time;
}
