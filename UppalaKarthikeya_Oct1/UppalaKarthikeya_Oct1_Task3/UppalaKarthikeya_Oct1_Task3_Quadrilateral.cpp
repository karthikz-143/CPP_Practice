#include "UppalaKarthikeya_Oct1_Task3_Quadrilateral.h"
#include <cmath>

Quadrilateral::Quadrilateral(const float sideVals[4], const float angleVals[4])
{
    sides = new float[4];
    angles = new float[4];
    for(int i=0; i<4; i++) {
        sides[i] = sideVals[i];
        angles[i] = angleVals[i];
    }
}

Quadrilateral::Quadrilateral(const Quadrilateral& other)
{
    sides = new float[4];
    angles = new float[4];
    for(int i=0; i<4; i++) {
        sides[i] = other.sides[i];
        angles[i] = other.angles[i];
    }
}

Quadrilateral& Quadrilateral::operator=(const Quadrilateral& other)
{
    if(this != &other) {
        delete[] sides;
        delete[] angles;
        sides = new float[4];
        angles = new float[4];
        for(int i=0; i<4; i++) {
            sides[i] = other.sides[i];
            angles[i] = other.angles[i];
        }
    }
    return *this;
}

Quadrilateral::~Quadrilateral()
{
    delete[] sides;
    delete[] angles;
}

bool Quadrilateral::isValid() const
{
    float sum = 0.0f;
    for(int i=0; i<4; i++) {
        sum += angles[i];
    }
    return (std::fabs(sum - 360.0f) < 0.01f);
}

float Quadrilateral::area() const { return 0.0f; }

std::string Quadrilateral::type() const { return "Quadrilateral"; }

float Quadrilateral::perimeter() const
{
    float sum = 0.0f;
    for(int i=0; i<4; i++) {
        sum += sides[i];
    }
    return sum;
}

bool Quadrilateral::operator==(const Quadrilateral& other) const
{
    return std::fabs(this->area() - other.area()) < 0.01f;
}

std::ostream& operator<<(std::ostream& os, const Quadrilateral& q)
{
    os << q.type() << " [Sides: ";
    for(int i=0; i<4; i++) {
        os << q.sides[i] << " ";
    }
    os << "Angles: ";
    for(int i=0; i<4; i++) {
        os << q.angles[i] << " ";
    }
    os << "] Area: " << q.area();
    return os;
}

Quadrilateral::operator float() const { return this->area(); }

float Quadrilateral::operator()() const { return this->perimeter(); }

// Trapezoid
Trapezoid::Trapezoid(const float sideVals[4], const float angleVals[4]) 
: Quadrilateral(sideVals, angleVals) {}

bool Trapezoid::isValid() const
{
    return Quadrilateral::isValid();
}

float Trapezoid::area() const
{
    return (sides[0] + sides[2]) / 2.0f * 5.0f; // dummy height
}

std::string Trapezoid::type() const { return "Trapezoid"; }

// Parallelogram
Parallelogram::Parallelogram(const float sideVals[4], const float angleVals[4])
: Trapezoid(sideVals, angleVals) {}

bool Parallelogram::isValid() const
{
    return Quadrilateral::isValid();
}

float Parallelogram::area() const
{
    float rad = angles[0] * 3.14159f / 180.0f;
    return sides[0] * sides[1] * std::sin(rad);
}

std::string Parallelogram::type() const { return "Parallelogram"; }

// Rectangle
Rectangle::Rectangle(const float sideVals[4], const float angleVals[4])
: Parallelogram(sideVals, angleVals) {}

bool Rectangle::isValid() const
{
    return Quadrilateral::isValid() && 
           std::fabs(angles[0]-90.0f)<0.01f && 
           std::fabs(angles[1]-90.0f)<0.01f;
}

float Rectangle::area() const { return sides[0] * sides[1]; }

std::string Rectangle::type() const { return "Rectangle"; }

// Square
Square::Square(const float sideVals[4], const float angleVals[4])
: Rectangle(sideVals, angleVals) {}

bool Square::isValid() const
{
    return Rectangle::isValid() && 
           std::fabs(sides[0]-sides[1])<0.01f;
}

float Square::area() const { return sides[0] * sides[0]; }

std::string Square::type() const { return "Square"; }
