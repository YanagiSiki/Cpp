#include "Snake.h"
int main() {
    Controller c;
    initwindow(MAX_X, MAX_Y , "Snake" );
    c.run();
    getch();
    closegraph( );
    return 0;
}
