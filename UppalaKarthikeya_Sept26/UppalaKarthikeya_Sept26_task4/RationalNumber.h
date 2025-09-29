#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include <iostream>

class RationalNumber {
private:
    int numerator;
    int denominator;

    void reduce();               // function to reduce fraction 
    int gcd(int a, int b);       // greatest common divisor
 
public:
    RationalNumber(int num = 0, int den = 1);

    // Operator overloads for arithmetic
    RationalNumber operator+(const RationalNumber& rhs) const; //Addition
    RationalNumber operator-(const RationalNumber& rhs) const; //Subtraction
    RationalNumber operator*(const RationalNumber& rhs) const; //Multiplication
    RationalNumber operator/(const RationalNumber& rhs) const; //Division

    // Relational and equality operators
    bool operator==(const RationalNumber& rhs) const; 
    bool operator!=(const RationalNumber& rhs) const;
    bool operator<(const RationalNumber& rhs) const;
    bool operator>(const RationalNumber& rhs) const;
    bool operator<=(const RationalNumber& rhs) const;
    bool operator>=(const RationalNumber& rhs) const;

    // Display function
    friend std::ostream& operator<<(std::ostream& out, const RationalNumber& rn);

};

#endif // RATIONALNUMBER_H
