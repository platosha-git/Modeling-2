#include "generation.h"

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

const string tableName = "/home/platosha/Desktop/BMSTU/7sem/Modeling-2/lab3/tableRandom.txt";

vector<int> algGenerator(const int amount,
                            const int leftBorder, const int rightBorder)
{
    srand(time(0));

    vector<int> res;
    for (int i = 0; i < amount; i++) {
        int number = leftBorder + random() % rightBorder;
        res.push_back(number);
    }
    return res;
}

vector<int> tableGenerator(const int amount,
                            const int leftBorder, const int rightBorder)
{
    string line;
    ifstream in(tableName);
    if (in.is_open()) {
        getline(in, line);
        cout << line << endl;
    }
    in.close();

    vector<int> res;
    return res;
}
