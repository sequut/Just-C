#include "cblas.h"
#include <stdio.h>
#include <stdlib.h>

void dgemm(int m, int n, int k, double alpha, const double* A, const double* B, double beta, double* C){
    double* aa = (double*)calloc(m * k, sizeof(double));
    if (!aa)
        exit(666);

    double* answer = (double*)calloc(n * m, sizeof(double));
    if (!answer){
        free(aa);
        exit(666);
    }


    for (int i = 0; i < m * k; i++)
        aa[i] = alpha * A[i];

    for (int i = 0; i < m * n; i++)
        C[i] *= beta;


    for (int a = 0; a < m; a++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < k; j++)
                answer[a * n + i] += aa[a * k + j] * B[j * n + i];

    for (int i = 0; i < m * n; i++)
        C[i] += answer[i];

    free(aa);
    free(answer);
}
void cblas_dgemm(OPENBLAS_CONST enum CBLAS_ORDER Order,
                 OPENBLAS_CONST enum CBLAS_TRANSPOSE TransA,
                 OPENBLAS_CONST enum CBLAS_TRANSPOSE TransB,
                 OPENBLAS_CONST blasint M,
                 OPENBLAS_CONST blasint N,
                 OPENBLAS_CONST blasint K,
                 OPENBLAS_CONST double alpha,
                 OPENBLAS_CONST double *A,
                 OPENBLAS_CONST blasint lda,
                 OPENBLAS_CONST double *B,
                 OPENBLAS_CONST blasint ldb,
                 OPENBLAS_CONST double beta,
                 double *C,
                 OPENBLAS_CONST blasint ldc){

    dgemm(M, N, K, alpha, A, B, beta, C);
}