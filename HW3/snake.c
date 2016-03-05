#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define MAX_X 800
#define MAX_Y 600
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32
#define ESC 27
#define ever (;;)

const char *game_over_img = "game_over.bmp";
const char *head_up = "head_up.bmp";
const char *head_down = "head_down.bmp";
const char *head_left = "head_left.bmp";
const char *head_right = "head_right.bmp";
const char *body_img = "body.bmp";
const char *food_img = "food.bmp";
const char *edge_img = "edge.bmp";
const char *bg_img = "bg.bmp";
const char *winner_img = "winner.bmp";

class Position
{
private:
    int xVal;
    int yVal;

public:
    Position(int x=0, int y=0)
    {
        xVal=x;
        yVal=y;
    }
    int x()
    {
        return xVal;
    }
    int y()
    {
        return yVal;
    }

};
class SnakeElement
{
private:
    Position p;

public:
    SnakeElement()
    {

    }
};
class Snake
{
private:
    SnakeElement e[10];
    int size;
public:
    Snake()
    {

    }
    bool verify_pos(snake_t snake[], int size)
    {
        int x=e[0].x;
        int y=e[0].y;
        if(x<20 || y<20 || x>MAX_X-40 || y>MAX_Y-40) return false;
        for(int i=2; i<size; i++)
            if(e[i].x == x && e[i].y == y) return false;
        return true;
    }
};
class Food
{
private:
    Position p;

public:
    Food() {}

};


void draw_food(snake_t snake[], food_t *food, int size)
{
    int i, fx, fy;
    int x = snake[0].x;
    int y = snake[0].y;
    srand(time(NULL));
    for ever
{
    fx = (rand() % MAX_X-20) + 20;
        fy = (rand() % MAX_Y-20) + 20;
        if(fx<20 || fy <20 || fx > MAX_X-40 || fy>MAX_Y-40) continue;
        if(fx % 20 == 0 && fy % 20 == 0 && x != fx && y != fy)
        {
            readimagefile(food_img, fx, fy, fx+20, fy+20);
            food->x = fx;
            food->y = fy;
            break;
        }
        for(i=0; i<=size; i++)
            if(fx == snake[i].x && fy == snake[i].y) continue;
    }
}
void gameover(int size, int speed)
{
    readimagefile(game_over_img,MAX_X/2-170,MAX_Y/2-25,MAX_X/2+170,MAX_Y/2+25);
    printf("\nYou have scored %d points!\n\n", (size-2)*10*speed);
    //saveHighscore();
    system("PAUSE");
    exit(0);//encerra o programa
}

void draw_point(int size, int speed)
{
    char msg[10];
    sprintf(msg, "Score: %d", (size-2)*10*speed);
    outtextxy(20, MAX_Y-19, msg);
}
void drawEdge()
{
    readimagefile(edge_img, 10, 10, MAX_X-10, 19);
    readimagefile(edge_img, 10, MAX_Y-19, MAX_X-10, MAX_Y-10);
    readimagefile(edge_img, 10, 10, 19, MAX_Y-10);
    readimagefile(edge_img, MAX_X-19, 19, MAX_X-10, MAX_Y-10);
}
void drawHead(snake_t snake[], short dir)
{
    int x = snake[0].x;
    int y = snake[0].y;
    if (dir == UP)
    {
        readimagefile(head_up, x, y, x+20, y+20);
    }
    else if (dir == DOWN)
    {
        readimagefile(head_down, x, y, x+20, y+20);
    }
    else if (dir == RIGHT)
    {
        readimagefile(head_right, x, y, x+20, y+20);
    }
    else if (dir == LEFT)
    {
        readimagefile(head_left, x, y, x+20, y+20);
    }
}
void drawSnake(snake_t snake[], int size, short dir)
{
    int i;
    drawHead(snake, dir);
    printf("size=%d\n", size);
    for(i = 1; i< size; i++)
    {
        readimagefile(body_img,snake[i].x,snake[i].y,snake[i].x+20,snake[i].y+20);
    }
}
void drawFirstBody(snake_t snake[])
{
    readimagefile(body_img,snake[1].x,snake[1].y,snake[1].x+20,snake[1].y+20);
}
void dispaerTail(snake_t snake[], int size)
{
    readimagefile(bg_img,snake[size-1].x-1,snake[size-1].y-1,snake[size-1].x+21,snake[size-1].y+21);
}

void setSnake(snake_t snake[], int *size_p, short dir, int point, int nx, int ny)
{
    int i, size=(*size_p);
    if (nx==snake[0].x && ny==snake[0].y) return;
    dispaerTail(snake, size);

    if (point==1)
    {
        size++;
        *size_p = size;
    }
    for(i = size-1; i>=1 ; i--)
    {
        snake[i].x = snake[i-1].x;
        snake[i].y = snake[i-1].y;
    }
    snake[0].x  = nx;
    snake[0].y =ny;
    drawHead(snake, dir);
    drawFirstBody(snake);
}
int getDirect(snake_t snake[], short *dir, int *nx, int *ny)
{
    if(kbhit())
    {
        (*dir) = getch();
    }
    if((*dir) == ESC) return -1;
    else if((*dir) == UP)
    {
        (*ny)-=20;
    }
    else if((*dir) == DOWN)
    {
        (*ny)+=20;
    }
    else if((*dir) == LEFT)
    {
        (*nx)-=20;
    }
    else if((*dir) == RIGHT)
    {
        (*nx)+=20;
    }
    return 0;
}
int getPoint(snake_t snake[], food_t *food, int *size, int speed)
{
    int x = snake[0].x;
    int y = snake[0].y;
    if(x == food->x && y == food->y)
    {
        draw_food(snake, food, *size);
        draw_point(*size, speed);

        return 1;
    }
    return 0;
}
void init(snake_t snake[], int *size, int nx, int ny)
{
    snake[(*size)].x = nx;
    snake[(*size)].y=ny;
    (*size)++;
    snake[(*size)].x = nx;
    snake[(*size)].y=ny+20;
    (*size)++;
}
void run()
{
    food_t food;
    snake_t snake[20];
    int size=0;
    short dir = UP, speed=1, point=0;
    int newX=MAX_X/2;
    int newY=MAX_Y/2;

    init(snake, &size, newX, newY);
    initwindow(MAX_X, MAX_Y , "Snake" );
    drawEdge();
    draw_food(snake, &food, size);
    draw_point(size, speed);
    drawSnake(snake, size, dir);

    for ever
{
    point = getPoint(snake, &food, &size, speed);
        if (!verify_pos(snake, size)) gameover(size, speed);
        setSnake(snake, &size, dir, point, newX, newY);
        if (getDirect(snake, &dir, &newX, &newY)==-1) break;
        delay(120/speed);
        if (size>=10)
        {
            readimagefile(winner_img,MAX_X/2-300,MAX_Y/2-150,MAX_X/2+300,MAX_Y/2+150);
            break;
        }
    }
    getch();
    closegraph( );
}
int main()
{
    run();
    return 0;
}
