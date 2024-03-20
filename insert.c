//JIVAJ BRAR insert.c
#include "insert.h"

#include "stats.h"

#include <stdio.h>

void insertion_sort(Stats *stats, int *arr, int length) {
    for (int k = 0; k < length; k++) {
        int j = k, temp = arr[k];
        while (j >= 1 && cmp(stats, arr[j - 1], temp) == 1) {
            arr[j] = move(stats, arr[j - 1]);
            j--;
        }
        move(stats, temp);
        arr[j] = temp;
    }
}
