#pragma once
#include <windows.h>
#include <map>
#include "Helpers.h"


class ConsoleGUI
{
private:
    void setColor(Colors color);
    void resetColor();
    void setCursor(unsigned int x, unsigned int y);
public:
    //void SetFontSize(SHORT x, SHORT y);
    void drawBlock(unsigned int x, unsigned int y, unsigned int size, Colors color);
};