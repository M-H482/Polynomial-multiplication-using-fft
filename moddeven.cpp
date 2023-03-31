#include "myheader.h"

void icopy(int n, int* x, int stride_x, int* y, int stride_y)
{
    int i, idx_x = 0, idx_y = 0;
    for (i = 0; i < n; i++) {
        y[idx_y] = x[idx_x];

        idx_y += stride_y;
        idx_x += stride_x;
    }
}

void moddeven(int n, int* array, int* tmp)
{
    if (n == 2)
        return;
    int nHalf = n / 2;
    icopy(nHalf, array, 2, tmp, 1);
    icopy(nHalf, array + 1, 2, tmp + nHalf, 1);
    icopy(n, tmp, 1, array, 1);
#ifdef DEBUG
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");
#endif
    moddeven(nHalf, array, tmp);
    moddeven(nHalf, array + nHalf, tmp);
}