#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char a;
    int aa[127] = {0};
    int n;

    while (scanf("%c", &a)==1){
        n = (int)(a);
        if (n>31)
            aa[n] += 1;
    }
    
    for (int i = 32; i < 127; i++) {
        if (aa[i] > 0) {
            printf("%c ", (char)(i));
            for (int j = 0; j < aa[i]; j++)
                printf("#");
            printf("\n");
        }
    
    } 
    return 0;
}
