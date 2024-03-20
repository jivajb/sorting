//JIVAJ BRAR quick.c
#include "quick.h"

#include "stats.h"

#include <stdio.h>

int partition(Stats *stats, int *A, int low, int high) {
    int ppivot = A[high], i = low;
    for (int j = low; j < high; ++j) {
        if (0 <= cmp(stats, ppivot, A[j])) {
            swap(stats, &A[i], &A[j]);
            ++i;
        }
    }
    swap(stats, &A[i], &A[high]);
    return i;
}

void recursion(Stats *stats, int *A, int low, int high) {
    if (high > low) {
        int rpivot = partition(stats, A, low, high);
        recursion(stats, A, low, rpivot - 1);
        recursion(stats, A, rpivot + 1, high);
    }
}

void quick_sort(Stats *stats, int *A, int n) {
    recursion(stats, A, 0, n - 1);
}
