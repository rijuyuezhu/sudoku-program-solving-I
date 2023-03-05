#include "../../sudoku.h"
#include <fstream>

bool Save_board(void) {
    std::ofstream outFile("sudoku_data/saves");
    if(!outFile)
        return 0;
    outFile << Board_to_string(g_game_board);
    outFile.close();
    return 1;
}