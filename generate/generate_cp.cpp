#include "../sudoku.h"

bool Generate_cp(void) {
    Board ret = String_to_board(Get_from_cp());
    if(ret.init[0][0] == -1)
        return 0;
    g_game_board = ret;
    return 1;
}