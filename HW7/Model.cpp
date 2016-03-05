#include "Flight.h"
Position::Position(int x=0, int y=0)    {
        xVal=x;
        yVal=y;
}
int Position::x() {  return xVal;  }
int Position::y() {  return yVal;  }
void Position::setXY(int x, int y) {
    xVal=x;
    yVal=y;
}
Element::Element() {   }
int Element::x() { return p.x();}
int Element::y() { return p.y();}
void Element::setXY(int x, int y) {
    p.setXY(x, y);
}
bool Element::isOutRange() {
    if(x()<20 || y()<20 || x()>MAX_X-40 || y()>MAX_Y-40) return true;
    return false;
}
int Element::getLife() {
    return life;
}
Bullet::Bullet(int dVal)   {
   damage=dVal;
   used = false;
}
int Bullet::getDamage() {
    return damage;
}
void Bullet::move() {
    setXY(x(), y()-GRID);
}
bool Bullet::isHit() {
    return true;
}
void Bullet::setUsed(bool input) {
    used = input;
}
bool Bullet::isUsed() {
    return used;
}
Enemy::Enemy() {}
Hero::Hero(int deadVal) {
    dead = deadVal;
    fbId=0;
}
void Hero::init(int x, int y) {
    setXY(x, y);
}
int Hero::getDead() {
    return dead;
}
void Hero::move(int nX, int nY) {
    setXY(nX, nY);
}
void Hero::fire() {
    cout<<"fire=>"<<fbId<<endl;
    bullets[fbId].setXY(x(), y());
    bullets[fbId].setUsed(true);
    fbId=(fbId+1)%(BULLET_NO);
}
void Hero::moveBullets() {
    int i=0;
    for (i=0;i<BULLET_NO; i++) {
       if (bullets[i].isUsed()) {
           bullets[i].move();
           if (bullets[i].isOutRange()) {
              bullets[i].setUsed(false);
           }
       }
    }
}
int Hero::getBulletX(int i) {
    return bullets[i].x();
}
int Hero::getBulletY(int i) {
    return bullets[i].y();
}
bool Hero::bulletUsed(int i) {
    return bullets[i].isUsed();
}
