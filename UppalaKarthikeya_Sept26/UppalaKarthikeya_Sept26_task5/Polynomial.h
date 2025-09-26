#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <vector>
using namespace std;

struct Term {
    int coeff;
    int exp;
};

class Polynomial {
private:
    vector<Term> terms;
    void simplify(); // combine like terms

public:
    Polynomial();
    Polynomial(const vector<Term>& t);
    Polynomial(const Polynomial& other); // copy constructor
    ~Polynomial();

    // Setters & Getters
    void addTerm(int coeff, int exp);
    vector<Term> getTerms() const;

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
    friend ostream& operator<<(ostream& out, const Polynomial& poly);
};

#endif
