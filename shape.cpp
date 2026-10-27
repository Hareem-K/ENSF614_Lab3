// shape.cpp
#include "shape.h"
#include <iostream>
#include <cstring>

using namespace std;

Shape::Shape(double x, double y, const char* name)
    : origin(x, y)
{
    shapeName = new char[strlen(name) + 1];
    strcpy(shapeName, name);
}

Shape::Shape(const Shape& other)
    : origin(other.origin)
{
    shapeName = new char[strlen(other.shapeName) + 1];
    strcpy(shapeName, other.shapeName);
}

Shape& Shape::operator=(const Shape& other)
{
    if (this != &other)
    {
        origin = other.origin;

        delete[] shapeName;

        shapeName = new char[strlen(other.shapeName) + 1];
        strcpy(shapeName, other.shapeName);
    }

    return *this;
}

Shape::~Shape()
{
    delete[] shapeName;
}

const Point& Shape::getOrigin() const
{
    return origin;
}

const char* Shape::getName() const
{
    return shapeName;
}

// prints on the screen the shape’s name, x and y coordinates of point origin
void Shape::display() const
{
    cout << "Shape Name: " << shapeName << endl;
    cout << "X-coordinate: " << origin.getx() << endl;
    cout << "Y-coordinate: " << origin.gety() << endl;
}

double Shape::distance(const Shape& other) const
{
    return origin.distance(other.origin);
}

double Shape::distance(const Shape& s1, const Shape& s2)
{
    return Point::distance(s1.origin, s2.origin);
}

// changes the position of the shape
void Shape::move(double dx, double dy)
{
    origin.setx(origin.getx() + dx);
    origin.sety(origin.gety() + dy);
}