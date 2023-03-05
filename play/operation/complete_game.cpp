#include "../../sudoku.h"

bool Complete_game(void) {
    Print_message("Complete your sudoku?", COL_NORMAL);
    Key_value key = Get_key();
    if(Check_key(K_ENTER, key)) {
        Board ret = Solve_game(g_game_board);
        if(ret.now[0][0] == -1) {
            Print_message("Error: No answer to the sudoku.", COL_ERROR);
            return 0;
        }
        g_game_board = ret;
        Init_board();
        Print_board();
        return 1;
    } else {
        Print_message("", COL_NORMAL);
        return 0;
    }
}  