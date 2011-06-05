#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Given an integer array a of size sz
 * select n elements at random and place
 * them at the end of the array.
 * If n == sz, this will cause an
 * in-place shuffle.
 * This is better known as the
 * Knuth-Fisher-Yates shuffle algorithm.
 * Select an item at random, swap it with
 * the last item in the set, now consider
 * all elements of the set minus the last.
 */

void rand_pick(int* a, int sz, int n) {
    int rand_idx, last;
    srand((unsigned)time(0));
    while (n > 0) {
        rand_idx = rand() % sz;
        last = a[sz-1];
        a[sz-1] = a[rand_idx];
        a[rand_idx] = last;
        --n; --sz;
    }
}


/* Testing the shuffler... */
int main() {
    int i, a[5] = {1,2,3,4,5};
    rand_pick(a,5,5);
    for (i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
