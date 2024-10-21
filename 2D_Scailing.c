#include <graphics.h>
#include <conio.h>

void drawRectangle(int x1, int y1, int x2, int y2) {
    rectangle(x1, y1, x2, y2);
}

void scale(int *x1, int *y1, int *x2, int *y2, float sx, float sy) {
    *x1 = (int)(*x1 * sx);
    *y1 = (int)(*y1 * sy);
    *x2 = (int)(*x2 * sx);
    *y2 = (int)(*y2 * sy);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "NULL");

    int x1 = 200, y1 = 200;
    int x2 = 400, y2 = 300;

    setcolor(WHITE);
    drawRectangle(x1, y1, x2, y2);
    
    float sx = 1.5; 
    float sy = 1.5; 

    scale(&x1, &y1, &x2, &y2, sx, sy);
    
    setcolor(YELLOW);
    drawRectangle(x1, y1, x2, y2);
    
    getch();
    closegraph();
    return 0;
}
