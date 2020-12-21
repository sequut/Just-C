#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int vs_opr(int* aa, int n) {
    for (int i = 1; i <= n; i++) {
        if (*(aa + i) == 0)
            return 0;
    }
    return 1;
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    int sost_3 = 1;
    int x, y;
    int n, m;
    int stat_f = 1;
    scanf("%d %d", &n, &m);

    int* aa = (int*)malloc((n+1) * sizeof(int));
    int* bb = (int*)malloc((n+1) * sizeof(int));

    if (aa == 0){
        free(bb);
        return 0;
    }
    if (bb == 0){
        free(aa);
        return 0;
    }

    for (int i = 0; i <= n; i++) {
        aa[i] = 0;
        bb[i] = 0;
    }

    int sv[5] = { 0 };  

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        if ((aa[x] != 0) && (aa[x] != y)) {
            stat_f = 0;
            break;
        }

        if ((bb[y] != 0) && (bb[y] != x))
            sost_3 = 0;

        aa[x] = y;
        bb[y] = x;
    }

    if (stat_f == 0) {
        printf("0");
        free(aa);
        free(bb);
        return 0;
    }


    sv[0] = 1;
    printf("1 ");

    if (vs_opr(aa, n) == 1)
        sv[1] = 1;

    if (sost_3 == 1)
        sv[2] = 1;

    if (vs_opr(bb, n) == 1)
        sv[3] = 1;

    if (sv[2] == 1 && sv[3] == 1)
        sv[4] = 1;


    for (int i = 1; i < 5; i++)
        if (sv[i] == 1)
            printf("%d ", i+1);   
  
    free(aa);
    free(bb);
    
    return 0;
}
