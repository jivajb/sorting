// JIVAJ BRAR sorting.c
#include "batcher.h"
#include "heap.h"
#include "insert.h"
#include "quick.h"
#include "set.h"
#include "shell.h"
#include "stats.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define HELP1 "Select at least one sort to perform.\n"
#define HELP                                                                                       \
    "SYNOPSIS\n   A collection of comparison-based sorting algorithms.\n\nUSAGE\n   ./sorting "    \
    "[-Hahbsqi] [-n length] [-p elements] [-r seed]\n\nOPTIONS\n   -H              Display "       \
    "program help and usage.\n   -a              Enable all sorts.\n   -h              Enable "    \
    "Heap Sort.\n   -b              Enable Batcher Sort.\n   -sortingset              Enable "     \
    "Shell Sort.\n   -q              Enable Quick Sort.\n   -j              Enable Insertion "     \
    "Sort.\n   -n length       Specify number of array elements (default: 100).\n   -p elements  " \
    "   Specify number of elements to print (default: 100).\n   -r seed         Specify random "   \
    "seed (default: 13371453).\n"

int main(int argc, char **argv) {

    char sortoptions[] = "Hahbsqin:p:r:", *temppointer;
    int userinp, num_elements = 100, disp = 100;
    unsigned seed = 13371453;

    Set sortingset = set_empty();
    Stats stats;
    reset(&stats);
    while (-1 != (userinp = getopt(argc, argv, sortoptions))) {
        switch (userinp) {
        case 'H': fprintf(stderr, HELP); exit(1);
        case 'a':
            sortingset = set_empty();
            sortingset = set_complement(sortingset);
            break;

        case 'h': sortingset = set_insert(sortingset, 0); break;

        case 'b': sortingset = set_insert(sortingset, 1); break;

        case 's': sortingset = set_insert(sortingset, 2); break;

        case 'q': sortingset = set_insert(sortingset, 3); break;

        case 'i': sortingset = set_insert(sortingset, 4); break;

        case 'n': num_elements = strtol(optarg, &temppointer, 10); break;

        case 'p': disp = strtol(optarg, &temppointer, 10); break;

        case 'r': seed = strtol(optarg, &temppointer, 10); break;

        default: break;
        }
    }

    if (sortingset == set_empty()) {
        fprintf(stderr, HELP1);
        fprintf(stderr, HELP);
    }

    if (num_elements < disp) {
        disp = num_elements;
    }
    srandom(seed);
    //int* mainarray = (int*)malloc(num_elements*2*sizeof(int));
    int mainarray[99999];
    int count = 0;
    for (int j = 0; j < num_elements; j++) {
        mainarray[j] = (random() & 0x3FFFFFFF);
        ;
    }

    if (true == set_member(sortingset, 4)) {
        //int* arrayi = (int*)malloc(num_elements*sizeof(int));
        int arrayi[99999];
        for (int j = 0; j < num_elements; j++) {
            arrayi[j] = mainarray[j];
        }
        insertion_sort(&stats, arrayi, num_elements);
        print_stats(&stats, "Insertion Sort", num_elements);
        reset(&stats);
        count = 0;
        for (int x = 0; x < disp; x++) {
            if (count == 5) {
                printf("\n");
                count = 0;
            }
            printf("%13d", arrayi[x]);
            count++;
        }
        if (disp != 0) {
            printf("\n");
        }
        //free(arrayi);
    }
    if (true == set_member(sortingset, 0)) {
        //int* arrayh = (int*)malloc(num_elements*sizeof(int));
        int arrayh[99999];
        for (int j = 0; j < num_elements; j++) {
            arrayh[j] = mainarray[j];
        }
        heap_sort(&stats, arrayh, num_elements);
        print_stats(&stats, "Heap Sort", num_elements);
        reset(&stats);

        count = 0;
        for (int x = 0; x < disp; x++) {
            if (count == 5) {
                printf("\n");
                count = 0;
            }

            printf("%13d", arrayh[x]);
            count++;
        }
        if (disp != 0) {
            printf("\n");
        }
        //free(arrayh);
    }

    if (true == set_member(sortingset, 2)) {

        //int* arrays = (int*)malloc(num_elements*sizeof(int));
        int arrays[99999];
        for (int j = 0; num_elements > j; j++) {
            arrays[j] = mainarray[j];
        }
        shell_sort(&stats, arrays, num_elements);
        print_stats(&stats, "Shell Sort", num_elements);
        reset(&stats);

        count = 0;
        for (int x = 0; x < disp; x++) {
            if (count == 5) {
                printf("\n");
                count = 0;
            }
            printf("%13d", arrays[x]);
            count++;
        }
        if (disp != 0) {
            printf("\n");
        }
        //free(arrays);
    }

    if (set_member(sortingset, 3) == true) {
        //int* arrayq = (int*)malloc(num_elements*sizeof(int));
        int arrayq[99999];
        for (int j = 0; num_elements > j; j++) {
            arrayq[j] = mainarray[j];
        }
        quick_sort(&stats, arrayq, num_elements);
        print_stats(&stats, "Quick Sort", num_elements);
        reset(&stats);
        count = 0;
        for (int x = 0; x < disp; x++) {
            if (count == 5) {
                printf("\n");
                count = 0;
            }
            printf("%13d", arrayq[x]);
            count++;
        }
        if (disp != 0) {
            printf("\n");
        }
        //free(arrayq);
    }

    if (set_member(sortingset, 1) == true) {
        //int* arrayb = (int*)malloc(num_elements*sizeof(int));
        int arrayb[99999];
        for (int j = 0; num_elements > j; j++) {
            arrayb[j] = mainarray[j];
        }
        batcher_sort(&stats, arrayb, num_elements);
        print_stats(&stats, "Batcher Sort", num_elements);
        reset(&stats);
        count = 0;
        for (int x = 0; x < disp; x++) {
            if (count == 5) {
                printf("\n");
                count = 0;
            }

            printf("%13d", arrayb[x]);
            count++;
        }
        if (disp != 0) {
            printf("\n");
        }
        //free(arrayb);
    }
    //free(mainarray);
    return 0;
}
