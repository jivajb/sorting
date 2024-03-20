//JIVAJ BRAR
#include "batcher.h"

#include "stats.h"

#include <stdio.h>

void comparator(Stats *stats, int *A, int x, int y) {
    if (cmp(stats, A[x], A[y]) == 1) {
        swap(stats, &A[x], &A[y]);
    }
}

void batcher_sort(Stats *stats, int *A, int n) {
    if (n == 0) {
        return;
    }

    int t = 0, temp = n;

    while (temp > 0) { // bit length
        temp >>= 1;
        ++t;
    }
    int p = 1 << (t - 1);

    while (p > 0) {
        int q = 1 << (t - 1), r = 0, d = p;
        while (d > 0) {
            for (int i = 0; i < (n - d); ++i) {
                if ((i & p) == r) {
                    comparator(stats, A, i, (i + d));
                }
            }
            d = (q - p);
            q >>= 1;
            r = p;
        }
        p >>= 1;
    }
}
