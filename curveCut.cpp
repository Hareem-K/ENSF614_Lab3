// curveCut.cpp
#include "curveCut.h"
#include <iostream>
#include <cstdlib>

using namespace std;

const double CURVE_PI = 3.14159265358979323846;

CurveCut::CurveCut(double x, double y, double width,
                   double length, double radius, const char* name)
    : Shape(x, y, name),
      Rectangle(x, y, width, length, name),
      Circle(x, y, radius, name)
{
    if (radius < 0 || radius > width || radius > length)
    {
        cerr << "Error: radius must be nonnegative and no greater than width or length." << endl;
        exit(1);
    }
}

double CurveCut::area() const
{
    double r = get_radius();
    return Rectangle::area() - CURVE_PI * r * r / 4;
}

double CurveCut::perimeter() const
{
    double r = get_radius();
    return Rectangle::perimeter() - 2 * r + CURVE_PI * r / 2;
}

void CurveCut::display() const
{
    cout << "CurveCut Name: " << getName() << endl;
    cout << "X-coordinate: " << getOrigin().getx() << endl;
    cout << "Y-coordinate: " << getOrigin().gety() << endl;
    cout << "Width: " << get_side_a() << endl;
    cout << "Length: " << get_side_b() << endl;
    cout << "Radius of the cut: " << get_radius() << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}