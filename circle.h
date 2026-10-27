// circle.h
#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : virtual public Shape
{
private:
    double radius;

public:
    Circle(double x, double y, double radius, const char* name);

    double get_radius() const;
    void set_radius(double r);

    double area() const override;
    double perimeter() const override;
    void display() const override;
};

#endif