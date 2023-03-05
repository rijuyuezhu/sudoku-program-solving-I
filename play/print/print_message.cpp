#include "../../sudoku.h"
#include <iostream>
#include <sstream>

constexpr int BEGIN_ROW = 16;
constexpr int BEGIN_COL = 36;

static void Clear_message() {
    for(int row = 16; row <= 24; row++) {
        Gotoxy(row, 36);
        for(int cnt = 1; cnt <= 24; cnt++)
            std::cout << ' ';
    }
}
void Print_message(std::string s, int color) {
    Clear_message();
    Set_color(color);
    std::string tmp;
    std::stringstream str_in_out(s);
    int now_line = BEGIN_ROW, now_col = BEGIN_COL;
    while(str_in_out >> tmp) {
        if(now_col + tmp.length() >= SCREEN_WIDTH)
            now_line++, now_col = BEGIN_COL;
        Gotoxy(now_line, now_col);
        std::cout << tmp << ' ';
        now_col += tmp.length() + 1;
    }
}