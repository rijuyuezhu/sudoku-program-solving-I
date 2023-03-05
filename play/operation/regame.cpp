#include "../../sudoku.h"
#include <cstring>
bool Regame(void) {
    Print_message("Replay your sudoku?", COL_NORMAL);
    Key_value key = Get_key();
    if(Check_key(K_ENTER, key)) {
        memcpy(g_game_board.now, g_game_board.init, sizeof(g_game_board.init));
        Init_board();
        Print_board();
        return 1;
    } else {
        Print_message("", COL_NORMAL);
        return 0;
    }
}