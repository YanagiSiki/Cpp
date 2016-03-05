#include "Snake.h"

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
SnakeElement::SnakeElement() {   }
int SnakeElement::x() { return p.x();}
int SnakeElement::y() { return p.y();}
void SnakeElement::setXY(int x, int y) {
    p.setXY(x, y);
}
Snake::Snake(int size)   {
   sizeVal=size;
}
void Snake::setSize(int size) { sizeVal=size; }
int Snake::size() { return sizeVal; }
bool Snake::verify_pos()     {
    int x=e[0].x();
    int y=e[0].y();
    if(x<20 || y<20 || x>MAX_X-40 || y>MAX_Y-40) return false;
	for(int i=2; i<sizeVal; i++){
		if(e[i].x() == x && e[i].y() == y) return false;
	}

    return true;
}
void Snake::setXY(int i, int x, int y) {
   e[i].setXY(x, y);
}
int Snake::x(int i) {return e[i].x(); }
int Snake::y(int i) {return e[i].y(); }
void Snake::init(int nx, int ny) {
    setXY(sizeVal, nx, ny);
    sizeVal++;
    setXY(sizeVal, nx, ny+20);
    sizeVal++;
}
void Snake::move(short dir, bool getPoint, int nx, int ny) {
    int i;
    if (nx==e[0].x() && ny==e[0].y()) return;

    if (getPoint==1) {
        sizeVal++;
    }
    for(i = sizeVal-1; i>=1 ; i--) {
		setXY(i,e[i-1].x(),e[i-1].y());
	}
	setXY(0,nx,ny);


}
Food::Food() {}
int Food::x() { return p.x();}
int Food::y() { return p.y();}
void Food::setXY(int x, int y) {
    p.setXY(x, y);
}
void Food::setNewPosition(Snake snake){
    int i, fx, fy;
    int x = snake.x(0);
    int y = snake.y(0);
    srand(time(NULL));
    for ever    {
        fx = (rand() % MAX_X-20) + 20;
        fy = (rand() % MAX_Y-20) + 20;
        if(fx<20 || fy <20 || fx > MAX_X-40 || fy>MAX_Y-40) continue;
        if(fx % 20 == 0 && fy % 20 == 0 && x != fx && y != fy)        {
            readimagefile(food_img, fx, fy, fx+20, fy+20);
            break;
        }
        for(i=0; i<=snake.size(); i++)
            if(fx == snake.x(i) && fy == snake.y(i)) continue;
    }
    setXY(fx, fy);
}
