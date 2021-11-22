#include "generation.h"

#include <iostream>
#include <cmath>

using namespace std;

vector<int> algGenerator(const int elem, const int n)
{
    vector<int> res;
    for (int i = 0; i < n; i++) {
        int min = pow(10, elem - 1);
        int max = pow(10, n) - 1;
        int number = min + (random() % (max - min + 1));
        res.push_back(number);
    }
    return res;
}
