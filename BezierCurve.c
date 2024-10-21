#include <graphics.h>
#include <conio.h>
#include <math.h>

void drawBezier(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3) {
    for (float t = 0; t <= 1; t += 0.01) {
        float x = pow(1 - t, 3) * x0 + 3 * pow(1 - t, 2) * t * x1 + 3 * (1 - t) * t * t * x2 + pow(t, 3) * x3;
        float y = pow(1 - t, 3) * y0 + 3 * pow(1 - t, 2) * t * y1 + 3 * (1 - t) * t * t * y2 + pow(t, 3) * y3;
        putpixel((int)x, (int)y, WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x0 = 100, y0 = 300;
    int x1 = 200, y1 = 100;
    int x2 = 300, y2 = 100;
    int x3 = 400, y3 = 300;

    drawBezier(x0, y0, x1, y1, x2, y2, x3, y3);

    getch();
    closegraph();
    return 0;
}
