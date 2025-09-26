#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
public:
    Complex(double = 0.0, double = 0.0);

    Complex operator+(const Complex&) const;
    Complex operator-(const Complex&) const;
    Complex operator*(const Complex&) const; // multiplication

    bool operator==(const Complex&) const;
    bool operator!=(const Complex&) const;

    // stream operators
    friend std::ostream& operator<<(std::ostream&, const Complex&);
    friend std::istream& operator>>(std::istream&, Complex&);

private:
    double real;
    double imaginary;
};

#endif // COMPLEX_H
