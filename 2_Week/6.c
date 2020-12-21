#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <math.h>


int SU_V_STR(int n){
    int summ = 0;
    char a;
    for (int i = 0; i < n; i++) {
        scanf("%c", &a);
        if (a == '1')
            summ += pow(2, i);
    }
    return summ;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    int su;
    scanf("%d\n", &n);
    while (n / 8 > 0) {
        printf("%d ", SU_V_STR(8));
        n -= 8;
    }
    if (n > 0) {
        printf("%d ", SU_V_STR(n));
    }

    return 0;
}
