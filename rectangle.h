// rectangle.h
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "square.h"

// rectangle inherits from square which inherits from shape
class Rectangle : public Square
{
private:
    double side_b;

public:
    // No default constructor
    Rectangle(double x, double y,
              double side_a, double side_b,
              const char* name);

    Rectangle(const Rectangle& other);

    Rectangle& operator=(const Rectangle& other);

    // getters and setters
    double get_side_b() const;
    void set_side_b(double side);

    double area() const override;
    double perimeter() const override;

    void display() const override;
};

#endif