#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <math.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char ch;
    int k = 0;
    int sch = 0;
    scanf("%c", &ch);

    if (ch != '.') {
        sch = 1; //начало слова
        k += 1;
    }
    else
        sch = 2;

    while (ch != '\n') {

        if ((ch != '.') && (ch!=' ')) {
            if (sch == 2)
                k += 1;
            sch = 1; //начало слова/ идет слово
        }
            
            else
                sch = 2; //начало слова
        scanf("%c", &ch);
    }
    printf("%d", k);
    return 0;
}
