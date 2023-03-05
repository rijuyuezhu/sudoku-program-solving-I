#include "../sudoku.h"
#include <iostream>


static int point;

constexpr int COL_LEFT_TWO = 8;
constexpr int COL_RIGHT_ONE = 5;
constexpr int ROW_UP_FIVE = 3;
constexpr int ROW_DOWN_THREE = 2;
const std::string KEY_STRING[KEY_TYPE_SIZE] = {
    "UP",
    "DOWN",
    "LEFT",
    "RIGHT",
    "REGAME",
    "UNDO",
    "REDO",
    "ZERO",
    "ONE",
    "TWO",
    "THREE",
    "FOUR",
    "FIVE",
    "SIX",
    "SEVEN",
    "EIGHT",
    "NINE",
    "FINISH",
    "COPY",
    "QUIT",
    "ENTER"
};

bool Check_key(Key_type kt, Key_value key) {
    return g_setting_info.key_board[kt] == key;
}

static void Get_row_and_col(int point, int &row, int &col) {
    row = point % COL_LEFT_TWO;
    col = point / COL_LEFT_TWO;
}

static int Get_point(int row, int col) {
    return col * COL_LEFT_TWO + row;
}

static void Print_menu() {
    Set_color(COL_TITLE);
    Gotoxy(3, 18);
    std::cout << "--- Choose Your Keys ---";
    Set_color(COL_NORMAL);
    for(int v = 0; v < KEY_TYPE_SIZE; v++) {
        int row, col;
        Get_row_and_col(v, row, col);
        Gotoxy(6 + 2 * row, 4 + col * 17);
        std::cout << KEY_STRING[v];
    }
    
}

static void Print_key(int v) {
    Set_color(COL_NORMAL);
    int row, col;
    Get_row_and_col(v, row, col);
    Gotoxy(6 + 2 * row, 12 + col * 17);
    std::cout << Get_keystring(g_setting_info.key_board[v]);
}

static void Print_all_keys() {
    for(int v = 0; v < KEY_TYPE_SIZE; v++)
        Print_key(v);
}

static void Print_point() {
    Set_color(COL_NORMAL);
    int row, col;
    Get_row_and_col(point, row, col);
    Gotoxy(6 + 2 * row, 11 + col * 17);
    std::cout << "<";
    Gotoxy(6 + 2 * row, 17 + col * 17);
    std::cout << ">";
}

static void Erase_point() {
    Set_color(COL_NORMAL);
    int row, col;
    Get_row_and_col(point, row, col);
    Gotoxy(6 + 2 * row, 11 + col * 17);
    std::cout << " ";
    Gotoxy(6 + 2 * row, 17 + col * 17);
    std::cout << " ";
}
static void Point_down() {
    Erase_point();
    int row, col;
    Get_row_and_col(point, row, col);
    if(col == 2)
        row = (row + 1) % COL_RIGHT_ONE;
    else
        row = (row + 1) % COL_LEFT_TWO;
    point = Get_point(row, col);
    Print_point();
}

static void Point_up() {
    Erase_point();
    int row, col;
    Get_row_and_col(point, row, col);
    if(col == 2)
        row = (row - 1 + COL_RIGHT_ONE) % COL_RIGHT_ONE;
    else
        row = (row - 1 + COL_LEFT_TWO) % COL_LEFT_TWO;
    point = Get_point(row, col);
    Print_point();
}

static void Point_left() {
    Erase_point();
    int row, col;
    Get_row_and_col(point, row, col);
    if(row < 5)
        col = (col - 1 + ROW_UP_FIVE) % ROW_UP_FIVE;
    else
        col = (col - 1 + ROW_DOWN_THREE) % ROW_DOWN_THREE;
    point = Get_point(row, col);
    Print_point();
}

static void Point_right() {
    Erase_point();
    int row, col;
    Get_row_and_col(point, row, col);
    if(row < 5)
        col = (col + 1) % ROW_UP_FIVE;
    else
        col = (col + 1) % ROW_DOWN_THREE;
    point = Get_point(row, col);
    Print_point();
}

static void Print_setting_message(std::string s, int color) {
    Set_color(color);
    Gotoxy(22, 7);
    std::cout << s;
    for(int i = s.length()+1; i <= 53; i++)
        std::cout << ' ';
}

static int Try_modify_key() {
    Print_setting_message("Please press the key you want to use.", COL_NORMAL);
    Key_value key = Get_key();
    std::string key_string = Get_keystring(key);
    if(key_string.empty())
        return -1;
    for(int v = 0; v < KEY_TYPE_SIZE; v++)
        if(v != point && g_setting_info.key_board[v] == key)
            return -2;
    g_setting_info.key_board[point] = key;
    return 1;
}

void Key_board_menu(void) {
    point = K_UP;
    Clear_screen();
    Print_menu();    
    Print_all_keys();
    Print_point();
    while(true) {
        Key_value key = Get_key();
        if(Check_key(K_DOWN, key))
            Point_down();
        else if(Check_key(K_UP, key))
            Point_up();
        else if(Check_key(K_LEFT, key))
            Point_left();
        else if(Check_key(K_RIGHT, key))
            Point_right();
        else if(Check_key(K_QUIT, key))
            return ;
        else if(Check_key(K_ENTER, key)) {
            int sta = Try_modify_key();
            if(sta == 1) {
                Print_setting_message("The key has been modified!", COL_NORMAL);
                Print_key(point);
                Save_setting();
                continue;
            } else if(sta == -1) {
                Print_setting_message("Error: Undefined key!", COL_ERROR);
                continue;
            } else if(sta == -2) {
                Print_setting_message("Already exists key!", COL_ERROR);
                continue;
            }
        }
        Print_setting_message("", COL_NORMAL);
    }
}