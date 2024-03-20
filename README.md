Purpose: 
The purpose is to create a sorting program that sorts 8-bit integer arrays through either insert, shell, heap, quick, or batcher’s odd-even merge sort.

How to Use the Program:
Usage: ./sorting [-Hahbsqi] [-n length] [-p elements] [-r seed]

OPTIONS:
-H  Display program help and usage.

-a              Enable all sorts.
-h              Enable Heap Sort.
-b              Enable Batcher Sort.
-sortingset	Enable Shell Sort.
-q 		Enable Quick Sort.
-j              Enable Insertion Sort.

-n length  	Specify number of array elements (default: 100).
-p elements  	Specify number of elements to print (default: 100).
-r seed 	Specify random seed (default: 13371453).

Design: 
There will be a sorting.c, which brings together all of the sorting algorithms’ c files and makes the program complete. This will also be the executable. The function will take in a type of sorting algorithm, and there will be an integer value associated with the n and p values, and then the sorting algorithm will return the sorting algorithm.

Functions:
Functions
● Set set_empty(void): Returns the sets and bits to zero.
● Set set_universal(void): This would return every possibility of a member in a set.
● Set set_insert(Set s, int x): Takes an input of x, which is to be inserted into Set s, and then
moves the bits over a value of x and returns the newly updated set.
● Set set_remove(Set s, int x): This function inputs a set s and int x, and then it finds the equivalent position of x in set s and returns the set s with x removed.
● bool set_member(Set s, int x): It inputs set s and int x, and if the value of x and its equivalent position in s are the same, it’ll return true. Otherwise, it’ll return false.
● Set set_union(Set s, Set t): Inputs the set s and set t and compares them, and it is an OR operation, so if either of the sets has a 1 in the position, it’ll return a 1 in the final union set that it returns. If 0 in both, it’ll return a zero in that position.
● Set set_intersect(Set s, Set t): Inputs the sets s and t compares them as an AND operation so it will only return 1s in the position that both sets have them in. For example, 0110110 and 1101010 would return 0100010.
● Set set_difference(Set s, Set t): Inputs sets s and t and then negates t so ~t and does the AND operation to find the difference between the set s and set t. Then, it returns the integer array with the difference.
● Set set_complement(Set s): Inputs the set s and negates it so returns ~s which is the complement to set s.
● Batcher’s Odd-Even Merge Sort:
● int cmp(Stats *stats, int x, int y): Inputs and compares x and y. If x > y returns 1; if x = y,
returns 0; if x < y returns -1. This function is given to us.
● int move(Stats *stats, int x): Inputs stats and int x the stats field would give the
jump/move amount and the x is the integer that moves. Returns new x. This function is
given to us.
● void swap(Stats *stats, int *x, int *y): Inputs stats and int pointers x and y. Swaps x and y
and uses the +3 move stated by stats so that there is a temporary variable.
● void reset(Stats *stats): Resets the stats field to 0 which changes the move amount.
● void print_stats(Stats *stats, const char *algorithm_name, int num_elements): Inputs
stats, the algorithm name, and elements. Prints stats, movement, and final values.
