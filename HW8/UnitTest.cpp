#include "shape.h"
#include "v_shape.h"


void Shape_print(Shape *sp){
    cout<<"Name:"<<sp->getName()<<endl;
    cout<<"Perimeter:"<<sp->getPerimeter()<<endl;
    cout<<"Area:"<<sp->getArea()<<endl;
    cout<<"-------分隔線-------"<<endl;
}
void V_Shape_print(V_Shape *vsp){
    cout<<"Name:"<<vsp->getName()<<endl;
    cout<<"Perimeter:"<<vsp->getPerimeter()<<endl;
    cout<<"Area:"<<vsp->getArea()<<endl;
    cout<<"-------分隔線-------"<<endl;
}



TEST(Shape){
    Shape s;
    Circle c(5);
    Rectangle r(5,2);

    CHECK_EQUAL(s.getName(),"Shape");
    CHECK_EQUAL(s.getArea(),0);
    CHECK_EQUAL(s.getPerimeter(),0);
    //////////
    CHECK_EQUAL(c.getName(),"Circle");
    CHECK_EQUAL(c.getArea(),75);
    CHECK_EQUAL(c.getPerimeter(),30);
    //////////
    CHECK_EQUAL(r.getName(),"Rectangle");
    CHECK_EQUAL(r.getArea(),10);
    CHECK_EQUAL(r.getPerimeter(),14);
}
TEST(Shape_point){
    cout<<"-------Shape_point-------"<<endl;
    Shape s;
    Circle c(5);
    Rectangle r(5,2);

    Shape *sp;
    Circle *cp;
    Rectangle *rp;
    //
    sp=&s;
    CHECK_EQUAL(sp->getName(),"Shape");
    CHECK_EQUAL(sp->getArea(),0);
    CHECK_EQUAL(sp->getPerimeter(),0);
    Shape_print(sp);
    //
    sp=&c;
    CHECK_EQUAL(sp->getName(),"Shape");
    CHECK_EQUAL(sp->getArea(),0);
    CHECK_EQUAL(sp->getPerimeter(),0);
    Shape_print(sp);
    //
    sp=&r;
    CHECK_EQUAL(sp->getName(),"Shape");
    CHECK_EQUAL(sp->getArea(),0);
    CHECK_EQUAL(sp->getPerimeter(),0);
    Shape_print(sp);

    //cp=&s;
    //cp=&r;
    cp=&c;
    CHECK_EQUAL(cp->getName(),"Circle");
    CHECK_EQUAL(cp->getArea(),75);
    CHECK_EQUAL(cp->getPerimeter(),30);

    //rp=&s;
    //rp=&c;
    rp=&r;
    CHECK_EQUAL(rp->getName(),"Rectangle");
    CHECK_EQUAL(rp->getArea(),10);
    CHECK_EQUAL(rp->getPerimeter(),14);


    cout<<"-------Shape_point-------"<<endl;
}
/////////////////////////////////////////////////////////
TEST(virtual_Shape){
    V_Shape s;
    V_Circle c(5);
    V_Rectangle r(5,2);

    CHECK_EQUAL(s.getName(),"V_Shape");
    CHECK_EQUAL(s.getArea(),0);
    CHECK_EQUAL(s.getPerimeter(),0);
    //////////
    CHECK_EQUAL(c.getName(),"V_Circle");
    CHECK_EQUAL(c.getArea(),75);
    CHECK_EQUAL(c.getPerimeter(),30);
    //////////
    CHECK_EQUAL(r.getName(),"V_Rectangle");
    CHECK_EQUAL(r.getArea(),10);
    CHECK_EQUAL(r.getPerimeter(),14);
}


TEST(virtual_Shape_point){
    cout<<"-------virtual_Shape_point-------"<<endl;
    V_Shape s;
    V_Circle c(5);
    V_Rectangle r(5,2);

    V_Shape *sp;
    V_Circle *cp;
    V_Rectangle *rp;
    //
    sp=&s;
    CHECK_EQUAL(sp->getName(),"V_Shape");
    CHECK_EQUAL(sp->getArea(),0);
    CHECK_EQUAL(sp->getPerimeter(),0);
    V_Shape_print(sp);
    //
    sp=&c;
    CHECK_EQUAL(sp->getName(),"V_Circle");//////////////////override
    CHECK_EQUAL(sp->getArea(),75);
    CHECK_EQUAL(sp->getPerimeter(),30);
    V_Shape_print(sp);
    //
    sp=&r;
    CHECK_EQUAL(sp->getName(),"V_Rectangle");//////////////////override
    CHECK_EQUAL(sp->getArea(),10);
    CHECK_EQUAL(sp->getPerimeter(),14);
    V_Shape_print(sp);


    //cp=&s;
    //cp=&r;
    cp=&c;
    CHECK_EQUAL(cp->getName(),"V_Circle");
    CHECK_EQUAL(cp->getArea(),75);
    CHECK_EQUAL(cp->getPerimeter(),30);
    //rp=&s;
    //rp=&c;
    rp=&r;
    CHECK_EQUAL(rp->getName(),"V_Rectangle");
    CHECK_EQUAL(rp->getArea(),10);
    CHECK_EQUAL(rp->getPerimeter(),14);
    cout<<"-------virtual_Shape_point-------"<<endl;
}
