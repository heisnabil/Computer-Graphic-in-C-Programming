#include <graphics.h>
#include <conio.h>
#include <math.h>

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void rotate(int *x, int *y, float angle) {
    float rad = angle * (3.14159 / 180); 
    int x_new = (int)(*x * cos(rad) - *y * sin(rad));
    int y_new = (int)(*x * sin(rad) + *y * cos(rad));
    *x = x_new;
    *y = y_new;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "NULL");

    int x1 = 200, y1 = 200;
    int x2 = 250, y2 = 150;
    int x3 = 300, y3 = 200;

    setcolor(WHITE);
    drawTriangle(x1, y1, x2, y2, x3, y3);
    
    float angle = 45; 

    rotate(&x1, &y1, angle);
    rotate(&x2, &y2, angle);
    rotate(&x3, &y3, angle);

    setcolor(YELLOW);
    drawTriangle(x1, y1, x2, y2, x3, y3);
    
    getch();
    closegraph();
    return 0;
}
