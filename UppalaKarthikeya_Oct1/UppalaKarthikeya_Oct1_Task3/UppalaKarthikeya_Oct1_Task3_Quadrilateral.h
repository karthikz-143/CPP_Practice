#ifndef UPPALAKARTHIKEYA_OCT1_TASK3_QUADRILATERAL_H
#define UPPALAKARTHIKEYA_OCT1_TASK3_QUADRILATERAL_H

#include <iostream>
#include <string>

class Quadrilateral
{
protected:
    float* sides;
    float* angles;

public:
    Quadrilateral(const float sideVals[4], const float angleVals[4]);
    Quadrilateral(const Quadrilateral& other);
    Quadrilateral& operator=(const Quadrilateral& other);
    virtual ~Quadrilateral();

    virtual bool isValid() const;
    virtual float area() const; 
    virtual std::string type() const;

    float perimeter() const;

    bool operator==(const Quadrilateral& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Quadrilateral& q);
    operator float() const; 
    float operator()() const;
};

// Derived classes
class Trapezoid : public Quadrilateral
{
public:
    Trapezoid(const float sideVals[4], const float angleVals[4]);
    bool isValid() const override;
    float area() const override;
    std::string type() const override;
};

class Parallelogram : public Trapezoid
{
public:
    Parallelogram(const float sideVals[4], const float angleVals[4]);
    bool isValid() const override;
    float area() const override;
    std::string type() const override;
};

class Rectangle : public Parallelogram
{
public:
    Rectangle(const float sideVals[4], const float angleVals[4]);
    bool isValid() const override;
    float area() const override;
    std::string type() const override;
};

class Square : public Rectangle
{
public:
    Square(const float sideVals[4], const float angleVals[4]);
    bool isValid() const override;
    float area() const override;
    std::string type() const override;
};

#endif
