#include "Flight.h"
int Controller::getDirect(int *nx, int *ny, int *fire){
    // �ɤW���q�{��
    // ���o��L�W�U���k���ʪ���V�A�]�w�s��XY�y��
    // �P�_�O�_���U�ť���A��ܵo�g�l�u�A�]�w *fire�C

    if(kbhit()){
        (*fire) = getch();
    }

    if((*fire) == ESC) return -1;
    else if((*fire) == UP)     {
        (*ny)-=20;
    }
    else if((*fire) == DOWN)     {
        (*ny)+=20;
    }
    else if((*fire) == LEFT)     {
        (*nx)-=20;
    }
    else if((*fire)== RIGHT)     {
        (*nx)+=20;
    }



    //cout<<(*fire)<<endl;
    return 0;
}
bool Controller::getPoint(Enemy enemy, Bullet bullet) {
    //int xb=bullet.x();
    //int yb=bullet.y();
    return true;
}
void Controller::run() {
    View v;
    Hero hero;
    Bullet *bullet = NULL;
    Enemy enemy;
    bool isGetPoint=false;
    int fire=0,speed=1;
    int newX=MAX_X/2;
    int newY=3*MAX_Y/4;
    hero.init(newX, newY);
    v.drawEdge();
    v.drawHero(hero);


    for ever {
        fire=0;

        if (getDirect(&newX,&newY,&fire)==-1) break;
        if(hero.isOutRange()){
            newX=MAX_X/2;
            newY=3*MAX_Y/4;
        }
        v.disappearHero(hero);
        hero.move(newX,newY);
        v.drawHero(hero);
        if(fire==SPACE){
            hero.fire();
            //cout<<"0000"<<endl;
        }
        v.disappearHeroBullets(hero);
        hero.moveBullets();
        v.drawHeroBullets(hero);
        delay(120/speed);
    }
    //printf("\nYou have scored %d points!\n\n", (snake.size()-2)*10*speed);
    // �ɤW���q�{��
    // �����v���\��C
    //�@�� Hero�A�i�H�ϥ���L�W�U���k���ʡA���U�ť���i�H�o�g�l�u�C
}
