#include "../../sudoku.h"

bool Copy_to_paste(void) {
    Put_to_cp(Board_to_string(g_game_board));
    return 1;
}