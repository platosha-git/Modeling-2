#ifndef MEMORY_H
#define MEMORY_H

void allocateMatrix(float ***Matrix, const int size);
void copyMatrix(float ***Matrix, float **a, const int size);
void freeMatrix(float ***Matrix, const int size);

#endif // MEMORY_H
