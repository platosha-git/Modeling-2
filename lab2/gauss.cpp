#include <iostream>
#include "gauss.h"
#include "memory.h"

using namespace std;

const double eps = 1e-5;

vector<double> gauss(float **a, vector<float> y, int n)
{
    float **matr = nullptr;
    allocateMatrix(&matr, n);
    copyMatrix(&matr, a, n);

    vector<double> x(n, 0);

    int k = 0;
    while (k < n) {
        float max = abs(matr[k][k]);
        int index = k;

        for (int i = k + 1; i < n; i++) {
            if (abs(matr[i][k]) > max) {
                max = abs(matr[i][k]);
                index = i;
            }
        }

        for (int j = 0; j < n; j++) {
            swap(matr[k][j], matr[index][j]);
        }
        swap(y[k], y[index]);

        for (int i = k; i < n; i++) {
            double temp = matr[i][k];
            if (abs(temp) < eps) continue;

            for (int j = 0; j < n; j++) {
                matr[i][j] /= temp;
            }

            y[i] /= temp;
            if (i == k)  continue;

            for (int j = 0; j < n; j++) {
                matr[i][j] -= matr[k][j];
            }
            y[i] -= y[k];
        }
        k++;
    }

    for (k = n - 1; k >= 0; k--) {
        x[k] = y[k];
        for (int i = 0; i < k; i++) {
            y[i] -= matr[i][k] * x[k];
        }
    }

    freeMatrix(&matr, n);

    return x;
}
