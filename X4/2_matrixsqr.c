#include "cblas.h"
void MatrixSqr (int n , const double *A , double* R ){
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                n, n, n, 1.0, A, n, A, n, 0.0, R, n);
}
/*
CblasRowMajor
Indicates that the matrices are stored in row major order, with the elements of each row of the matrix stored contiguously as shown in the figure above.
CblasNoTrans
Enumeration type indicating that the matrices A and B should not be transposed or conjugate transposed before multiplication.
m, n, k
Integers indicating the size of the matrices:
A: m rows by k columns
B: k rows by n columns
C: m rows by n columns
alpha
Real value used to scale the product of matrices A and B.
A
Array used to store matrix A.
k
Leading dimension of array A, or the number of elements between successive rows (for row major storage) in memory. In the case of this exercise the leading dimension is the same as the number of columns.
B
Array used to store matrix B.
n
Leading dimension of array B, or the number of elements between successive rows (for row major storage) in memory. In the case of this exercise the leading dimension is the same as the number of columns.
beta
Real value used to scale matrix C.
C
Array used to store matrix C.
n
Leading dimension of array C, or the number of elements between successive rows (for row major storage) in memory. In the case of this exercise the leading dimension is the same as the number of columns.

 cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
       m, n, k, alpha, A, k, B, n, beta, C, n);
 */