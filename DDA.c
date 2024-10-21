#include <graphics.h>
#include <conio.h>
#include <math.h>

void DDA(int x1, int y1, int x2, int y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float Xinc = dx / steps;
    float Yinc = dy / steps;
    float x = x1, y = y1;
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += Xinc;
        y += Yinc;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "NULL");
    DDA(100, 100, 200, 200);
    getch();
    closegraph();
    return 0;
}
