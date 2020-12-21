#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

char* concat(char* pref, char* suff) {
    int i = 0;
    while (suff[i] != '\0') {
        pref[i] = suff[i];
        i += 1;
    }
    pref[i] = suff[i];
   
    
    return (pref + i);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;

    char aa[1000001];
    char bb[10001];
    char* a = aa;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        gets(bb);
        a = concat(a, bb);

    }
    printf("%s", aa);
    
    return 0;
}
