#include "myheader.h"

void init(int n, vector<complex<double>>& a1, vector<complex<double>>& a2)
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++) {
        a1[i] = rand() % 10;
    }
    for (int i = 0; i < n; i++) {
        a2[i] = rand() % 10;
    }
}

void carry(int len, vector<complex<double>>& c)
{
    int t = 0;
    for (int i = 0; i < len; i++) {
        int r = c[i].real();
        c[i].real((r + t) % 10);
        t = (r + t) / 10;
    }
}

void mul(int n, vector<complex<double>>& a, vector<complex<double>>& b,
    vector<complex<double>>& c)
{
    int m = 2 * n;

    vector<complex<double>> y1(m);
    vector<complex<double>> y2(m);
    vector<complex<double>> t(m);

    fft(m, a.data(), y1.data());
    fft(m, b.data(), y2.data());

    for (int i = 0; i < m; i++) {
        t[i] = y1[i] * y2[i];
    }

    dft(m, t.data(), c.data());

    carry(m, c);
}

void baseline(int n, vector<complex<double>>& a, vector<complex<double>>& b,
    vector<complex<double>>& c)
{
    int m = n * 2;
    for (int i = 0; i < m; i++) {
        complex<double> sum(0.0, 0.0);
        for (int j = 0; j <= i; j++) {
            {
                sum += a[j] * b[i - j];
            }
        }
        c[i] = sum;
    }
    carry(m, c);
}

bool check(double threshold, int m, vector<complex<double>>& c1, vector<complex<double>>& c2)
{
    for (int i = 0; i < m; i++) {
        if (fabs(c1[i].real() - c2[i].real()) > threshold
            || fabs(c1[i].imag() - c2[i].imag()) > threshold) {
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv)
{
    int n = 8, m;
    if (argc == 2) {
        n = atoi(argv[1]);
    } else if (argc > 2) {
        printf("Usage: exe n!\n");
        return 0;
    }

    m = 2 * n;
    vector<complex<double>> a(m);
    vector<complex<double>> b(m);

    vector<complex<double>> c1(m);
    vector<complex<double>> c2(m);

    init(n, a, b);

    mul(n, a, b, c1);

    baseline(n, a, b, c2);

    printf("A:\n");
    for (int i = 0; i < m; i++) {
        printf("%.0lf ", a[i].real());
    }
    printf("\n");

    printf("B:\n");
    for (int i = 0; i < m; i++) {
        printf("%.0lf ", b[i].real());
    }
    printf("\n");

    printf("C1 fft:\n");
    for (int i = 0; i < m; i++) {
        printf("%.0lf ", c1[i].real());
    }
    printf("\n");

    printf("C2 baseline:\n");
    for (int i = 0; i < m; i++) {
        printf("%.0lf ", c2[i].real());
    }
    printf("\n");
    return 0;
}