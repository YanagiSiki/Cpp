#include <iostream>
#include <string>
#include <vector>
#include <UnitTest++.h>
#include <stdlib.h>
#include <iomanip>

#define pi 3

using namespace std;




class V_Shape {
public:
    virtual double getPerimeter();
    virtual double getArea();
    virtual string getName();
private:
    string name;
    void V_Shape_name();
};
class V_Circle: public V_Shape {
public:
    V_Circle(double r);
    double getPerimeter();
    double getArea();
    string getName();
private:
    double Radius;
    string name;
    void V_Circle_name();
};

class V_Rectangle: public V_Shape {
public:
    V_Rectangle(double w,double h);
    double getPerimeter();
    double getArea();
    string getName();
private:
    double Width;
    double Height;
    string name;
    void V_Rectangle_name();
};

