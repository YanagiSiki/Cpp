#include "Snake.h"

void View::drawEdge() {
    readimagefile(edge_img, 10, 10, MAX_X-10, 19);
    readimagefile(edge_img, 10, MAX_Y-19, MAX_X-10, MAX_Y-10);
    readimagefile(edge_img, 10, 10, 19, MAX_Y-10);
    readimagefile(edge_img, MAX_X-19, 19, MAX_X-10, MAX_Y-10);
}
void View::draw_score(int size, int speed) {
    char msg[10];
    sprintf(msg, "Score: %d", (size-2)*10*speed);
    outtextxy(20, MAX_Y-19, msg);
}
void View::drawHead(Snake snake, short dir) {
    int x = snake.x(0);
    int y = snake.y(0);
    if (dir == UP)    {
        readimagefile(head_up, x, y, x+20, y+20);
    }
    else if (dir == DOWN)     {
        readimagefile(head_down, x, y, x+20, y+20);
    }
    else if (dir == RIGHT)    {
        readimagefile(head_right, x, y, x+20, y+20);
    }
    else if (dir == LEFT)     {
        readimagefile(head_left, x, y, x+20, y+20);
    }
}
void View::drawSnake(Snake snake, short dir) {
    int i;
    drawHead(snake, dir);
    printf("size=%d\n", snake.size());
    for(i = 1; i< snake.size(); i++)  {
        readimagefile(body_img,snake.x(i),snake.y(i),snake.x(i)+20,snake.y(i)+20);
    }
}
void View::drawMoveSnake(Snake snake, short dir) {
    drawHead(snake, dir);
    drawFirstBody(snake);
}
void View::drawFirstBody(Snake snake) {
    readimagefile(body_img,snake.x(1),snake.y(1),snake.x(1)+20,snake.y(1)+20);
}
void View::dispaerTail(Snake snake) {
    int size = snake.size();
    readimagefile(bg_img,snake.x(size-1)-1,snake.y(size-1)-1,
              snake.x(size-1)+21,snake.y(size-1)+21);
}
void View::draw_food(Food food){
    readimagefile(food_img, food.x(), food.y(), food.x()+20, food.y()+20);
}
void View::gameover() {
    readimagefile(game_over_img,MAX_X/2-170,MAX_Y/2-25,MAX_X/2+170,MAX_Y/2+25);
    //saveHighscore();
}
void View::winner() {
    readimagefile(winner_img,MAX_X/2-300,MAX_Y/2-150,MAX_X/2+300,MAX_Y/2+150);
}
