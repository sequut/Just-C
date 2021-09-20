void dgemv (int m, int n, double alpha, const double* A, const double* X, double beta, double* Y){
    for (int i = 0; i < m; i++){
        double su = 0;
        Y[i] *= beta;
        for (int j = 0; j < n; j++)
            su += A[i * n + j] * X[j];
        Y[i] += su * alpha;
    }
}
void dger (int m, int n, double alpha, const double* X, const double* Y, double* A){
    double tek;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            tek = alpha * X[i] * Y[j];
            A[i * n + j] += tek;
        }
    }
}