#include "../../sudoku.h"
#include <iostream>

static int Get_v_x(int v) {
    return (v - 1) / 3;
}

static int Get_v_y(int v) {
    return (v - 1) % 3;
}

static int Get_center_v_x(int x) {
    int v_x = Get_v_x(x);
    return 5 + v_x * 2;
}

static int Get_center_v_y(int y) {
    int v_y = Get_v_y(y);
    return 44 + v_y * 3;
}

static void Clear_hint() {
    Set_color(COL_NORMAL);
    for(int i = 5; i <= 9; i++) {
        Gotoxy(i, 44);
        for(int cnt = 1; cnt <= 7; cnt++)
            std::cout << ' ';
    }
}
void Print_hint(int x, int y) {
    if(!g_setting_info.open_hint)
        return;
    Clear_hint();
    Hint hint = Get_hint(x, y);
    Set_color(COL_NORMAL);
    if(hint.empty()) {
        Gotoxy(7, 44);
        std::cout << "nothing";
    } else {
        for(int v = 1; v <= 9; v++) {
            int pos_x = Get_center_v_x(v);
            int pos_y = Get_center_v_y(v);
            Gotoxy(pos_x, pos_y);
            if(hint.count(v)) {
                std::cout << v;
            } else {
                std::cout << " ";
            }
        }
    }
    Gotoxy(12, 46);
    std::cout << x+1;
    Gotoxy(12, 48);
    std::cout << y+1;
}