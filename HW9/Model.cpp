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
void Bullet::downmove() {
    setXY(x(), y()+GRID);
}

void Bullet::setUsed(bool input) {
    used = input;
}
bool Bullet::isUsed() {
    return used;
}
////////////HW9·s¼W
Enemy::Enemy() {
    fbId=0;
}
void Enemy::init(int x, int y){
    setXY(x, y);
}
void Enemy::move(int newX, int newY){
    srand(time(NULL));
    dir=(rand()%5)+1;
    //cout<<dir<<endl;
    cout<<p.x()<<"--"<<p.y()<<endl;
    if(dir == 1){
        setXY(newX,newY-20);
        //fire();
        //(*ny)-=20;
    }
    else if(dir == 2){
        setXY(newX,newY+20);
        //fire();
        //(*ny)+=20;
    }
    else if(dir == 3){
        setXY(newX-20,newY);
        //fire();
        //(*nx)-=20;
    }
    else if(dir== 4){
        setXY(newX+20,newY);
        //fire();
        //(*nx)+=20;
    }
    else if(dir== 5){
        fire();
        //(*nx)+=20;
    }
    //delay(120);
}
void Enemy::damageLife(int *idVal){
    (*idVal)--;
}
bool Enemy::isHit(int x, int y){
    if(this->x()==x && this->y()==y)return 1;
    else return 0;
}
void Enemy::fire() {
    cout<<"enemy_fire=>"<<fbId<<endl;
    bullets[fbId].setXY(x(), y());
    bullets[fbId].setUsed(true);
    fbId=(fbId+1)%(BULLET_NO);
}

void Enemy::moveBullets() {
    int i=0;
    for (i=0;i<BULLET_NO; i++) {
       if (bullets[i].isUsed()) {
           bullets[i].downmove();
           if (bullets[i].isOutRange()) {
              bullets[i].setUsed(false);
           }
       }
    }
}
int Enemy::getBulletX(int i) {
    return bullets[i].x();
}
int Enemy::getBulletY(int i) {
    return bullets[i].y();
}
bool Enemy::bulletIsUsed(int i) {
    return bullets[i].isUsed();
}

///////////////
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
void Hero::getDamage() {
    dead--;
}
void Hero::move(int nX, int nY) {
    setXY(nX, nY);
}
bool Hero::isAttacked(int x, int y){
    if(this->x()==x && this->y()==y)return 1;
    else return 0;
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
bool Hero::bulletIsUsed(int i) {
    return bullets[i].isUsed();
}
