#include "memory.h"

void allocateMatrix(float ***Matrix, const int size)
{
    *Matrix = new float* [size];
    for (int i = 0; i < size; i++) {
        (*Matrix)[i] = new float [size];
    }
}

void freeMatrix(float ***Matrix, const int size)
{
    for (int i = 0; i < size; i++) {
        delete[] (*Matrix)[i];
    }
    delete [] (*Matrix);
}
