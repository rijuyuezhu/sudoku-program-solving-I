#include "../sudoku.h"
#include <windows.h>
#include <cstdlib>
#include <sstream>

void Gotoxy(int x, int y) {
    COORD position;
    position.X = y;
    position.Y = x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void Clear_screen(void) {
    system("cls");
}

void Set_color(int color) {
    HANDLE hCorsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCorsole, color);
}

void Set_window_color(int color) {
    std::stringstream tmp;
    tmp << "color " << std::hex << color;
    system(tmp.str().c_str());
}
