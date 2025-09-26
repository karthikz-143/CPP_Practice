// HugeInt.cpp
#include <cctype>
#include "HugeInt.h"
using namespace std;

// long constructor
HugeInt::HugeInt(long value) {
    for (int i = 0; i < digits; i++)
        integer[i] = 0;

    for (int j = digits - 1; value != 0 && j >= 0; j--) {
        integer[j] = value % 10;
        value /= 10;
    }
}

// string constructor
HugeInt::HugeInt(const string &number) {
    for (int i = 0; i < digits; i++)
        integer[i] = 0;

    int length = number.size();
    for (int j = digits - length, k = 0; j < digits; j++, k++)
        if (isdigit(number[k]))
            integer[j] = number[k] - '0';
}

// addition
HugeInt HugeInt::operator+(const HugeInt &op2) const {
    HugeInt temp;
    int carry = 0;

    for (int i = digits - 1; i >= 0; i--) {
        temp.integer[i] = integer[i] + op2.integer[i] + carry;
        if (temp.integer[i] > 9) {
            temp.integer[i] %= 10;
            carry = 1;
        } else {
            carry = 0;
        }
    }
    return temp;
}

HugeInt HugeInt::operator+(int op2) const {
    return *this + HugeInt(op2);
}

HugeInt HugeInt::operator+(const string &op2) const {
    return *this + HugeInt(op2);
}

// multiplication
HugeInt HugeInt::operator*(const HugeInt &op2) const {
    HugeInt result;

    for (int i = digits - 1; i >= 0; i--) {
        int carry = 0;
        for (int j = digits - 1, k = digits - 1 - (digits - 1 - i);
             j >= 0 && k >= 0; j--, k--) {
            int prod = integer[i] * op2.integer[j] + result.integer[k] + carry;
            result.integer[k] = prod % 10;
            carry = prod / 10;
        }
    }
    return result;
}

// division (naive long division)
HugeInt HugeInt::operator/(const HugeInt &op2) const {
    HugeInt zero(0);
    HugeInt one(1);
    HugeInt quotient(0);
    HugeInt remainder(*this);

    while (remainder >= op2) {
        HugeInt temp = remainder;
        int count = 0;
        while (temp >= op2) {
            temp = temp + HugeInt(-1); // simple decrement
            count++;
        }
        remainder = temp;
        quotient = quotient + HugeInt(count);
    }
    return quotient;
}

// comparisons
bool HugeInt::operator==(const HugeInt &op2) const {
    for (int i = 0; i < digits; i++)
        if (integer[i] != op2.integer[i])
            return false;
    return true;
}

bool HugeInt::operator!=(const HugeInt &op2) const {
    return !(*this == op2);
}

bool HugeInt::operator<(const HugeInt &op2) const {
    for (int i = 0; i < digits; i++) {
        if (integer[i] < op2.integer[i]) return true;
        if (integer[i] > op2.integer[i]) return false;
    }
    return false;
}

bool HugeInt::operator<=(const HugeInt &op2) const {
    return *this < op2 || *this == op2;
}

bool HugeInt::operator>(const HugeInt &op2) const {
    return !(*this <= op2);
}

bool HugeInt::operator>=(const HugeInt &op2) const {
    return !(*this < op2);
}

// output
ostream& operator<<(ostream &output, const HugeInt &num) {
    int i;
    for (i = 0; (num.integer[i] == 0) && (i < HugeInt::digits - 1); i++);
    for (; i < HugeInt::digits; i++)
        output << num.integer[i];
    return output;
}
