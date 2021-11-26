#include "generation.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

const string tableName = "/home/platosha/Desktop/BMSTU/7sem/Modeling-2/lab3/tableRandom.txt";
const int A = 73129;
const int C = 95121;
const int m = 100000;

vector<int> algGenerator(const int amount,
                         const int leftBorder, const int rightBorder)
{
    time_t now = time(0);
    tm *gmtm = gmtime(&now);
    static unsigned int seed = gmtm->tm_sec;

    vector<int> res;
    for (int i = 0; i < amount; i++) {
        seed = (seed * A + C) % m;
        int number = leftBorder + seed % (rightBorder - leftBorder + 1);
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

vector<int> tabGenerator(const int amount,
                         const int leftBorder, const int rightBorder)
{
    time_t now = time(0);
    tm *gmtm = gmtime(&now);
    unsigned int sec = gmtm->tm_sec;

    vector<int> table = getTable();

    vector<int> res;
    for (int i = 0; i < amount; i++) {
        int k = sec % 50, l = (sec + i) % 10;
        int number = leftBorder + table[10 * k + l] % (rightBorder - leftBorder + 1);
        res.push_back(number);
    }

    return res;
}

vector<double> frequencyTest(const std::vector<int> sequence,
                             const int leftBorder, const int rightBorder)
{
    double avg = 0;
    for (size_t i = 0; i < sequence.size(); i++) {
        avg += sequence[i];
    }
    avg /= sequence.size();

    double disp = 0;
    for (size_t i = 0; i < sequence.size(); i++) {
        disp += (sequence[i] - avg) * (sequence[i] - avg);
    }
    disp /= (sequence.size() - 1);
    disp = sqrt(disp);

    int count = 0;
    for (size_t i = 0; i < sequence.size(); i++) {
        if ((avg - disp) < sequence[i] && sequence[i] < (avg + disp)) {
            count++;
        }
    }

    double resActual = static_cast<float> (count) / static_cast<float> (sequence.size());
    double resTheory = 2 * disp / (rightBorder - leftBorder);
    vector<double> res {resActual, resTheory};

    return res;
}

vector<vector<double>> criterionCheck(const std::vector<int> dig1, const std::vector<int> dig2,
                    const std::vector<int> dig3)
{
    vector<vector<double>> res(3);
    res[0] = frequencyTest(dig1, 1, 9);
    res[1] = frequencyTest(dig2, 10, 99);
    res[2] = frequencyTest(dig3, 100, 999);

    return res;
}
