#include "integerset.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int comp (const void *a, const void *b){
    long int aa = *((int*)a);
    long int bb = *((int*)b);
    if (aa == bb)
        return 0;
    else if (aa > bb)
        return 1;
    else
        return -1;
}

IntegerSet* CreateSet(int* arr, int n){
    IntegerSet* answ = calloc(1, sizeof(IntegerSet));
    if (!answ)
        exit(666);

    answ->length = n;
    if (n != 0){
        answ->arr = (int*)calloc(n, sizeof(int));
        if (!answ->arr)
            exit(666);
        memcpy(answ->arr, arr, answ->length*sizeof(int));
        qsort(answ->arr, n, sizeof(int), comp);
        int sost = 0;
        for (int i = 1; i < n; i++)
            if (answ->arr[i] == answ->arr[i - 1]) {
                sost = 1;
                break;
            }
        if (sost){
            free(answ->arr);
            free(answ);
            return 0;
        }
    }
    return answ;
}

int IsInSet(IntegerSet* aa, int chto) {
    if (!aa || aa->length == 0)
        return 0;

    int* answ = (int*)bsearch(&chto, aa->arr, aa->length, sizeof(int), comp);
    if (!answ)
        return 0;
    return 1;
}