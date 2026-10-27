// shape.h
#ifndef SHAPE_H
#define SHAPE_H

#include "point.h"

class Shape
{
private:
    Point origin;
    char* shapeName;

public:
    // No default constructor
    Shape(double x, double y, const char* name);

    // Rule of Three
    Shape(const Shape& other);
    Shape& operator=(const Shape& other);

    virtual ~Shape();

    // Getters
    const Point& getOrigin() const;
    const char* getName() const;

    // added for lab 3
    virtual double area() const { return 0; }
    virtual double perimeter() const { return 0; }

    virtual void display() const;

    double distance(const Shape& other) const;
    static double distance(const Shape& s1, const Shape& s2);

    void move(double dx, double dy);
};

#endif