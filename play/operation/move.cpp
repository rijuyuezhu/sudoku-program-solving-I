#include "../../sudoku.h"

int g_cursor_x;

int g_cursor_y;


void Move_init() {
    g_cursor_x = g_cursor_y = 4;
}

bool Go_up(void) {
    if(g_cursor_x == 0)
        return 0;
    Delete_cursor(g_cursor_x, g_cursor_y);
    g_cursor_x--;
    Add_cursor(g_cursor_x, g_cursor_y);
    return 1;
}

bool Go_down(void) {
    if(g_cursor_x == BOARD_SIZE-1)
        return 0;
    Delete_cursor(g_cursor_x, g_cursor_y);
    g_cursor_x++;
    Add_cursor(g_cursor_x, g_cursor_y);
    return 1;
}

bool Go_left(void) {
    if(g_cursor_y == 0)
        return 0;
    Delete_cursor(g_cursor_x, g_cursor_y);
    g_cursor_y--;
    Add_cursor(g_cursor_x, g_cursor_y);
    return 1;
}

bool Go_right(void) {
    if(g_cursor_y == BOARD_SIZE-1)
        return 0;
    Delete_cursor(g_cursor_x, g_cursor_y);
    g_cursor_y++;
    Add_cursor(g_cursor_x, g_cursor_y);
    return 1;
}

bool Move_cursor(int x, int y) {
    Delete_cursor(g_cursor_x, g_cursor_y);
    g_cursor_x = x;
    g_cursor_y = y;
    Add_cursor(g_cursor_x, g_cursor_y);
    return 1;
}