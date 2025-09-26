#ifndef DOUBLESUBSCRIPTEDARRAY_H
#define DOUBLESUBSCRIPTEDARRAY_H

#include <iostream>
using namespace std;

class DoubleSubscriptedArray {
private:
    int rows;
    int cols;
    int *ptr;   // single array storing all elements

public:
    DoubleSubscriptedArray(int r = 1, int c = 1);
    DoubleSubscriptedArray(const DoubleSubscriptedArray &);
    ~DoubleSubscriptedArray();

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    // operator() for subscripting
    int &operator()(int r, int c);
    const int &operator()(int r, int c) const;

    // assignment and comparisons
    const DoubleSubscriptedArray &operator=(const DoubleSubscriptedArray &);
    bool operator==(const DoubleSubscriptedArray &) const;
    bool operator!=(const DoubleSubscriptedArray &) const;

    // input/output
    friend ostream &operator<<(ostream &, const DoubleSubscriptedArray &);
    friend istream &operator>>(istream &, DoubleSubscriptedArray &);
};

#endif
