#include "RationalNumber.h"

// Utility: GCD
int RationalNumber::gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

// Reduce fraction
void RationalNumber::reduce() {
    int divisor = gcd(abs(numerator), abs(denominator));
    numerator /= divisor;
    denominator /= divisor;

    // Avoid negative denominators
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

// Constructor
RationalNumber::RationalNumber(int num, int den) {
    if (den == 0) {
        cout << "Error: Denominator cannot be zero. Setting to 1.\n";
        denominator = 1;
    } else {
        denominator = den;
    }
    numerator = num;
    reduce();
}

// Arithmetic operators
RationalNumber RationalNumber::operator+(const RationalNumber& rhs) const {
    return RationalNumber(numerator * rhs.denominator + rhs.numerator * denominator,
                          denominator * rhs.denominator);
}

RationalNumber RationalNumber::operator-(const RationalNumber& rhs) const {
    return RationalNumber(numerator * rhs.denominator - rhs.numerator * denominator,
                          denominator * rhs.denominator);
}

RationalNumber RationalNumber::operator*(const RationalNumber& rhs) const {
    return RationalNumber(numerator * rhs.numerator,
                          denominator * rhs.denominator);
}

RationalNumber RationalNumber::operator/(const RationalNumber& rhs) const {
    return RationalNumber(numerator * rhs.denominator,
                          denominator * rhs.numerator);
}

// Relational & equality
bool RationalNumber::operator==(const RationalNumber& rhs) const {
    return (numerator == rhs.numerator && denominator == rhs.denominator);
}

bool RationalNumber::operator!=(const RationalNumber& rhs) const {
    return !(*this == rhs);
}

bool RationalNumber::operator<(const RationalNumber& rhs) const {
    return (numerator * rhs.denominator < rhs.numerator * denominator);
}

bool RationalNumber::operator>(const RationalNumber& rhs) const {
    return rhs < *this;
}

bool RationalNumber::operator<=(const RationalNumber& rhs) const {
    return !(*this > rhs);
}

bool RationalNumber::operator>=(const RationalNumber& rhs) const {
    return !(*this < rhs);
}

// Output
ostream& operator<<(ostream& out, const RationalNumber& rn) {
    if (rn.denominator == 1)
        out << rn.numerator;
    else
        out << rn.numerator << "/" << rn.denominator;
    return out;
}
