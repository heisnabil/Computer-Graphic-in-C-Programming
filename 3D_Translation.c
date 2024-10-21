#include <graphics.h>
#include <conio.h>

void drawCube(int x, int y, int size) {
    int half = size / 2;
    int vertices[8][2] = {
        {x - half, y - half},
        {x + half, y - half},
        {x + half, y + half},
        {x - half, y + half},
        {x - half + size/4, y - half - size/4},
        {x + half + size/4, y - half - size/4},
        {x + half + size/4, y + half - size/4},
        {x - half + size/4, y + half - size/4}
    };

    for (int i = 0; i < 4; i++) {
        line(vertices[i][0], vertices[i][1], vertices[(i + 1) % 4][0], vertices[(i + 1) % 4][1]);
        line(vertices[i + 4][0], vertices[i + 4][1], vertices[(i + 1) % 4 + 4][0], vertices[(i + 1) % 4 + 4][1]);
        line(vertices[i][0], vertices[i][1], vertices[i + 4][0], vertices[i + 4][1]);
    }
}

void translateCube(int *x, int *y, float tx, float ty) {
    *x += (int)tx;
    *y += (int)ty;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x = 300, y = 200, size = 100;
    float tx = 50, ty = 30;

    setcolor(WHITE);
    drawCube(x, y, size);
    delay(2000);
    cleardevice();

    translateCube(&x, &y, tx, ty);
    setcolor(YELLOW);
    drawCube(x, y, size);

    getch();
    closegraph();
    return 0;
}
