#include "../matrix.h"
#include <stdio.h>
#include <malloc.h>
#include <math.h>


#define MATRIX_EQUAL( matrix, expected_matrix )                                \
{                                                                           \
    printf("Testing matrix_multiplication... \n ");                                   \
    int no_error = 0;                                                      \
    for (int i = 0; i < matrix.rows; i++) {                                \
        for (int j = 0; j < matrix.cols; j++) {                            \
            if (    (fabs(0.95*matrix.data[i*matrix.rows + j]) <= fabs(expected_matrix[i][j]))  \
                && (fabs(1.05*matrix.data[i*matrix.rows + j]) >= fabs(expected_matrix[i][j]))    ) {     \
                no_error ++;                                                \
            }                                                                \
            else {                                                          \
                printf("value: %lf, expected: %lf; row: %d, col: %d\n",         \
                        matrix.data[i*matrix.rows + j], expected_matrix[i][j],     \
                        (i+1), (j+1));   \
                 return 1;       \
            }                                                                   \
        }                                                                       \
    }                                                                           \
    if (no_error == matrix.rows * matrix.cols) {                                  \
        printf("Test is completed successfully!\n");                                 \
    }                                                                               \
}


int main() {
    double test_1_1[2][2] = {{-3.85, 0.97},
                           {50.0, -156.75}};
    Matrix test_one_1 = {2,2,*test_1_1};

    double test_1_2[2][2] = {{-23.67, 105.88},
                             {0, -30.99}};
    Matrix test_one_2 = {2,2,*test_1_2};

    double result_1[2][2] = {{91.1295, -437.6938},
                             {-1183.5, 10151.6825}};

    Matrix result_one = matrix_mult(test_one_1, test_one_2);
    MATRIX_EQUAL(result_one, result_1);
    free(result_one.data);

    double test_2_1[3][4] = {{-58.0, 33.87, 12.99, -0.38},
                             {0.0, -33.85, 420.98, -32.88},
                             {-13.88, 53.9, -23.57, 0.43}};
    Matrix test_two_1 = {3,4,*test_2_1};

    double test_2_2[4][3] = {{-22.83, 0.88, 143.82},
                             {88.37, -5.06, 3.48},
                             {-33.90, 0.23, -20.36},
                             {0.0, 12.34, -88.756}};
    Matrix test_two_2 = {4,3,*test_2_2};

    double result_2[3][3] = {{3876.8709, -224.1237, -8454.44152},
                             {-17262.5465, -137.6328, -5770.65352},
                             {5879.0464, -285.0633, -1366.92948}};

    Matrix result_two = matrix_mult(test_two_1, test_two_2);

    MATRIX_EQUAL(result_two, result_2);
    free(result_two.data);


    return 0;
}