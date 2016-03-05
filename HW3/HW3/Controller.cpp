#include "Snake.h"

int Controller::getDirect(short *dir, int *nx, int *ny){
    if(kbhit())     {
        (*dir) = getch();
    }
    if((*dir) == ESC) return -1;
    else if((*dir) == UP)     {
        (*ny)-=20;
    }
    else if((*dir) == DOWN)     {
        (*ny)+=20;
    }
    else if((*dir) == LEFT)     {
        (*nx)-=20;
    }
    else if((*dir) == RIGHT)     {
        (*nx)+=20;
    }
    return 0;
}
bool Controller::getPoint(Snake snake, Food food) {
    if (snake.x(0)==food.x() && snake.y(0)==food.y())  return true;
    return false;
}
void Controller::run() {
    View v;
    Food food;
    Snake snake; //snake(20)
    bool isGetPoint;
    short dir = UP, speed=1;
    int newX=MAX_X/2;
    int newY=MAX_Y/2;
    snake.init(newX, newY);
    food.setNewPosition(snake);
    v.drawEdge();
    v.draw_food(food);
    v.draw_score(snake.size(), speed);
    v.drawSnake(snake, dir);
    for ever {
        isGetPoint = getPoint(snake, food);
        if (isGetPoint) {
            v.draw_score(snake.size(), speed);
            food.setNewPosition(snake);
            v.draw_food(food);
        }
        if (snake.size()>=10)   {
            v.winner();
            break;
        }
        else if (!snake.verify_pos()) {
            v.gameover();
            break;
        }
        v.dispaerTail(snake);
        snake.move(dir, isGetPoint, newX, newY);
        v.drawMoveSnake(snake, dir);
        if (getDirect(&dir, &newX, &newY)==-1) break;
        delay(120/speed);
    }
    printf("\nYou have scored %d points!\n\n", (snake.size()-2)*10*speed);
}
