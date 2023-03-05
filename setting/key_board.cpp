#include "../sudoku.h"

void Modify_key_board(Key_type key, Key_value val) {
    g_setting_info.key_board[key] = val;
}