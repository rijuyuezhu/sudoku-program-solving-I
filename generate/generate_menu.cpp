#include "../sudoku.h"
#include <iostream>

static constexpr int ITEM_SIZE = 4;

enum Item {
    LIBRARY,
    SAVES,
    CP,
    EXIT
};

static int point;

static void Print_menu() {
    Set_color(COL_TITLE);
    Gotoxy(3, 17);
    std::cout << "--- Generate Your Game ---";
    Set_color(COL_NORMAL);
    Gotoxy(7, 18);
    std::cout << "Start From Game Library.";
    Gotoxy(11, 19);
    std::cout << "Start From Last Saves.";
    Gotoxy(15, 18);
    std::cout << "Start From Copy & Paste.";
    Gotoxy(19, 26);
    std::cout << "Go Back.";
}

static int Get_row_of_point() {
    int row = 0;
    if(point == LIBRARY)
        row = 7;
    else if(point == SAVES)
        row = 11;
    else if(point == CP)
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

static bool Generate_game() {
    bool flag = 0;
    switch(point) {
        case LIBRARY:
            flag = Generate_lib();
            break;
        case SAVES:
            flag = Generate_saves();
            break;
        case CP:
            flag = Generate_cp();
            break;
    }
    if(!flag)
        return 0;
    Run_game();
    return 1;
}

static void Print_fail() {
    Set_color(COL_ERROR);
    Gotoxy(22, 7);
    std::cout << "Error: Fail to start the game. Try other ways.";
}
static void Erase_fail() {
    Set_color(COL_ERROR);
    Gotoxy(22, 7);
    for(int i = 0; i < 48; i++)
        std::cout << ' ';
}
void Generate_menu(void) {
    point = LIBRARY;
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
            else if(Generate_game()) {
                return ;
            } else {
                Print_fail();
                continue;
            }
        }
        Erase_fail();
    }
}