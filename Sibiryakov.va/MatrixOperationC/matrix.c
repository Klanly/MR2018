#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matrix.h"

extern double matrix_trace(const Matrix A)
{
    double trace = 0; // след матрицы
    unsigned int size = A.rows;
    for (int counter_rows = 0; counter_rows < size; counter_rows++) {
        for (int counter_cols = 0; counter_cols < size; counter_cols++) {
            if (counter_rows == counter_cols) {
                trace += A.data[counter_rows * size + counter_cols]; // считаем след матрицы
            }
        }
    }
    return trace;
}

extern Matrix matrix_mult(const Matrix A, const Matrix B)
{
    Matrix TMres;
    TMres.cols = B.cols;
    TMres.rows = A.rows;
    TMres.data = malloc(TMres.cols * TMres.rows * sizeof(double));

    for (int i=0; i<TMres.rows; i++)
        for (int j=0; j<TMres.cols; j++)
    TMres.data[i*TMres.rows + j] = 0;

    double res = 0;
    for (int i=0; i<TMres.rows; i++) {
        for (int j = 0; j < TMres.cols; j++) {
            for (int u = 0; u < A.cols; u++) {
                TMres.data[(i * TMres.cols) + j] += (A.data[(i * A.cols) + u] * B.data[(u * B.cols) + j]);
            }
        }
    }
     return TMres;
}

extern Matrix matrix_minor(const Matrix A, unsigned int del_row, int del_col)
{
    unsigned int size_matrix = A.cols;

    Matrix temp = {size_matrix-1, size_matrix-1};
    temp.data = malloc(temp.cols * temp.rows * sizeof(double));

    int elem = 0;
    for (int i = 0; i < size_matrix; i++){
        if (i == del_row) {
            continue;
        }
        for (int j = 0; j < size_matrix; j++) {
            if (j == del_col) {
                continue;
            }
            temp.data[elem] = A.data[i*size_matrix + j];
            elem++;
        }
    }
    return temp;
}

extern double matrix_determinant(const Matrix A)
{

    if (A.cols == 1) {
        return A.data[0];
    }

    double ans = 0;
    int sign = 1;
    for (int i = 0; i < A.rows; i++) {
        Matrix temp = matrix_minor(A, 0, i);
        ans += (sign * A.data[i] * matrix_determinant(temp));
        sign *= -1;
        free(temp.data);
    }

    return ans;
}

extern Matrix matrix_sum(const Matrix A, const Matrix B)
{
    unsigned int rows = A.rows;
    unsigned int cols = A.cols;
    Matrix temp = {cols, rows};
    temp.data = malloc(cols * rows * sizeof(double));

    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            temp.data[i*rows + j] = A.data[i*rows + j] + B.data[i*rows + j];
        }
    }

    return temp;
}

extern Matrix matrix_mult__scalar(const double scalar, const Matrix A)
{
    unsigned int rows = A.rows;
    unsigned int cols = A.cols;
    Matrix temp = {cols, rows};
    temp.data = malloc(cols * rows * sizeof(double));

    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            temp.data[i*rows + j] = scalar*A.data[i*rows+j];
        }
    }

    return temp;
}


extern Matrix matrix_trans(const Matrix A)
{
    unsigned int rows = A.rows;
    unsigned int cols = A.cols;
    Matrix temp = {cols, rows};
    temp.data = malloc(cols * rows * sizeof(double));

    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            temp.data[j*cols + i] = A.data[i*cols+j];
        }
    }

    return temp;
}

