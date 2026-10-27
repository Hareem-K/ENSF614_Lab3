// rectangle.cpp
#include "rectangle.h"
#include <iostream>

using namespace std;

Rectangle::Rectangle(double x, double y,
                     double side_a, double side_b,
                     const char* name)
    : Shape(x, y, name),
      Square(x, y, side_a, name),
      side_b(side_b)
{
}

Rectangle::Rectangle(const Rectangle& other)
    : Shape(other),
      Square(other),
      side_b(other.side_b)
{
}

Rectangle& Rectangle::operator=(const Rectangle& other)
{
    if (this != &other)
    {
        Square::operator=(other);
        side_b = other.side_b;
    }

    return *this;
}

double Rectangle::get_side_b() const
{
    return side_b;
}

void Rectangle::set_side_b(double side)
{
    side_b = side;
}

double Rectangle::area() const
{
    return side_a * side_b;
}

double Rectangle::perimeter() const
{
    return 2 * (side_a + side_b);
}

// displays the name, and x and y coordinate origin of the shape, side_a, side_b, area, and perimeter of a rectangle object
void Rectangle::display() const
{
    cout << "Rectangle Name: " << getName() << endl;
    cout << "X-coordinate: " << getOrigin().getx() << endl;
    cout << "Y-coordinate: " << getOrigin().gety() << endl;
    cout << "Side a: " << side_a << endl;
    cout << "Side b: " << side_b << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}