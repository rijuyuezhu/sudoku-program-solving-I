#include "../sudoku.h"


static bool Hint_check(int val, int x, int y) {
    for(int row = 0; row < BOARD_SIZE; row++)
        if(row != x && g_game_board.now[row][y] == val)
            return 0;
    for(int col = 0; col < BOARD_SIZE; col++)
        if(col != y && g_game_board.now[x][col] == val)
            return 0;
    int block_r = x / BLOCK_SIZE * BLOCK_SIZE;
    int block_c = y / BLOCK_SIZE * BLOCK_SIZE;
    for(int row = block_r; row < block_r + BLOCK_SIZE; row++)
        for(int col = block_c; col < block_c + BLOCK_SIZE; col++)
            if((row != x || col != y) && g_game_board.now[row][col] == val)
                return 0;
    return 1;
}

Hint Get_hint(int x, int y) {
    if(g_game_board.init[x][y])
        return Hint();
    Hint ret;
    for(int v = 1; v <= NUMBER_SIZE; v++)
        if(Hint_check(v, x, y))
            ret.insert(v);
    return ret;
}

bool Judge_legal(int x, int y) {
    if(g_game_board.init[x][y])
        return 1;
    if(g_game_board.now[x][y] == 0)
        return 1;
    return Hint_check(g_game_board.now[x][y], x, y);
}

std::set<Coord> Get_illegal() {
    std::set<Coord> ret;
    for(int row = 0; row < BOARD_SIZE; row++)
        for(int col = 0; col < BOARD_SIZE; col++)
            if(!Judge_legal(row, col))
                ret.insert({row, col});
    return ret;
}

bool Judge_win() {
    for(int row = 0; row < BOARD_SIZE; row++)
        for(int col = 0; col < BOARD_SIZE; col++)
            if(g_game_board.now[row][col] == 0)
                return 0;
    return Get_illegal().empty();
}