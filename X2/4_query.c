#include <stdint.h>
extern int N;
int64_t aaa[100000];
int64_t Sum(int l, int r);

int64_t poisk(int64_t* aa, int64_t chto, int n, int l) {
    int up = n;
    int down = l;
    int tek = (n + l - 1) / 2;

    int64_t sum_do_l = aa[l - 1];

    while (up != down) {
        tek = ((up - down) / 2) + down;
        if ((aa[tek] - sum_do_l) <= chto)
            down = tek;
        else
            up = tek;
        if (up - down == 1) {
            if ((aa[up] - sum_do_l) <= chto)
                return (up + 1);
            else
                return (down + 1);
        }
    }
    return up;
}

int Query(int l, int64_t sum) {
    int64_t sum_do_l;
    //printf("%lld ", Sum(l, n-1));
    if (l > 0)
        sum_do_l = aaa[l - 1];
    else
        sum_do_l = 0;
    //printf("%lld %d %lld ", sum, l, aaa[l]);
    if (sum < (aaa[l] - sum_do_l))
        return l;

    if (Sum(l, N - 1) < sum)
        return N;

    return poisk(aaa, sum, N - 1, l);
}