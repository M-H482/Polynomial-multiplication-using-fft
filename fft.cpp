#include "myheader.h"

void reorder(int n, complex<double>* a, complex<double>* A, int* bitr)
{
    for (int i = 0; i < n; i++) {
        A[i] = a[bitr[i]];
    }
}

void fft(int n, complex<double>* a, complex<double>* A)
{
    int* bitr = new int[n];
    bitreverse(n, bitr);

    reorder(n, a, A, bitr);

    int m = 2, mh = 1;
    const double Pi = atan(1.0) * 4.0;
    complex<double> twoPiI = 2.0 * Pi * complex<double>(0.0, 1.0);
    complex<double> t, u;

    while (m <= n) {
        complex<double> wm = exp(twoPiI / complex<double>(m, 0.0));

        for (int k = 0; k < n; k += m) {

            complex<double> w(1.0, 0.0);

            for (int j = 0; j < mh; j++) {
                t = w * A[k + j + mh];
                u = A[k + j];

                A[k + j] = u + t;
                A[k + j + mh] = u - t;
                w = w * wm;
            }
        }
        mh = m;
        m = m * 2;
    }

    delete[] bitr;
}

void dft(int n, complex<double>* y, complex<double>* A)
{
    int* bitr = new int[n];
    bitreverse(n, bitr);

    reorder(n, y, A, bitr);

    int m = 2, mh = 1;
    const double Pi = atan(1.0) * 4.0;
    complex<double> twoPiI = 2.0 * Pi * complex<double>(0.0, 1.0);
    complex<double> t, u;

    while (m <= n) {
        // wm => wm^(-1)
        complex<double> wm = exp(twoPiI / complex<double>(-1.0 * m, 0.0));

        for (int k = 0; k < n; k += m) {

            complex<double> w(1.0, 0.0);

            for (int j = 0; j < mh; j++) {
                t = w * A[k + j + mh];
                u = A[k + j];

                A[k + j] = u + t;
                A[k + j + mh] = u - t;
                w = w * wm;
            }
        }
        mh = m;
        m = m * 2;
    }

    // divide n
    complex<double> invn(1.0 / n, 0.0);
    for (int i = 0; i < n; i++) {
        A[i] = A[i] * invn;
    }

    delete[] bitr;
}
