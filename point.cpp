// point.cpp
#include "point.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int Point::count = 0;

Point::Point(double x, double y)
    : x(x), y(y)
{
    count++;
    id = 1000 + count;
}

Point::Point(const Point& other)
    : x(other.x), y(other.y)
{
    count++;
    id = 1000 + count;
}

Point::~Point()
{
    count--;
}

double Point::getx() const
{
    return x;
}

double Point::gety() const
{
    return y;
}

int Point::getId() const
{
    return id;
}

void Point::setx(double x)
{
    this->x = x;
}

void Point::sety(double y)
{
    this->y = y;
}

// displays x and y coordinates
void Point::display() const
{
    cout << fixed << setprecision(2);
    cout << "X-coordinate: " << x
         << " Y-coordinate: " << y << endl;
}

int Point::counter()
{
    return count;
}

double Point::distance(const Point& other) const
{
    double dx = x - other.x;
    double dy = y - other.y;

    return sqrt(dx * dx + dy * dy);
}

double Point::distance(const Point& p1, const Point& p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;

    return sqrt(dx * dx + dy * dy);
}