// HugeInt.h
#ifndef HUGEINT_H
#define HUGEINT_H

#include <iostream>
#include <string>
using namespace std;

class HugeInt {
    friend ostream &operator<<(ostream &, const HugeInt &);

public:
    static const int digits = 30; // max digits

    HugeInt(long = 0);             // from long
    HugeInt(const string &);       // from string

    HugeInt operator+(const HugeInt &) const;
    HugeInt operator+(int) const;
    HugeInt operator+(const string &) const;

    HugeInt operator*(const HugeInt &) const;
    HugeInt operator/(const HugeInt &) const;

    bool operator==(const HugeInt &) const;
    bool operator!=(const HugeInt &) const;
    bool operator<(const HugeInt &) const;
    bool operator<=(const HugeInt &) const;
    bool operator>(const HugeInt &) const;
    bool operator>=(const HugeInt &) const;

private:
    short integer[digits];
};

#endif
