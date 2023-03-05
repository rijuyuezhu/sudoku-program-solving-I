#include "../sudoku.h"
#include "conio.h"
#include <cctype>

Key_value Get_key(void) {
    Key_value key;
    key.first = getch();
    if(key.first == 0 || key.first == 224)
        key.second = getch();
    else
        key.second = 0;
    if('a' <= key.first && key.first <= 'z')
        key.first = toupper(key.first);
    return key;
}

static const std::string UNKNOWN = "";

std::string Get_keystring(Key_value key) {
    if(key.first == 0) {
        return UNKNOWN;
    } else if(key.first == 224) {
        int v = key.second;
        if(v == 72)
            return " UP  ";
        else if(v == 80)
            return " DOWN";
        else if(v == 75)
            return " LEFT";
        else if(v == 77)
            return "RIGHT";
        else
            return UNKNOWN;
    } else {
        int v = key.first;
        if(v == 32)
            return "SPACE";
        else if(v == 9)
            return " TAB ";
        else if(v == 27)
            return " ESC ";
        else if(v == 13)
            return "ENTER";
        else if(v == 8)
            return " BACK";
        else if(isalpha(v))
            return "  " + std::string(1, char(toupper(v))) + "  ";
        else if(isgraph(v))
            return "  " + std::string(1, char(v)) + "  ";
        else
            return UNKNOWN;
    }
    return UNKNOWN;
}