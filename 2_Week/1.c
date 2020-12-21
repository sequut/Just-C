#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

int prost(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 1;
    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        if (prost(i) == 0)
            printf("%d\n", i);
    }
}
