#include "../sudoku.h"
#include <fstream>
#include <random>

static constexpr int HALF_STRING_LENGTH = 81;

static std::string Get_path(void) {
    switch(g_setting_info.difficulty) {
        case 1:
            return "sudoku_data/board1";
        case 2:
            return "sudoku_data/board2";
        case 3:
            return "sudoku_data/board3";
        default:
            return "";
    }
    return "";
}

static bool Read_string(std::string &text) {
    std::string path = Get_path();
    if(path.empty())
        return 0;
    std::ifstream inFile(path.c_str());
    if(!inFile)
        return 0;
    text.clear();
    std::string tmp;
    while(inFile >> tmp)
        text += tmp;
    inFile.close();
    return 1;
}

bool Generate_lib(void) {
    std::string text;
    if(!Read_string(text))
        return 0;
    if(text.empty())
        return 0;
    if(text.length() % HALF_STRING_LENGTH != 0)
        return 0;
    std::vector<Board> boards;
    for(int i = 0; i < (int)text.length(); i += HALF_STRING_LENGTH)
        boards.push_back(String_to_board(text.substr(i, HALF_STRING_LENGTH)));
    
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<int> distr(0, boards.size()-1);

    g_game_board = boards[distr(eng)];
    return 1;
}