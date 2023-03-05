#include "../sudoku.h"
#include <iostream>


void Run_game() {
    Init_board();
    Print_board();
    while(true) {
        Add_cursor(g_cursor_x, g_cursor_y);
        Print_hint(g_cursor_x, g_cursor_y);
        if(Judge_win()) {
            Print_message("You win! Congratulations", COL_TITLE);
        }
        Key_value key = Get_key();
        if(Check_key(K_UP, key)) {
            if(!Go_up()) {
                Print_message("Error: Cannot go up.", COL_ERROR);
                continue;
            }
        } else if(Check_key(K_DOWN, key)) {
            if(!Go_down()) {
                Print_message("Error: Cannot go down.", COL_ERROR);
                continue;
            }
        } else if(Check_key(K_LEFT, key)) {
            if(!Go_left()) {
                Print_message("Error: Cannot go left.", COL_ERROR);
                continue;
            }
        } else if(Check_key(K_RIGHT, key)) {
            if(!Go_right()) {
                Print_message("Error: Cannot go right.", COL_ERROR);
                continue;
            }
        } else if(Check_key(K_REGAME, key)) {
            Regame();
            continue;
        } else if(Check_key(K_UNDO, key)) {
            if(!Undo()) {
                Print_message("Error: Cannot undo latest operation.", COL_ERROR);
                continue;
            }
        } else if(Check_key(K_REDO, key)) {
            if(!Redo()) {
                Print_message("Error: Cannot redo latest operation.", COL_ERROR);
                continue;
            }
        } else if(Check_key(K_COMPLETE, key)) {
            Complete_game();
            continue;
        } else if(Check_key(K_COPY, key)) {
            if(!Copy_to_paste()) {
                Print_message("Error: Cannot put the board to copy & paste.", COL_ERROR);
                continue;
            }
        } else if(Check_key(K_QUIT, key)) {
            Save_board();
            return ;
        } else {
            bool flag_con = 0;
            for(int val = 0; val <= 9; val++) {
                if(Check_key(Key_type(K_ZERO + val), key)) {
                    if(!Write_number(g_cursor_x, g_cursor_y, val, 1)) {
                        Print_message("Error: Cannot write down the number here.", COL_ERROR);
                        flag_con = 1;
                    }
                    break;
                }
            }
            if(flag_con)
                continue;
        }


        Print_message("", COL_NORMAL);
    }
}