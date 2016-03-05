#include "v_shape.h"



double V_Shape::getPerimeter(){
    return 0;
}
double V_Shape::getArea(){
    return 0;
}

void V_Shape::V_Shape_name(){
    name="V_Shape";
}
string V_Shape::getName(){
    V_Shape_name();
    return name;
}
////////////////////
V_Circle::V_Circle(double r){
    Radius=r;
}
double V_Circle::getPerimeter(){
    return 2*pi*Radius;
}

double V_Circle::getArea(){
    return pi*Radius*Radius;
}
void V_Circle::V_Circle_name(){
    name="V_Circle";
}
string V_Circle::getName(){
    V_Circle_name();
    return name;
}
//////////////////////
V_Rectangle::V_Rectangle(double w,double h){
    Width=w;
    Height=h;
}
double V_Rectangle::getPerimeter(){
    return 2*(Width+Height);
}

double V_Rectangle::getArea(){
    return Width*Height;
}
void V_Rectangle::V_Rectangle_name(){
    name="V_Rectangle";
}
string V_Rectangle::getName(){
    V_Rectangle_name();
    return name;
}
