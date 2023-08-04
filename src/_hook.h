#ifndef _HOOK_H
#define _HOOK_H

#include <windows.h>

#define rgbRed 0x000000FF
#define rgbGreen 0x0000FF00
#define rgbBlue 0x00FF0000


struct PONT {
    int x{};
    int y{};
};

struct COLOR {
    BYTE r;
    BYTE g;
    BYTE b;
};

COLOR getPixelData(int x, int y, COLOR &c, COLORREF &pixel);
void RGBtoHSL(BYTE red, BYTE green, BYTE blue, double& hue, double& saturation, double& lightness);

LRESULT CALLBACK lMouseProc(int nCode, WPARAM wParam, LPARAM lParam);
HHOOK SetMouseHook();
void UnsetMouseHook(HHOOK hook);

#endif