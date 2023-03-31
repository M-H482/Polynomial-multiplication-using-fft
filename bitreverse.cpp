#include "myheader.h"

void bitreverse(int n, int* array)
{
    if (n < 2) {
        array[0] = 0;
        return;
    }

    array[0] = 0, array[1] = 1;

    int j = 2;
    while (j < n) {
        for (int i = 0; i < j; i++) {
            array[i] *= 2;
            array[i + j] = array[i] + 1;
        }
        j *= 2;
#ifdef DEBUG
        for (int i = 0; i < j; i++) {
            printf("%d ", array[i]);
        }
        printf("\n\n");
#endif
    }
}