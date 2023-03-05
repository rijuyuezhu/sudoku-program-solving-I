/**
 * @author Wenrui Huang
 * @date 2022-11-02
 * @brief the header file of the whole project
*/

#ifndef SUDOKUH
#define SUDOKUH

#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>

constexpr int BOARD_SIZE = 9;
constexpr int BLOCK_SIZE = 3;
constexpr int SCREEN_WIDTH = 60;
constexpr int SCREEN_HEIGHT = 25;
constexpr int NUMBER_SIZE = 9;
constexpr int KEY_TYPE_SIZE = 21;
constexpr int COL_NORMAL = 0xF1;
constexpr int COL_TITLE = 0xF5;
constexpr int COL_ERROR = 0xF4; 

enum Key_type {
    K_UP,
    K_DOWN,
    K_LEFT,
    K_RIGHT,
    K_REGAME,
    K_UNDO,
    K_REDO,
    K_ZERO,
    K_ONE,
    K_TWO,
    K_THREE,
    K_FOUR,
    K_FIVE,
    K_SIX,
    K_SEVEN,
    K_EIGHT,
    K_NINE,
    K_COMPLETE,
    K_COPY,
    K_QUIT,
    K_ENTER
};

struct Board {
    int init[BOARD_SIZE][BOARD_SIZE];
    int now[BOARD_SIZE][BOARD_SIZE];
};

typedef std::pair<int, int> Key_value;

struct Setting_info {
    int difficulty;
    int open_hint;
    Key_value key_board[KEY_TYPE_SIZE];
};

typedef std::set<int> Hint;

struct Operation_node {
    int x, y, fr, to;
};

typedef std::pair<int, int> Coord;
typedef std::vector<Operation_node> Operation_sequence;

void Gotoxy(int x, int y);
void Clear_screen(void);
void Set_color(int color);
void Set_window_color(int color);
void Put_to_cp(std::string s);
std::string Get_from_cp(void);
std::string Board_to_string(Board NowBoard);
Board String_to_board(std::string s);
Key_value Get_key(void);
std::string Get_keystring(Key_value key);
bool Generate_lib(void);
bool Generate_saves(void);
bool Generate_cp(void);
void Generate_menu(void);
extern Board g_game_board;
extern Operation_sequence g_operation_sequence;
extern int g_operation_sequence_id;
void Init_board(void);
Hint Get_hint(int x, int y);
bool Judge_legal(int x, int y);
std::set<Coord> Get_illegal(void);
bool Judge_win();
extern int g_cursor_x;
extern int g_cursor_y;
void Move_init(void);
bool Go_up(void);
bool Go_down(void);
bool Go_left(void);
bool Go_right(void);
bool Move_cursor(int x, int y);
bool Write_number(int x, int y, int val, int ty);
bool Regame(void);
bool Undo(void);
bool Redo(void);
Board Solve_game(Board NowBoard);
bool Complete_game(void);
bool Copy_to_paste(void);
bool Save_board(void);
void Print_board(void);
void Delete_cursor(int x, int y);
void Add_cursor(int x, int y);
void Modify_number(int x, int y, int val);
void Print_hint(int x, int y);
void Print_message(std::string s, int color);
void Run_game(void);
extern Setting_info g_setting_info;
void Setting_menu(void);
void Modify_difficulty(int val);
void Modify_open_hint(int val);
void Key_board_menu(void);
bool Check_key(Key_type kt, Key_value key);
void Modify_key_board(Key_type kt, Key_value key);
void Load_setting(void);
void Save_setting(void);
void Start_menu(void);
int main(void);



#endif