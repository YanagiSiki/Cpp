#include "shape.h"

double Shape::getPerimeter(){
    return 0;
}
double Shape::getArea(){
    return 0;
}

void Shape::Shape_name(){
    name="Shape";
}
string Shape::getName(){
    Shape_name();
    return name;
}

////////////////////
Circle::Circle(double r){
    Radius=r;
}
double Circle::getPerimeter(){
    return 2*pi*Radius;
}

double Circle::getArea(){
    return pi*Radius*Radius;
}
void Circle::Circle_name(){
    name="Circle";
}
string Circle::getName(){
    Circle_name();
    return name;
}
//////////////////////
Rectangle::Rectangle(double w,double h){
    Width=w;
    Height=h;
}
double Rectangle::getPerimeter(){
    return 2*(Width+Height);
}

double Rectangle::getArea(){
    return Width*Height;
}
void Rectangle::Rectangle_name(){
    name="Rectangle";
}
string Rectangle::getName(){
    Rectangle_name();
    return name;
}
