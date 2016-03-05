#include "Flight.h"

void View::drawEdge() {
    readimagefile(edge_img, 10, 10, MAX_X-10, 19);
    readimagefile(edge_img, 10, MAX_Y-19, MAX_X-10, MAX_Y-10);
    readimagefile(edge_img, 10, 10, 19, MAX_Y-10);
    readimagefile(edge_img, MAX_X-19, 19, MAX_X-10, MAX_Y-10);
}
void View::drawScore(int score) {
    char msg[10];
    sprintf(msg, "Score: %d", score);
    outtextxy(20, MAX_Y-19, msg);
}
void View::drawHeroBullets(Hero hero) {
    int x, y, i;
    for (i=0; i<BULLET_NO; i++) {
        if (hero.bulletUsed(i)) {
            x=hero.getBulletX(i);
            y=hero.getBulletY(i);
            line(x, y, x, y+5);
        }
    }
}
void View::drawHero(Hero hero) {
    int x=hero.x();
    int y=hero.y();
    readimagefile(hero_img, x, y, x+GRID, y+GRID);
}
void View::disappearHero(Hero hero) {
    int x=hero.x();
    int y=hero.y();
    readimagefile(bg_img,x, y, x+GRID, y+GRID);
}
void View::disappearHeroBullets(Hero hero) {
    int x, y, i;
    for (i=0; i<BULLET_NO; i++) {
        if (hero.bulletUsed(i)) {
            x=hero.getBulletX(i);
            y=hero.getBulletY(i);
            readimagefile(bg_img,x, y, x+GRID, y+GRID);
        }
    }
}
void View::gameover() {
    readimagefile(game_over_img,MAX_X/2-170,MAX_Y/2-25,MAX_X/2+170,MAX_Y/2+25);
    //saveHighscore();
}
void View::winner() {
    readimagefile(winner_img,MAX_X/2-300,MAX_Y/2-150,MAX_X/2+300,MAX_Y/2+150);
}
