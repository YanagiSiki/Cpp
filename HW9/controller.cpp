#include "Flight.h"
int Controller::getDirect(int *nx, int *ny, int *fire){
    // �ɤW���q�{��
    // ���o��L�W�U���k���ʪ���V�A�]�w�s��XY�y��
    // �P�_�O�_���U�ť���A��ܵo�g�l�u�A�]�w *fire�C
    int tmpx=*nx,tmpy=*ny;
    if(kbhit()){
        (*fire) = getch();
    }

    if((*fire) == ESC) return -1;
    else if((*fire) == UP)     {
        tmpy-=20;
    }
    else if((*fire) == DOWN)     {
        tmpy+=20;
    }
    else if((*fire) == LEFT)     {
        tmpx-=20;
    }
    else if((*fire)== RIGHT)     {
        tmpx+=20;
    }
    Hero herotmp;
    herotmp.init(tmpx,tmpy);
    if(herotmp.isOutRange()==0){
        (*nx)=tmpx;
        (*ny)=tmpy;
    }


    return 0;
}
bool Controller::getPoint(Enemy enemy, Hero hero) {
    int i;
    for (i=0;i<BULLET_NO; i++) {
        if(enemy.isHit(hero.getBulletX(i),hero.getBulletY(i)))return 1;
    }
    return 0;
}
bool Controller::getAttacked(Enemy enemy, Hero hero) {
    int i;
    for (i=0;i<BULLET_NO; i++) {
        if(hero.isAttacked(enemy.getBulletX(i),enemy.getBulletY(i)))return 1;
    }
    return 0;
}
void Controller::run() {
    View v;
    Hero hero;
    Bullet *bullet = NULL;
    Bullet *Enemy_bullet = NULL;
    Enemy enemy;
    bool isGetPoint=false;
    int fire=0,speed=1;
    int idVal=10;
    int newX=MAX_X/2;
    int newY=3*MAX_Y/4;
    int newEnemyX=MAX_X/2;
    int newEnemyY=MAX_Y/4;
    enemy.init(newEnemyX,newEnemyY);
    hero.init(newX, newY);
    v.drawEdge();
    v.drawHero(hero);
    v.drawEnemy(enemy);
    printf("Enemy HP=10");

    for ever {
        v.drawScore(idVal,0);
        fire=0;

        if (getDirect(&newX,&newY,&fire)==-1) break;
        /*if(hero.isOutRange()){
            newX=MAX_X/2;
            newY=3*MAX_Y/4;
        }*/
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
        ////HW9�s�W
        if(getPoint(enemy,hero)==1){
            enemy.damageLife(&idVal);
            if(idVal==0){
                v.winner();
                printf("You win!");
                break;
            }
        }
        ////
        v.disappearEnemy(enemy);
        enemy.move(newEnemyX,newEnemyY);
        v.drawEnemy(enemy);

        v.disappearEnemyBullets(enemy);
        enemy.moveBullets();
        v.drawEnemyBullets(enemy);

        if(getAttacked(enemy,hero)==1){
            hero.getDamage();
            if(hero.getDead()==0){
                v.gameover();
                printf("You lost!");
                break;
            }
        }

        delay(120/speed);
    }
    printf("�C������");
    // �ɤW���q�{��
    // �����v���\��C
    //�@�� Hero�A�i�H�ϥ���L�W�U���k���ʡA���U�ť���i�H�o�g�l�u�C
}
