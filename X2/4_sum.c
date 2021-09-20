#include <stdint.h>
int N;
int64_t aaa[100011] = { 0 };
void Init(const int* arr, int n) {
    aaa[0] = arr[0];
    N = n;
    for (int i = 1; i < n; i++)
        aaa[i] = arr[i] + aaa[i - 1];
}
int64_t Sum(int l, int r) {
    if (l == 0)
        return (aaa[r]);
    else
        return (aaa[r] - aaa[l - 1]);
}