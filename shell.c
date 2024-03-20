//JIVAJ BRAR shell.c
#include "gaps.h"
#include "stats.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void shell_sort(Stats *stats, int *A, int n) {
    for (int gap = 0; gap < GAPS; gap++) {
        if (gaps[gap] < n) {
            for (int k = gaps[gap]; k < n; k++) {
                int j = k;
                int temp = A[k];
                move(stats, temp);
                while (j >= gaps[gap] && cmp(stats, A[j - gaps[gap]], temp) == 1) {
                    A[j] = move(stats, A[j - gaps[gap]]);
                    j -= gaps[gap];
                }
                move(stats, temp);
                A[j] = temp;
            }
        }
    }
}
