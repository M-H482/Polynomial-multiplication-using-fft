#include "myheader.h"

void oddeven(int n, int* array)
{
    if (n == 2)
        return;
    int nHalf = n / 2, i, j, target;

    for (int i = 1; i < nHalf; i++) {
        target = array[2 * i]; // ith even num
        for (int j = 2 * i; j > i; j--) { // keep odd nums' order
            array[j] = array[j - 1];
        }
        array[i] = target;
    }
#ifdef DEBUG
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");
#endif
    oddeven(nHalf, array);
    oddeven(nHalf, array + nHalf);
}