#ifndef GENERATION_H
#define GENERATION_H

#include <vector>

std::vector<int> algGenerator(const int amount,
                              const int leftBorder, const int rightBorder);

std::vector<int> getTable();
std::vector<int> tabGenerator(const int amount,
                              const int leftBorder, const int rightBorder);


std::vector<double> frequencyTest(const std::vector<int> dig,
                                  const int leftBorder, const int rightBorder);

std::vector<std::vector<double>> criterionCheck(const std::vector<int> dig1, const std::vector<int> dig2,
                                   const std::vector<int> dig3);

#endif // GENERATION_H
