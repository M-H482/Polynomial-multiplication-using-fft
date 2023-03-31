set -v

g++ -O2 bitreverse.cpp fft.cpp polyMul.cpp -o polyMul
g++ -O2 bitreverse.cpp moddeven.cpp oddeven.cpp  test.cpp -o test