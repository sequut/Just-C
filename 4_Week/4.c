#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int calcLetters(char* iStr, int* oLowerCnt, int* oUpperCnt, int* oDigitsCnt) {
    *oLowerCnt = 0;
    *oUpperCnt = 0;
    *oDigitsCnt = 0;
    int l = 0;
    while (iStr[l] != '\0') {
        if ((iStr[l] >= '0') && (iStr[l] <= '9'))
            *oDigitsCnt += 1;
        if ((iStr[l] >= 'A') && (iStr[l] <= 'Z'))
        * oUpperCnt += 1;
        if ((iStr[l] >= 'a') && (iStr[l] <= 'z'))
            *oLowerCnt += 1;
        l += 1;
    }
    return l;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char* a;
    char aa[101];

    int n = 1;

    int sch_low = 0;
    int sch_high = 0;
    int sch_dig = 0;

    a = gets(aa);
    int len;

    while (a != NULL) {
        len = calcLetters(aa, &sch_low, &sch_high, &sch_dig);
        printf("Line %d has %d chars: %d are letters (%d lower, %d upper), %d are digits.\n", n, len, sch_low + sch_high, sch_low, sch_high, sch_dig);
        a = gets(aa);
        n += 1;
    }
    return 0;
}
