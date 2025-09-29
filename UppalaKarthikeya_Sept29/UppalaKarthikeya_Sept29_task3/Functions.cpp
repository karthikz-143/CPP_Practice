#include "Functions.h"

// (a) Function to exchange values  and (b) prototype
void exchange(double* x, double* y)
{
    double temp = *x;
    *x = *y;
    *y = temp;
}

// (c) & (d) Function to evaluate poly(x) using function pointer
int evaluate(int x, int (*poly)(int))
{
    return poly(x);
}
