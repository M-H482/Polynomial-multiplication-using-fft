#include <cmath>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

// #define DEBUG

void oddeven(int n, int* array);
void moddeven(int n, int* array, int* tmp);
void bitreverse(int n, int* array);

void fft(int n, complex<double>* x, complex<double>* y);
void dft(int n, complex<double>* x, complex<double>* y);