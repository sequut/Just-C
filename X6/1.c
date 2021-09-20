#include <stdio.h>

int col[12], answer[12];
int hasV[12], hasH[12], hasS[24];
int hasD_help[24];
int* hasD = hasD_help + 12;

int N, M;
int sost = 0;

int aa[12][12];

void Rec(int r){
    if (sost)
        return;
    if (r == M){
        sost = 1;
        for (int i = 0; i < 12; i++)
            answer[i] = col[i];
        return;
    }
    for (int c = 0; c < N; c++){
        if (hasH[r] || hasV[c] || hasS[r + c] || hasD[r - c] || !aa[r][c])
            continue;
        col[r] = c;
        hasH[r] = hasV[c] = hasS[r + c] = hasD[r - c] = 1;
        Rec(r + 1);
        hasH[r] = hasV[c] = hasS[r + c] = hasD[r - c] = 0;
        col[r] = -1;
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d\n", &M, &N);
    char help;
    int what;
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++) {
            what = -1;
            while (what == -1){
                scanf("%c", &help);
                if (help == '?')
                    what = 1;
                else if (help == '.')
                    what = 0;
                else
                    what = -1;
            }
            aa[i][j] = what;
        }
    }

    Rec(0);

    if (sost) {
        printf("YES\n");
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (answer[i] == j)
                    printf("X");
                else
                    printf(".");
            }
            printf("\n");
        }
    }
    else
        printf("NO\n");

    return 0;
}