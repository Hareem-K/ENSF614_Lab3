// circle.cpp
#include "circle.h"
#include <iostream>

using namespace std;

const double PI = 3.14159265358979323846;

Circle::Circle(double x, double y, double radius, const char* name)
    : Shape(x, y, name), radius(radius)
{
}

double Circle::get_radius() const
{
    return radius;
}

void Circle::set_radius(double r)
{
    radius = r;
}

double Circle::area() const
{
    return PI * radius * radius;
}

double Circle::perimeter() const
{
    return 2 * PI * radius;
}

void Circle::display() const
{
    cout << "Circle Name: " << getName() << endl;
    cout << "X-coordinate: " << getOrigin().getx() << endl;
    cout << "Y-coordinate: " << getOrigin().gety() << endl;
    cout << "Radius: " << radius << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}