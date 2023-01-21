#pragma once
#include <windows.h>
#include <map>

enum Colors
{
    Green, Aqua, Red, Purple, Yellow, White
};


class ConsoleTools
{
private:
    void SetColor(Colors color);
    void ResetColor();
    void SetCursor(UINT x, UINT y);
public:
    //void SetFontSize(SHORT x, SHORT y);
    void DrawBlock(UINT x, UINT y, UINT size, Colors color);
};