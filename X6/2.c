#include <stdio.h>

long long aa[1001][1001];

long long algo(int k, int m, int n) {
    long long help;
    if (aa[k][m] == 0) {
        if (k == n)
            return 1;

        help = 0;
        int mi = (n - k < m) ? (n - k) : m;
        for (int i = 1; i <= mi; i++){
            help += algo(k + i, i, n);
            help %= 1000000007;
        }
        aa[k][m] = help;
    }
    return aa[k][m];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    printf("%lld\n", algo(0, n, n));
    return 0;
}