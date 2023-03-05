#include "../../sudoku.h"
#include <iostream>

static void Print_many(std::string s, int cnt) {
    for(int i = 0; i < cnt; i++)
        std::cout << s;
}

static void Print_block(void) {
    Set_color(COL_TITLE);
    Gotoxy(0, 0);
    std::cout << "┍";
    Print_many("━", 33);
    std::cout << "┑";
    Gotoxy(24, 0);
    std::cout << "┕";
    Print_many("━", 33);
    std::cout << "┙";
    for(int i = 1; i <= 23; i++) {
        Gotoxy(i, 0);
        std::cout << "│";
        Gotoxy(i, 34);
        std::cout << "│";
    }
}

static void Print_hint_title() {
    Set_color(COL_TITLE);
    Gotoxy(2, 36);
    std::cout << "Hint: You can put";
    Gotoxy(12, 42);
    std::cout << "in ( , )";
}

static void Print_message_title() {
    Set_color(COL_TITLE);
    Gotoxy(14, 36);
    std::cout << "Message:";
}

void Print_board(void) {
    Clear_screen();
    Print_block();
    if(g_setting_info.open_hint) {
        Print_hint_title();
    }
    Print_message_title();
    for(int row = 0; row < BOARD_SIZE; row++)
        for(int col = 0; col < BOARD_SIZE; col++)
            Modify_number(row, col, g_game_board.now[row][col]);
    Add_cursor(g_cursor_x, g_cursor_y);
    Print_hint(g_cursor_x, g_cursor_y);
}

static int Get_center_x(int x) {
    return 2 + 2 * x + (x / BLOCK_SIZE) * 2;
}

static int Get_center_y(int y) {
    return 3 + 3 * y + (y / BLOCK_SIZE) * 2;
}

void Delete_cursor(int x, int y) {
    Set_color(COL_NORMAL);
    int center_x = Get_center_x(x);
    int center_y = Get_center_y(y);
    Gotoxy(center_x - 1, center_y - 1);
    std::cout << " ";
    Gotoxy(center_x - 1, center_y + 1);
    std::cout << " ";
    Gotoxy(center_x + 1, center_y - 1);
    std::cout << " ";
    Gotoxy(center_x + 1, center_y + 1);
    std::cout << " ";
}

void Add_cursor(int x, int y) {
    Set_color(Judge_legal(x, y) ? COL_NORMAL : COL_TITLE);
    int center_x = Get_center_x(x);
    int center_y = Get_center_y(y);
    Gotoxy(center_x - 1, center_y - 1);
    std::cout << "┍";
    Gotoxy(center_x - 1, center_y + 1);
    std::cout << "┑";
    Gotoxy(center_x + 1, center_y - 1);
    std::cout << "┕";
    Gotoxy(center_x + 1, center_y + 1);
    std::cout << "┙";
}

void Modify_number(int x, int y, int val) {
    Set_color(g_game_board.init[x][y] ? COL_NORMAL : COL_ERROR);
    int center_x = Get_center_x(x);
    int center_y = Get_center_y(y);
    Gotoxy(center_x, center_y);
    if(val == 0)
        std::cout << "×";
    else    
        std::cout << val;
}