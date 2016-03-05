
#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX_X 800
#define MAX_Y 600
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32
#define ESC 27
#define ever (;;)

#define game_over_img "game_over.bmp"
#define head_up "head_up.bmp"
#define head_down "head_down.bmp"
#define head_left "head_left.bmp"
#define head_right "head_right.bmp"
#define body_img "body.bmp"
#define food_img "food.bmp"
#define edge_img "edge.bmp"
#define bg_img "bg.bmp"
#define winner_img "winner.bmp"

class Position {
private:
    int xVal;
    int yVal;
public:
    Position(int x, int y);
    int x();
    int y();
    void setXY(int x, int y);
};
class SnakeElement {
private:
    Position p;
public:
    SnakeElement();
    int x();
    int y();
    void setXY(int x, int y);
};
class Snake {
private:
    SnakeElement e[20];
    int sizeVal;
public:
    Snake(int size=0);
    void setSize(int size);
    int size();
    bool verify_pos();
    void setXY(int i, int x, int y);
    int x(int i);
    int y(int i);
    void init(int nx, int ny);
    void move(short dir, bool getPoint, int nx, int ny);
};
class Food {
private:
    Position p;
public:
    Food();
    int x();
    int y();
    void setXY(int x, int y);
    void setNewPosition(Snake snake);
};
class View {
public:
    void drawEdge();
    void draw_score(int size, int speed);
    void drawHead(Snake snake, short dir);
    void drawSnake(Snake snake, short dir);
    void drawMoveSnake(Snake snake, short dir);
    void drawFirstBody(Snake snake);
    void dispaerTail(Snake snake);
    void draw_food(Food food);
    void gameover();
    void winner();
};
class Controller {
public:
    int getDirect(short *dir, int *nx, int *ny);
    bool getPoint(Snake snake, Food food);
    void run();
};
#endif // SNAKE_H_INCLUDED