extern Matrix matrix_invert(const Matrix A)
{
    double temp;

    unsigned int rows = A.rows;
    unsigned int cols = A.cols;
    Matrix one = {cols, rows};
    Matrix result = {cols, rows};
    unsigned int size = cols;
    one.data = malloc(cols * rows * sizeof(double));
    result.data = malloc(cols * rows * sizeof(double));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            one.data[i * rows + j] = 0.0;

            if (i == j)
                one.data[i * rows + j] = 1.0;

            result.data[i*size + j] = A.data[i*size + j];
        }
    }

    for (int k = 0; k < size; k++) {
        temp = result.data[k*size + k];

        for (int j = 0; j < size; j++) {
            result.data[k*size + j] /= temp;
            one.data[k*size + j] /= temp;
        }

        for (int i = k + 1; i < size; i++) {
            temp = result.data[i*size + k];

            for (int j = 0; j < size; j++) {
                result.data[i*size + j] -= result.data[k*size + j] * temp;
                one.data[i*size + j] -= one.data[k*size + j] * temp;
            }
        }
    }

    for (int k = (size - 1); k > 0; k--) {

        for (int i = k - 1; i >= 0; i--) {

            temp = result.data[i*size + k];

            for (int j = 0; j < size; j++) {
                result.data[i*size + j] -= result.data[k*size + j] * temp;
                one.data[i*size + j] -= one.data[k*size + j] * temp;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {

            result.data[i*size + j] = one.data[i*size + j];
        }
    }

    free(one.data);

    return(result);
}

extern double matrix_eigen_values(const Matrix A)
{
    unsigned size = A.rows;
    double vector0[size];
    double vector0norm[size];
    double vector[size];
    static double sum = 0;
    static double d0 = 0;
    static double d = 0;
    double e = 0;
    for (unsigned i = 0; i < size; i++) {
        vector0[i] = 0;
    }
        vector0[0] = 1;
        do {
            for (unsigned j = 0; j < size; j++) {
               sum = sum + vector0[j] * vector0[j];
            }
            d0 = sqrt(sum);
            for (unsigned k = 0; k < size; k++) {
                vector0norm[k] = vector0[k] / d0;
            }
            for (unsigned i1 = 0; i1 < size; i1++) {
                vector[i1] = 0;
                for (unsigned j1 = 0; j1 < size; j1++) {
                    vector[i1] = vector[i1] + A.data[i1*A.rows + j1] * vector0norm[j1];
                }
            }
            sum = 0;
            for (unsigned k1 = 0; k1 < size; k1++) {
                sum = sum + vector[k1] * vector[k1];
            }
            d = sqrt(sum);
            e = fabs(d-d0);
            for (unsigned i2 = 0; i2 < size; i2++) {
                vector0[i2] = vector[i2];
            }
            sum = 0;
        }
        while (e > 0.001);
        return d;
}

extern void matrix_eigen_vectors(const Matrix A)
{
    unsigned size = A.rows;
    double vector0[size];
    double vector0norm[size];
    double vector[size];
    static double sum = 0;
    static double d0 = 0;
    static double d = 0;
    double e = 0;
    for (unsigned i = 0; i < size; i++) {
        vector0[i] = -1;
    }
    vector0[0] = 1;
    do {
        for (unsigned j = 0; j < size; j++) {
            sum = sum + vector0[j] * vector0[j];
        }
        d0 = sqrt(sum);
        for (unsigned k = 0; k < size; k++) {
            vector0norm[k] = vector0[k] / d0;
        }
        for (unsigned i1 = 0; i1 < size; i1++) {
            vector[i1] = 0;
            for (unsigned j1 = 0; j1 < size; j1++) {
                vector[i1] = vector[i1] + A.data[i1*A.rows + j1] * vector0norm[j1];
            }
        }
        sum = 0;
        for (unsigned k1 = 0; k1 < size; k1++) {
            sum = sum + vector[k1] * vector[k1];
        }
        d = sqrt(sum);
        e = fabs(d-d0);
        for (unsigned i2 = 0; i2 < size; i2++) {
            vector0[i2] = vector[i2];
        }
        sum = 0;
    }
    while (e > 0.001);
    for (unsigned i = 0; i < size; i++) {
        printf("%lf\n", vector0norm[i]);
    }
}