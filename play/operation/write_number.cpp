#include "../../sudoku.h"


static void Clear_sequence() {
    while((int)g_operation_sequence.size()-1 > g_operation_sequence_id)
        g_operation_sequence.pop_back();
}
bool Write_number(int x, int y, int val, int ty) {
    if(g_game_board.init[x][y])
        return 0;
    if(g_game_board.now[x][y] == val)
        return 1;
    if(ty) {
        Clear_sequence();
        Operation_node now;
        now.x = x;
        now.y = y;
        now.fr = g_game_board.now[x][y];
        now.to = val;
        g_operation_sequence.push_back(now);
        ++g_operation_sequence_id;
    }
    g_game_board.now[x][y] = val;
    Modify_number(x, y, val);
    return 1;
}