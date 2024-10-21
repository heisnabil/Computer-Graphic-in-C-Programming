#include <graphics.h>
#include <conio.h>

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void translate(int *x, int *y, int tx, int ty) {
    *x += tx;
    *y += ty;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "NULL");

    int x1 = 200, y1 = 200;
    int x2 = 300, y2 = 100;
    int x3 = 400, y3 = 200;

    setcolor(WHITE);
    drawTriangle(x1, y1, x2, y2, x3, y3);
    
    int tx = 50; 
    int ty = 50;

    translate(&x1, &y1, tx, ty);
    translate(&x2, &y2, tx, ty);
    translate(&x3, &y3, tx, ty);

    setcolor(YELLOW);
    drawTriangle(x1, y1, x2, y2, x3, y3);
    
    getch();
    closegraph();
    return 0;
}
