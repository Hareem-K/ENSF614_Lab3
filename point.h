// point.h
#ifndef POINT_H
#define POINT_H

class Point
{
private:
    double x;
    double y;
    int id;

    static int count;

public:
    // No default constructor
    Point(double x, double y);

    // Copy constructor
    Point(const Point& other);

    ~Point();

    // Getters
    double getx() const;
    double gety() const;
    int getId() const;

    // Setters
    void setx(double x);
    void sety(double y);

    void display() const;

    static int counter();

    double distance(const Point& other) const;
    static double distance(const Point& p1, const Point& p2);
};

#endif