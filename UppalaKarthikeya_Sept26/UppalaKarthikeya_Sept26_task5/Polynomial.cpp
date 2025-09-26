#include "Polynomial.h"

// Default constructor
Polynomial::Polynomial() {}

// Constructor
Polynomial::Polynomial(const vector<Term>& t) : terms(t) {
    simplify();
}

// Copy constructor
Polynomial::Polynomial(const Polynomial& other) {
    terms = other.terms;
}

// Destructor
Polynomial::~Polynomial() {
    terms.clear();
}

// Add term
void Polynomial::addTerm(int coeff, int exp) {
    if (coeff != 0) {
        terms.push_back({coeff, exp});
        simplify();
    }
}

// Getter
vector<Term> Polynomial::getTerms() const {
    return terms;
}
void Polynomial::simplify() {
    vector<Term> result;

    for (auto& t : terms) {
        bool found = false;
        for (auto& r : result) {
            if (r.exp == t.exp) {
                r.coeff += t.coeff;
                found = true;
                break;
            }
        }
        if (!found) result.push_back(t);
    }

    // Remove zero coeffs
    vector<Term> finalTerms;
    for (auto& r : result) {
        if (r.coeff != 0) finalTerms.push_back(r);
    }
    terms = finalTerms;
}

// Assignment operator
Polynomial& Polynomial::operator=(const Polynomial& rhs) {
    if (this != &rhs) {
        terms = rhs.terms;
    }
    return *this;
}

// Addition
Polynomial Polynomial::operator+(const Polynomial& rhs) const {
    Polynomial result(*this);
    for (auto& t : rhs.terms) {
        result.addTerm(t.coeff, t.exp);
    }
    return result;
}

// Subtraction
Polynomial Polynomial::operator-(const Polynomial& rhs) const {
    Polynomial result(*this);
    for (auto& t : rhs.terms) {
        result.addTerm(-t.coeff, t.exp);
    }
    return result;
}

// Multiplication
Polynomial Polynomial::operator*(const Polynomial& rhs) const {
    Polynomial result;
    for (auto& t1 : terms) {
        for (auto& t2 : rhs.terms) {
            result.addTerm(t1.coeff * t2.coeff, t1.exp + t2.exp);
        }
    }
    return result;
}

Polynomial& Polynomial::operator+=(const Polynomial& rhs) {
    *this = *this + rhs;
    return *this;
}


Polynomial& Polynomial::operator-=(const Polynomial& rhs) {
    *this = *this - rhs;
    return *this;
}


Polynomial& Polynomial::operator*=(const Polynomial& rhs) {
    *this = *this * rhs;
    return *this;
}

// Display
ostream& operator<<(ostream& out, const Polynomial& poly) {
    if (poly.terms.empty()) {
        out << "0";
        return out;
    }

    for (size_t i = 0; i < poly.terms.size(); i++) {
        int coeff = poly.terms[i].coeff;
        int exp = poly.terms[i].exp;

        if (i > 0 && coeff > 0) out << " + ";
        else if (coeff < 0) out << " - ";

        out << (abs(coeff));
        if (exp > 0) out << "x^" << exp;
    }
    return out;
}
