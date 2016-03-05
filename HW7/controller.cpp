#include "Flight.h"
int Controller::getDirect(int *nx, int *ny, int *fire){
    // 補上此段程式
    // 取得鍵盤上下左右移動的方向，設定新的XY座標
    // 判斷是否按下空白鍵，表示發射子彈，設定 *fire。

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
    // 補上此段程式
    // 完成影片功能。
    //一個 Hero，可以使用鍵盤上下左右移動，按下空白鍵可以發射子彈。
}
