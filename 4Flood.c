#include <graphics.h>
#include <conio.h>

void floodFill(int x, int y, int fillColor, int boundaryColor) {
    int currentColor = getpixel(x, y);
    if (x < 0 || x >= getmaxx() || y < 0 || y >= getmaxy()) return;
    if (getpixel(x, y) == boundaryColor || getpixel(x, y) == fillColor) return;
    
    putpixel(x, y, fillColor);
    floodFill(x + 1, y, fillColor, boundaryColor);
    floodFill(x - 1, y, fillColor, boundaryColor);
    floodFill(x, y + 1, fillColor, boundaryColor);
    floodFill(x, y - 1, fillColor, boundaryColor);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "NULL");

    setcolor(WHITE);
    rectangle(200, 200, 400, 400);
    floodFill(250, 250, YELLOW, WHITE);
    
    getch();
    closegraph();
    return 0;
}
