#include "memory.h"

void allocateMatrix(float ***Matrix, const int size)
{
    *Matrix = new float* [size];
    for (int i = 0; i < size; i++) {
        (*Matrix)[i] = new float [size];
    }
}

void copyMatrix(float ***Matrix, float **a, const int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            (*Matrix)[i][j] = a[i][j];
        }
    }
}

void freeMatrix(float ***Matrix, const int size)
{
    for (int i = 0; i < size; i++) {
        delete[] (*Matrix)[i];
    }
    delete [] (*Matrix);
}
