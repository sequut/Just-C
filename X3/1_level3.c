void dgemm (int m, int n, int k, double alpha, const double* A, const double* B, double beta, double* C){
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++){
            double su = 0;
            C[i * n + j] *= beta;
            for (int u = 0; u < k; u++)
                su += A[i * k + u] * B[u * n + j];
            C[i * n + j] += alpha*su;
        }
    }
}