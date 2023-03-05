#include "../sudoku.h"
#include <fstream>

bool Generate_saves(void) {
    std::ifstream inFile("sudoku_data/saves");
    if(!inFile)
        return 0;
    std::string text, tmp;
    while(inFile >> tmp)
        text += tmp;
    inFile.close();
    Board ret = String_to_board(text);
    if(ret.init[0][0] == -1)
        return 0;
    g_game_board = ret;
    return 1;
}