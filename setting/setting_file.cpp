#include "../sudoku.h"
#include <fstream>

static void Get_default_setting() {
    g_setting_info.difficulty = 1;
    g_setting_info.open_hint = 1;
    g_setting_info.key_board[K_UP] = {'W', 0};
    g_setting_info.key_board[K_DOWN] = {'S', 0};
    g_setting_info.key_board[K_LEFT] = {'A', 0};
    g_setting_info.key_board[K_RIGHT] = {'D', 0};
    g_setting_info.key_board[K_REGAME] = {'R', 0};
    g_setting_info.key_board[K_UNDO] = {'Z', 0};
    g_setting_info.key_board[K_REDO] = {'Y', 0};
    g_setting_info.key_board[K_ZERO] = {'0', 0};
    g_setting_info.key_board[K_ONE] = {'1', 0};
    g_setting_info.key_board[K_TWO] = {'2', 0};
    g_setting_info.key_board[K_THREE] = {'3', 0};
    g_setting_info.key_board[K_FOUR] = {'4', 0};
    g_setting_info.key_board[K_FIVE] = {'5', 0};
    g_setting_info.key_board[K_SIX] = {'6', 0};
    g_setting_info.key_board[K_SEVEN] = {'7', 0};
    g_setting_info.key_board[K_EIGHT] = {'8', 0};
    g_setting_info.key_board[K_NINE] = {'9', 0};
    g_setting_info.key_board[K_COMPLETE] = {'H', 0};
    g_setting_info.key_board[K_COPY] = {'C', 0};
    g_setting_info.key_board[K_QUIT] = {'Q', 0};
    g_setting_info.key_board[K_ENTER] = {32, 0};
}
void Load_setting() {
    std::ifstream inFile("sudoku_data/setting", std::ios::binary);
    if(!inFile) {
        Get_default_setting();
        return ;
    }
    if(!inFile.read((char *)&g_setting_info, sizeof(Setting_info)).good()) {
        Get_default_setting();
    }
    inFile.close();
}

void Save_setting() {
    std::ofstream outFile("sudoku_data/setting", std::ios::binary);
    if(!outFile)
        return ;
    outFile.write((char *)&g_setting_info, sizeof(Setting_info));
    outFile.close();
}