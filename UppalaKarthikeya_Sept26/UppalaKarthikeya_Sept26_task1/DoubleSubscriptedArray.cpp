#include "DoubleSubscriptedArray.h"
#include <iomanip>
#include <stdexcept>

// constructor
DoubleSubscriptedArray::DoubleSubscriptedArray(int r, int c) 
    : rows(r > 0 ? r : 1), cols(c > 0 ? c : 1) {
    ptr = new int[rows * cols]();
}

// copy constructor
DoubleSubscriptedArray::DoubleSubscriptedArray(const DoubleSubscriptedArray &other)
    : rows(other.getRows()), cols(other.getCols()) {
    ptr = new int[rows * cols];
    for (int i = 0; i < rows * cols; ++i)
        ptr[i] = other.ptr[i];
}

// destructor
DoubleSubscriptedArray::~DoubleSubscriptedArray() {
    delete[] ptr;
}

// operator()
int &DoubleSubscriptedArray::operator()(int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols)
        throw std::out_of_range("Subscript out of range");
    return ptr[r * cols + c];
}

const int &DoubleSubscriptedArray::operator()(int r, int c) const {
    if (r < 0 || r >= rows || c < 0 || c >= cols)
        throw std::out_of_range("Subscript out of range");
    return ptr[r * cols + c];
}

// assignment
const DoubleSubscriptedArray &DoubleSubscriptedArray::operator=(const DoubleSubscriptedArray &rhs) {
    if (this != &rhs) {
        if (rows * cols != rhs.getRows() * rhs.getCols()) {
            delete[] ptr;
            rows = rhs.getRows();
            cols = rhs.getCols();
            ptr = new int[rows * cols];
        }
        for (int i = 0; i < rows * cols; ++i)
            ptr[i] = rhs.ptr[i];
    }
    return *this;
}

// equality
bool DoubleSubscriptedArray::operator==(const DoubleSubscriptedArray &rhs) const {
    if (rows != rhs.getRows() || cols != rhs.getCols())
        return false;
    for (int i = 0; i < rows * cols; ++i)
        if (ptr[i] != rhs.ptr[i])
            return false;
    return true;
}

bool DoubleSubscriptedArray::operator!=(const DoubleSubscriptedArray &rhs) const {
    return !(*this == rhs);
}

// output
std::ostream &operator<<(std::ostream &out, const DoubleSubscriptedArray &a) {
    for (int i = 0; i < a.getRows(); ++i) {
        for (int j = 0; j < a.getCols(); ++j)
            out << std::setw(4) << a(i, j);
        out << '\n';
    }
    return out;
}

// input
std::istream &operator>>(std::istream &in, DoubleSubscriptedArray &a) {
    for (int i = 0; i < a.getRows() * a.getCols(); ++i)
        in >> a.ptr[i]; // allowed since operator>> is a friend
    return in;
}
