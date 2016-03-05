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
    int xVal;    //x�y��
    int yVal;    //y�y��
public:
    Position(int x, int y);
    int x();                    //����X�y��
    int y();                    //����Y�y��
    void setXY(int x, int y);
};
class Element {   //�C������
private:
    Position p;   //����y��
    int life;     //�ͩR�I��
public:
    Element();
    int x();                    //����X�y��
    int y();                    //����Y�y��
    void setXY(int x, int y);   //�]�wXY�y��
    int getLife();              //�����ͩR��
    bool isOutRange();         //�O�_���}�ù�
};
class Bullet: public Element {
private:
    int damage;   // �}�a�O
    bool used;    // �O�_�Q�ϥΡA�X�{�b�ù�
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
    int idVal;   //�ĤH�s��
    Position p;  //�ĤH�y��
public:
    Enemy();
};
class Hero: public Element {
private:
    Bullet bullets[BULLET_NO];  // �֦� BULLET_NO ���l�u
    int dead;                   //�������|���Ψ�
    int fbId;                  //�ثe�o�g�X�h���l�u ID
public:
    Hero(int deadVal=3);       //�غc�l
    void init(int x, int y);   //��l��
    int getDead();             //�������|���Ψ�
    void move(int newX, int newY); //�ۤv����
    void fire();                   //�o�g�l�u
    void moveBullets();            //���ʤl�u
    int getBulletX(int i);         //���o�l�u��X�y��
    int getBulletY(int i);         //���o�l�u��Y�y��
    bool bulletUsed(int i);        //�ˬd�� i���l�u�O�_�b�ϥΤ�
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
