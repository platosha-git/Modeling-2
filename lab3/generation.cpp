#include "generation.h"

#include <iostream>
#include <fstream>
#include <sstream>
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

vector<int> getTable()
{
    string line = "", number = "";
    vector<int> table;

    ifstream in(tableName);
    if (in.is_open()) {
        while (getline(in, line)) {
            stringstream strStream(line);
            while (getline(strStream, number, ' ')) {
                table.push_back(atoi(number.c_str()));
            }
        }
    }
    in.close();

    return table;
}

vector<int> tableGenerator(const int amount,
                            const int leftBorder, const int rightBorder)
{
    srand(time(0));

    vector<int> table = getTable();
    vector<int> res;
    for (int i = 0; i < amount; i++) {
        int k = random() % 50, l = random() % 10;
        int number = leftBorder + table[10 * k + l] % rightBorder;
        res.push_back(number);
    }

    return res;
}
