#include <iostream>
#include <string>
#include <vector>
#include <UnitTest++.h>
#include <stdlib.h>
#include <iomanip>

#define pi 3


using namespace std;

class Shape {
public:
    double getPerimeter();
    double getArea();
    string getName();
private:
    string name;
    void Shape_name();
};
class Circle: public Shape {
public:
    Circle(double r);
    double getPerimeter();
    double getArea();
    string getName();
private:
    double Radius;
    string name;
    void Circle_name();
};

class Rectangle: public Shape {
public:
    Rectangle(double w,double h);
    double getPerimeter();
    double getArea();
    string getName();
private:
    double Width;
    double Height;
    string name;
    void Rectangle_name();
};
