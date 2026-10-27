// curveCut.h
#ifndef CURVECUT_H
#define CURVECUT_H

#include "rectangle.h"
#include "circle.h"

class CurveCut : public Rectangle, public Circle
{
public:
    CurveCut(double x, double y, double width,
             double length, double radius, const char* name);

    double area() const override;
    double perimeter() const override;
    void display() const override;
};

#endif