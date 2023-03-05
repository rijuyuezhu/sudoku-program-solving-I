#include "../sudoku.h"
#include <windows.h>


void Put_to_cp(std::string s) {
    int len = s.length() + 1;
    HGLOBAL hMemory;
    LPTSTR lpMemory;
    if(!OpenClipboard(NULL))
        return ;
    if(!EmptyClipboard())
        return ;
    if(!(hMemory = GlobalAlloc(GMEM_MOVEABLE, len)))
        return ;
    if(!(lpMemory = (LPTSTR)GlobalLock(hMemory)))
        return ;
    memcpy_s(lpMemory, len, s.c_str(), len);
    GlobalUnlock(hMemory);
    if(!SetClipboardData(CF_TEXT, hMemory))
        return ;
    CloseClipboard();
}

std::string Get_from_cp(void) {
    std::string ret;
    LPTSTR clip_ptr;
    if(!IsClipboardFormatAvailable(CF_TEXT))
        return ret;
    if(!OpenClipboard(NULL))
        return ret;
    HGLOBAL lpMemory = GetClipboardData(CF_TEXT);
    if(!(clip_ptr = (LPTSTR)GlobalLock(lpMemory)))
        return ret;
    while(*clip_ptr)
        ret += *clip_ptr++;
    CloseClipboard();
    return ret;    
}