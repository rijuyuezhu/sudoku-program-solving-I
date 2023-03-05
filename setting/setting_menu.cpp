#include "../sudoku.h"
#include <iostream>
Setting_info g_setting_info;

constexpr int ITEM_SIZE = 4;

enum Item {
    DIFFICULTY,
    OPEN_HINT,
    KEYBOARD,
    EXIT
};

static int point;

static void Print_menu() {
    Set_color(COL_TITLE);
    Gotoxy(3, 17);
    std::cout << "--- Modify Your Setting---";
    Set_color(COL_NORMAL);
    Gotoxy(7, 20);
    std::cout << "Difficulty <1~3>: ";
    Gotoxy(11, 21);
    std::cout << "Open Hint <Y/N>: ";
    Gotoxy(15, 22);
    std::cout << "Modify Your Keys";
    Gotoxy(19, 26);
    std::cout << "Go Back";
}

static int Get_row_of_point() {
    int row = 0;
    if(point == DIFFICULTY)
        row = 7;
    else if(point == OPEN_HINT)
        row = 11;
    else if(point == KEYBOARD)
        row = 15;
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

static void Print_difficulty() {
    Gotoxy(7, 38);
    std::cout << g_setting_info.difficulty;
}

static void Print_open_hint() {
    Gotoxy(11, 38);
    std::cout << (g_setting_info.open_hint ? "Y" : "N");
}
static void Print_setting_message(std::string s, int color) {
    Set_color(color);
    Gotoxy(22, 7);
    std::cout << s;
    for(int i = s.length()+1; i <= 53; i++)
        std::cout << ' ';
}

static bool Try_modify_difficulty() {
    Print_setting_message("Please input an interger in 1~3(included).", COL_NORMAL);
    Key_value key = Get_key();
    for(int v = 1; v <= 3; v++)
        if(Check_key(Key_type(K_ZERO + v), key)) {
            g_setting_info.difficulty = v;
            return 1;
        }
    return 0;
}

static bool Try_modify_open_hint() {
    Print_setting_message("Please input an interger, 0 for N, 1 for Y.", COL_NORMAL);
    Key_value key = Get_key();
    for(int v = 0; v <= 1; v++) 
        if(Check_key(Key_type(K_ZERO + v), key)) {
            g_setting_info.open_hint = v;
            return 1;
        }
    return 0;
}
void Setting_menu(void) {
    point = DIFFICULTY;
    Clear_screen();
    Print_menu();
    Print_point();
    Print_difficulty();
    Print_open_hint();
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
                return;
            else if(point == DIFFICULTY) {
                if(Try_modify_difficulty()) {
                    Print_setting_message("The difficulty of the game has been modified!", COL_NORMAL);
                    Print_difficulty();
                    Save_setting();
                    continue;
                } else {
                    Print_setting_message("Error: The difficulty must be 1~3(included).", COL_ERROR);
                    continue;
                }
            } else if(point == OPEN_HINT) {
                if(Try_modify_open_hint()) {
                    Print_setting_message("The open hint setting has been modified!", COL_NORMAL);
                    Print_open_hint();
                    Save_setting();
                    continue;
                } else {
                    Print_setting_message("Error: The difficulty must be 0~1(included).", COL_ERROR);
                    continue;
                }
            } else if(point == KEYBOARD) {
                Key_board_menu();
                Clear_screen();
                Print_menu();
                Print_point();
                Print_difficulty();
                Print_open_hint();
            }
        }
        Print_setting_message("", COL_NORMAL);
    }
}