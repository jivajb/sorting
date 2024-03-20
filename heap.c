//JIVAJ BRAR heap.c

//#include "stats.h"
#include "heap.h"

#include "stats.h"

#include <stdbool.h>
#include <stdio.h>

int max_child(Stats *stats, int *A, int first, int last) {
    int left = ((2 * first) + 1), right = ((2 * first) + 2);
    if (1 == cmp(stats, A[right], A[left]) && last >= right) {
        return right;
    } else {
        return left;
    }
}

void fix_heap(Stats *stats, int *A, int first, int last) {
    int done = false, parent = first;
    while (!done && last >= (2 * parent + 1)) {
        int largest_child = max_child(stats, A, parent, last);
        if (-1 == cmp(stats, A[parent], A[largest_child])) {
            swap(stats, &A[parent], &A[largest_child]);
            parent = largest_child;
        } else {
            done = true;
        }
    }
}

void build_heap(Stats *stats, int *A, int first, int last) {
    if (last > 0) {
        for (int parent = ((last - 1) / 2); parent >= first; --parent) {
            fix_heap(stats, A, parent, last);
        }
    }
}

void heap_sort(Stats *stats, int *A, int n) {
    int first = 0, last = n - 1;
    build_heap(stats, A, first, last);
    for (int leaf = last; leaf > first; leaf--) {
        swap(stats, &A[first], &A[leaf]);
        fix_heap(stats, A, first, (leaf - 1));
    }
}
