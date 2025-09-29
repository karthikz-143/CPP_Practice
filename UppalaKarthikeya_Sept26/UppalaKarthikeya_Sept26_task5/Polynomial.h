#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <vector>
#include <algorithm> 
#include <cmath>     

struct Term {
    int coeff;
    int exp;
};

class Polynomial {
private:
    std::vector<Term> terms;
    void simplify(); // combine like terms, remove zeros, sort by exponent

public:
    Polynomial();
    Polynomial(const std::vector<Term>& t);
    Polynomial(const Polynomial& other); // copy constructor
    ~Polynomial();

    // Setters & Getters
    void addTerm(int coeff, int exp);
    std::vector<Term> getTerms() const;

    // Assignment operator
    Polynomial& operator=(const Polynomial& rhs);

    // Arithmetic operators
    Polynomial operator+(const Polynomial& rhs) const;
    Polynomial operator-(const Polynomial& rhs) const;
    Polynomial operator*(const Polynomial& rhs) const;

    // Compound assignment operators
    Polynomial& operator+=(const Polynomial& rhs);
    Polynomial& operator-=(const Polynomial& rhs);
    Polynomial& operator*=(const Polynomial& rhs);

    // Display
    friend std::ostream& operator<<(std::ostream& out, const Polynomial& poly);
};

#endif // POLYNOMIAL_H
