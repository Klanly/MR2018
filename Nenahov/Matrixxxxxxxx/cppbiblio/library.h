#ifndef CPPBIBLIO_LIBRARY_H
#define CPPBIBLIO_LIBRARY_H



#endif

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
class Matrixcpp {
    public:
            double *data;
            int rows;
            int cols;
    public:
    void matrix_rand(const int Mrows, const int Mcols);
    void matrix_print();
    Matrixcpp matrix_trans();

};



