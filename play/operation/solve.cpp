#include "../../sudoku.h"


namespace Dancing_Link_X {
    constexpr int MAXR = 729, MAXC = 324, MAXITEM = MAXR * 4 + MAXC + 1;
    static int U[MAXITEM+1], D[MAXITEM+1], L[MAXITEM+1], R[MAXITEM+1], row[MAXITEM+1], col[MAXITEM+1], siz[MAXC+1], rh[MAXR+1];
    static int n, m, tot, ans[MAXR+1], ans_num;
    static void Init(int _n, int _m) {
        n = _n, m = _m;
        tot = m+1;
        for(int i = 0; i <= m; i++) {
            U[i] = D[i] = i;
            L[i] = i-1;
            R[i] = i+1;
            siz[i] = 0;
        }
        for(int i = 1; i <= n; i++)
            rh[i] = -1;
        L[0] = m; R[m] = 0;
    }
    static void Insert(int r, int c) {
        ++siz[c];
        row[tot] = r;
        col[tot] = c;
        D[tot] = c;
        U[tot] = U[c];
        D[U[c]] = tot;
        U[c] = tot;
        if(rh[r] == -1) {
            rh[r] = L[tot] = R[tot] = tot;
        } else {
            R[tot] = rh[r];
            L[tot] = L[rh[r]];
            R[L[rh[r]]] = tot;
            L[rh[r]] = tot;
        }
        ++tot;
    }
    static void Delete(int c) {
        R[L[c]] = R[c];
        L[R[c]] = L[c];
        for(int i = D[c]; i != c; i = D[i])
            for(int j = R[i]; j != i; j = R[j]) {
                U[D[j]] = U[j];
                D[U[j]] = D[j];
                --siz[col[j]];
            }
    }
    static void Resume(int c) {
        for(int i = U[c]; i != c; i = U[i])
            for(int j = L[i]; j != i; j = L[j]) {
                U[D[j]] = D[U[j]] = j;
                ++siz[col[j]];
            }
        R[L[c]] = L[R[c]] = c;
    }
    static bool Dance(int step) {
        if(R[0] == 0) {
            ans_num = step;
            return 1;
        }
        int c = R[0];
        for(int i = R[0]; i != 0; i = R[i])
            if(siz[i] < siz[c])
                c = i;
        Delete(c);
        for(int i = D[c]; i != c; i = D[i]) {
            ans[step] = row[i];
            for(int j = R[i]; j != i; j = R[j])
                Delete(col[j]);
            if(Dance(step + 1))
                return 1;
            for(int j = L[i]; j != i; j = L[j])
                Resume(col[j]);
        }
        Resume(c);
        return 0;
    }
}
using Dancing_Link_X::MAXR;
using Dancing_Link_X::MAXC;

struct Line{
    int x, y, value;
};

static Line lines[MAXR+1];
static int num_of_line;

static int Calc_num_of_line(const Board &NowBoard) {
    int ret = 0;
    for(int row = 0; row < 9; row++)
        for(int col = 0; col < 9; col++)
            if(NowBoard.init[row][col])
                ret++;
            else
                ret += 9;
    return ret;
}

static int Block_num(int row, int col) {
    return (row / 3) * 3 + (col / 3);
}

static void Add_line(int row, int col, int val) {
    lines[++num_of_line] = {row, col, val};
    Dancing_Link_X::Insert(num_of_line, row * 9 + col + 1);
    //1-81: whether(row, col) exists.
    Dancing_Link_X::Insert(num_of_line, 81 + row * 9 + val);
    //82-162: whether (row, val) exists.
    Dancing_Link_X::Insert(num_of_line, 162 + col * 9 + val);
    //163-243: whether (col, val) exists.
    Dancing_Link_X::Insert(num_of_line, 243 + Block_num(row, col) * 9 + val);
    //244-324: whether (block(row, col), val) exists.
}

static void Board_to_Dance(const Board &NowBoard) {
    num_of_line = Calc_num_of_line(NowBoard);
    Dancing_Link_X::Init(num_of_line, MAXC);
    num_of_line = 0;
    for(int row = 0; row < 9; row++)
        for(int col = 0; col < 9; col++)
            if(NowBoard.init[row][col])
                Add_line(row, col, NowBoard.init[row][col]);
            else {
                for(int val = 1; val <= 9; val++)
                Add_line(row, col, val);
            }
}
Board Solve_game(Board NowBoard) {
    Board_to_Dance(NowBoard);
    if(Dancing_Link_X::Dance(0)) {
        for(int i = 0; i < Dancing_Link_X::ans_num; i++) {
            int id = Dancing_Link_X::ans[i];
            NowBoard.now[lines[id].x][lines[id].y] = lines[id].value;
        }
    } else {
        NowBoard.now[0][0] = -1;
    }
    return NowBoard;
}