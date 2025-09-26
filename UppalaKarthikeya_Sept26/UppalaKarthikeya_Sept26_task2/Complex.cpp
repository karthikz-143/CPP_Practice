#include "Complex.h"
#include <cmath>    
#include <ios>      

Complex::Complex(double realPart, double imaginaryPart)
    : real(realPart), imaginary(imaginaryPart) { }

Complex Complex::operator+(const Complex &other) const {
    return Complex(real + other.real, imaginary + other.imaginary);
}

Complex Complex::operator-(const Complex &other) const {
    return Complex(real - other.real, imaginary - other.imaginary);
}

// (a+bi) * (c+di) = (ac - bd) + (ad + bc)i
Complex Complex::operator*(const Complex &other) const {
    double r = real * other.real - imaginary * other.imaginary;
    double i = real * other.imaginary + imaginary * other.real;
    return Complex(r, i);
}

bool Complex::operator==(const Complex &other) const {
    const double EPS = 1e-9; // tolerance for floating-point comparison
    return (std::fabs(real - other.real) < EPS) &&
           (std::fabs(imaginary - other.imaginary) < EPS);
}

bool Complex::operator!=(const Complex &other) const {
    return !(*this == other);
}

// Output format: (real, imaginary)
std::ostream& operator<<(std::ostream &out, const Complex &c) {
    out << '(' << c.real << ", " << c.imaginary << ')';
    return out;
}

// Input format: (real, imaginary)
std::istream& operator>>(std::istream &in, Complex &c) {
    char ch;
    double r, i;

    if (!(in >> ch) || ch != '(') { in.setstate(std::ios::failbit); return in; }
    if (!(in >> r)) { in.setstate(std::ios::failbit); return in; }
    if (!(in >> ch) || ch != ',') { in.setstate(std::ios::failbit); return in; }
    if (!(in >> i)) { in.setstate(std::ios::failbit); return in; }
    if (!(in >> ch) || ch != ')') { in.setstate(std::ios::failbit); return in; }

    c.real = r;
    c.imaginary = i;
    return in;
}
