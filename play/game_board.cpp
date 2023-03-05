#include "../sudoku.h"

Board g_game_board;

Operation_sequence g_operation_sequence;

int g_operation_sequence_id;


void Init_board(void) {
    g_operation_sequence.clear();
    g_operation_sequence_id = -1;
    Move_init();
}