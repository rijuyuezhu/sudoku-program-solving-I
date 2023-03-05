#include "../sudoku.h"
#include <cstring>
static constexpr int HALF_STRING_LENGTH = 81;
static constexpr int FULL_STRING_LENGTH = 162;
static Board EMPTY_BOARD = {{{-1}}, {0}};


static bool Is_same(const Board &NowBoard) {
    for(int row = 0; row < BOARD_SIZE; row++)
        for(int col = 0; col < BOARD_SIZE; col++)
            if(NowBoard.init[row][col] != NowBoard.now[row][col])
                return 0;
    return 1;
}
std::string Board_to_string(Board NowBoard) {
    std::string ret;
    for(int row = 0; row < BOARD_SIZE; row++) {
        for(int col = 0; col < BOARD_SIZE; col++) {
            ret += char(NowBoard.init[row][col] + '0');
            ret += ' ';
        }
        ret += '\n';
    }
    if(Is_same(NowBoard)) return ret;
    for(int row = 0; row < BOARD_SIZE; row++) {
        for(int col = 0; col < BOARD_SIZE; col++) {
            ret += char(NowBoard.now[row][col] + '0');
            ret += ' ';
        }
        ret += '\n';
    }
    return ret;
}
Board String_to_board(std::string s) {
    std::string t;
    for(auto v : s)
        if(!isspace(v))
            t += v;
    int id = 0;
    Board ret;
    if(t.length() == HALF_STRING_LENGTH) {
        for(int row = 0; row < BOARD_SIZE; row++)
            for(int col = 0; col < BOARD_SIZE; col++)
                ret.init[row][col] = ret.now[row][col] = t[id++] - '0';
    } else if(t.length() == FULL_STRING_LENGTH) {
        for(int row = 0; row < BOARD_SIZE; row++)
            for(int col = 0; col < BOARD_SIZE; col++)
                ret.init[row][col] = t[id++] - '0';
        for(int row = 0; row < BOARD_SIZE; row++)
            for(int col = 0; col < BOARD_SIZE; col++)
                ret.now[row][col] = t[id++] - '0';
    } else
        ret = EMPTY_BOARD;
    return ret;
}