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
#define edge_img "edge.bmp"
#define bg_img "bg.bmp"
#define winner_img "winner.bmp"

class Position {
private:
    int xVal;    //x座標
    int yVal;    //y座標
public:
    Position(int x, int y);
    int x();                    //取的X座標
    int y();                    //取的Y座標
    void setXY(int x, int y);
};
class Element {   //遊戲元件
private:
    Position p;   //元件座標
    int life;     //生命點數
public:
    Element();
    int x();                    //取的X座標
    int y();                    //取的Y座標
    void setXY(int x, int y);   //設定XY座標
    int getLife();              //取的生命值
    bool isOutRange();         //是否離開螢幕
};
class Bullet: public Element {
private:
    int damage;   // 破壞力
    bool used;    // 是否被使用，出現在螢幕
public:
    Bullet(int damageVal=1);
    int getDamage();
    void move();
    bool isHit();
    bool isUsed();
    void setUsed(bool input);
};
class Enemy: public Element{
private:
    int idVal;   //敵人編號
    Position p;  //敵人座標
public:
    Enemy();
};
class Hero: public Element {
private:
    Bullet bullets[BULLET_NO];  // 擁有 BULLET_NO 顆子彈
    int dead;                   //此版本尚未用到
    int fbId;                  //目前發射出去的子彈 ID
public:
    Hero(int deadVal=3);       //建構子
    void init(int x, int y);   //初始化
    int getDead();             //此版本尚未用到
    void move(int newX, int newY); //自己移動
    void fire();                   //發射子彈
    void moveBullets();            //移動子彈
    int getBulletX(int i);         //取得子彈的X座標
    int getBulletY(int i);         //取得子彈的Y座標
    bool bulletUsed(int i);        //檢查第 i顆子彈是否在使用中
};
class View {
public:
    void drawEdge();
    void drawScore(int score);
    void drawHeroBullets(Hero hero);
    void drawHero(Hero hero);
    void disappearHero(Hero hero);
    void disappearHeroBullets(Hero hero);
    void gameover();
    void winner();
};
class Controller {
public:
    int getDirect(int *nx, int *ny, int *fire);
    bool getPoint(Enemy enemy, Bullet bullet);
    void run();
};
#endif // FLIGHT_H_INCLUDED
