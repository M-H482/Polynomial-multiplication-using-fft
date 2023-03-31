#include "myheader.h"

void reorder(int n, int* x, int* bitr)
{
    for (int i = 0; i < n; i++) {
        int r = bitr[i];
        if (r > i) {
            swap(x[i], x[r]);
        }
    }
}

int main(int argc, char** argv)
{
    int n = 8;
    if (argc == 2) {
        n = atoi(argv[1]);
    } else if (argc > 2) {
        printf("Usage: exe n!\n");
        return 0;
    }
    int* array = new int[n];
    int* tmp = new int[n];
    for (int i = 0; i < n; i++)
        array[i] = tmp[i] = i;

    // oddeven(n, array);
    // moddeven(n, array, tmp);
    bitreverse(n, array);

    reorder(n, tmp, array);
    for (int i = 0; i < n; i++) {
        printf("%d ", tmp[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    delete[] array;
    return 0;
}