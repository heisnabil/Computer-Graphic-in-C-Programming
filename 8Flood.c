#include <graphics.h>
#include <conio.h>

void floodFill(int x, int y, int fillColor, int boundaryColor) {
    int currentColor = getpixel(x, y);
    if (x < 0 || x >= getmaxx() || y < 0 || y >= getmaxy()) return;
    if (currentColor != boundaryColor && currentColor != fillColor) {
        putpixel(x, y, fillColor);
        floodFill(x + 1, y, fillColor, boundaryColor);
        floodFill(x - 1, y, fillColor, boundaryColor);
        floodFill(x, y + 1, fillColor, boundaryColor);
        floodFill(x, y - 1, fillColor, boundaryColor);
        floodFill(x + 1, y + 1, fillColor, boundaryColor);
        floodFill(x - 1, y - 1, fillColor, boundaryColor);
        floodFill(x + 1, y - 1, fillColor, boundaryColor);
        floodFill(x - 1, y + 1, fillColor, boundaryColor);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    setcolor(WHITE);
    rectangle(150, 150, 350, 350);
    floodFill(200, 200, YELLOW, WHITE);

    getch();
    closegraph();
    return 0;
}
