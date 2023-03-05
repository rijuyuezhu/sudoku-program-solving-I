#include "sudoku.h"
#include <iostream>

constexpr int ITEM_SIZE = 3;

enum Item {
    START,
    SETTING,
    EXIT
};
static int point;

static void Print_menu() {
    Set_color(COL_TITLE);
    Gotoxy(3, 15);
    std::cout << "--- Welcome To Sudoku Game ---";
    Set_color(COL_NORMAL);
    Gotoxy(7, 25);
    std::cout << "Start Game";
    Gotoxy(13, 26);
    std::cout << "Settings";
    Gotoxy(19, 28);
    std::cout << "Exit";
}

static int Get_row_of_point() {
    int row = 0;
    if(point == START)
        row = 7;
    else if(point == SETTING)
        row = 13;
    else if(point == EXIT)
        row = 19;
    return row;
}

static void Print_point() {
    Set_color(COL_NORMAL);
    int row = Get_row_of_point();
    Gotoxy(row, 10);
    std::cout << "<";
    Gotoxy(row, 49);
    std::cout << ">";
}

static void Erase_point() {
    Set_color(COL_NORMAL);
    int row = Get_row_of_point();
    Gotoxy(row, 10);
    std::cout << " ";
    Gotoxy(row, 49);
    std::cout << " ";
}

static void Point_down() {
    Erase_point();
    point = (point + 1) % ITEM_SIZE;
    Print_point();
}

static void Point_up() {
    Erase_point();
    point = (point - 1 + ITEM_SIZE) % ITEM_SIZE;
    Print_point();
}

void Start_menu(void) {
    point = START;
    Clear_screen();
    Print_menu();
    Print_point();
    while(true) {
        Key_value key = Get_key();
        if(Check_key(K_DOWN, key))
            Point_down();
        else if(Check_key(K_UP, key))
            Point_up();
        else if(Check_key(K_QUIT, key))
            return ;
        else if(Check_key(K_ENTER, key)) {
            if(point == EXIT)
                return ;
            else if(point == START)
                Generate_menu();
            else if(point == SETTING)
                Setting_menu();
            Clear_screen();
            Print_menu();
            Print_point();
        }
    }
}