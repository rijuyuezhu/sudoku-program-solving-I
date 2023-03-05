#include "../../sudoku.h"

bool Undo(void) {
    if(g_operation_sequence_id < 0)
        return 0;
    Operation_node now = g_operation_sequence[g_operation_sequence_id];
    if(!Write_number(now.x, now.y, now.fr, 0))
        return 0;
    Move_cursor(now.x, now.y);
    --g_operation_sequence_id;
    return 1;
}

bool Redo(void) {
    if(g_operation_sequence_id == (int)g_operation_sequence.size()-1)
        return 0;
    Operation_node now = g_operation_sequence[g_operation_sequence_id+1];
    if(!Write_number(now.x, now.y, now.to, 0))
        return 0;
    Move_cursor(now.x, now.y);
    ++g_operation_sequence_id;
    return 1;
}