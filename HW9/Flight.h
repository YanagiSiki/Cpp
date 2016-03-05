#ifndef FLIGHT_H_INCLUDED
#define FLIGHT_H_INCLUDED

#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define FOOD_NO 4
#define MAX_X 800
#define MAX_Y 600
#define GRID 20
#define MARGE 20
#define BULLET_NO 20

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32
#define ESC 27
#define ever (;;)

#define game_over_img "game_over.bmp"
#define hero_img "hero.bmp"
#define enemy_img "enemy.bmp"
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
class Element {
private:
    Position p;
    int life;
public:
    Element();
    int x();
    int y();
    void setXY(int x, int y);
    int getLife();
    void setLife(int liftVal);
    bool isOutRange();
};
class Bullet: public Element {
private:
    int damage;
    bool used;
public:
    Bullet(int damageVal=1);
    int getDamage();
    void move();
    void downmove();
    bool isUsed();
    void setUsed(bool input);
};
class Enemy: public Element{
private:
    Bullet bullets[BULLET_NO];
    int idVal;
    int dir;
    int fbId;
    Position p;
public:
    Enemy();
    void init(int x, int y);
    void move(int newX, int newY);
    void damageLife(int *idVal);
    bool isHit(int x, int y);
    void fire();//
    void moveBullets();//
    int getBulletX(int i);
    int getBulletY(int i);
    bool bulletIsUsed(int i);
    void bulletSetUsed(int i);
};
class Hero: public Element {
private:
    Bullet bullets[BULLET_NO];
    int dead;
    int fbId;
public:
    Hero(int deadVal=3);
    void init(int x, int y);
    int getDead();
    void getDamage();
    void move(int newX, int newY);
    bool isAttacked(int x, int y);
    void fire();
    void moveBullets();
    int getBulletX(int i);
    int getBulletY(int i);
    bool bulletIsUsed(int i);
    void bulletSetUsed(int i);
};
class View {
public:
    void drawEdge();
    void drawScore(int score, int eLife);
    void drawHeroBullets(Hero hero);
    void drawEnemyBullets(Enemy enemy);
    void drawHero(Hero hero);
    void drawEnemy(Enemy enemy);
    void disappearHero(Hero hero);
    void disappearEnemy(Enemy enemy);
    void disappearHeroBullets(Hero hero);
    void disappearEnemyBullets(Enemy enemy);
    void gameover();
    void winner();
};
class Controller {
public:
    int getDirect(int *nx, int *ny, int *fire);
    bool getPoint(Enemy enemy, Hero hero);
    bool getAttacked(Enemy enemy, Hero hero);
    void run();
};
#endif // FLIGHT_H_INCLUDED
