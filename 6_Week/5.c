#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

typedef struct sList {
    char value[8];
    int next;
    int last;
} List;

void printList(List* aa, int ind, int* first) {
    int sch = first[ind];
    printf("%d %s\n", ind, aa[sch].value);
    sch = aa[sch].next;
    while (sch != 0) {
        printf("%d %s\n", ind, aa[sch].value);
        sch = aa[sch].next;
    }
}
int first[1000001];

int main() {

    int n;
    char str[8];
    int ind;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    List* aa = (List*)calloc((1000000 + 1), sizeof(List));
    if (aa == 0)
        return 0;

    for (int i = 0; i < 1000001; i++)
        first[i] = -1;


    for (int i = 0; i < n; i++) {
        scanf("%d %s\n", &ind, str);

        strcpy(aa[i].value, str);
        
        if (first[ind] == -1) {
            first[ind] = i;
            aa[i].last = i;
        }
        else {
            aa[aa[first[ind]].last].next = i;
            aa[first[ind]].last = i;
        }
    }

    for (int i = 0; i < 1000001; i++)
        if (first[i] != -1)
            printList(aa, i, first);

    free(aa);
    return 0;
}
