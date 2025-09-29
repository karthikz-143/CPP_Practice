#include "Polynomial.h"

// Default constructor
Polynomial::Polynomial() {}

// Constructor from vector of terms
Polynomial::Polynomial(const std::vector<Term>& t) : terms(t) {
    simplify();
}

// Copy constructor
Polynomial::Polynomial(const Polynomial& other) : terms(other.terms) {}

// Destructor
Polynomial::~Polynomial() {
    terms.clear();
}

// Add a term and simplify to merge like exponents
void Polynomial::addTerm(int coeff, int exp) {
    if (coeff == 0) return;
    terms.push_back({coeff, exp});
    simplify();
}

// Return stored terms (copy)
std::vector<Term> Polynomial::getTerms() const {
    return terms;
}

// Combine terms with the same exponent, remove zero coefficients,
// and sort by exponent descending for clean output.
void Polynomial::simplify() {
    if (terms.empty()) return;

    std::vector<Term> combined;
    for (const auto& t : terms) {
        bool found = false;
        for (auto& c : combined) {
            if (c.exp == t.exp) {
                c.coeff += t.coeff;
                found = true;
                break;
            }
        }
        if (!found) combined.push_back(t);
    }

    std::vector<Term> finalTerms;
    for (const auto& c : combined) {
        if (c.coeff != 0) finalTerms.push_back(c);
    }

    // Sort by exponent descending so highest power prints first
    std::sort(finalTerms.begin(), finalTerms.end(), [](const Term& a, const Term& b){
        return a.exp > b.exp;
    });

    terms = std::move(finalTerms);
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
    for (const auto& t : rhs.terms) {
        result.addTerm(t.coeff, t.exp);
    }
    return result;
}

// Subtraction
Polynomial Polynomial::operator-(const Polynomial& rhs) const {
    Polynomial result(*this);
    for (const auto& t : rhs.terms) {
        result.addTerm(-t.coeff, t.exp);
    }
    return result;
}

// Multiplication
Polynomial Polynomial::operator*(const Polynomial& rhs) const {
    Polynomial result;
    for (const auto& a : terms) {
        for (const auto& b : rhs.terms) {
            result.addTerm(a.coeff * b.coeff, a.exp + b.exp);
        }
    }
    return result;
}

// Compound assignments
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

// Stream output formatting
std::ostream& operator<<(std::ostream& out, const Polynomial& poly) {
    if (poly.terms.empty()) {
        out << "0";
        return out;
    }

    for (std::size_t i = 0; i < poly.terms.size(); ++i) {
        int coeff = poly.terms[i].coeff;
        int exp = poly.terms[i].exp;

        // sign
        if (i > 0) {
            if (coeff > 0) out << " + ";
            else out << " - ";
        } else {
            if (coeff < 0) out << "-";
        }

        int absCoeff = std::abs(coeff);

        // print coefficient: if exponent != 0 always print coefficient (keep it simple)
        out << absCoeff;

        // print variable part
        if (exp > 0) {
            out << "x^" << exp;
        }
    }
    return out;
}
