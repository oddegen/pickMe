#include "_hook.h"
#include "curses.h"
#include <iostream>
#include <iomanip>

// Color constants.
double hue, saturation, lightness;
PONT p; COLOR c;
COLORREF pixel;
bool colONSCREEN = false;

// LRESULT CALLBACK MouseProc(
//   _In_ int    nCode,
//   _In_ WPARAM wParam,
//   _In_ LPARAM lParam
// );

LRESULT CALLBACK lMouseProc(int nCode, WPARAM wParam, LPARAM lParam) {

    if(nCode < 0) {
        return CallNextHookEx(NULL, nCode, wParam, lParam);
    }

    if(nCode == HC_ACTION) {
        if(wParam == WM_LBUTTONDOWN) {            
            
            MSLLHOOKSTRUCT* mouseHookStruct = reinterpret_cast<MSLLHOOKSTRUCT*>(lParam);

            p.x = mouseHookStruct->pt.x;
            p.y = mouseHookStruct->pt.y;

            c = getPixelData(p.x, p.y, c, pixel);

            RGBtoHSL(c.r, c.g, c.b, hue, saturation, lightness);

            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, pixel);

            
            if (colONSCREEN) {
                //Clear
                std::cout << "\n";

            }

            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 10; ++j) {
                    std::cout << " ";
                }
                if (i != 5) {
                    std::cout << "\n";
                }
            }

            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            // Display the color values in RGB, hexadecimal, and HSL formats
            std::cout << "RGB: " << std::setw(3) << (int)c.r << " " << std::setw(3) << (int)c.g << " " << std::setw(3) << (int)c.b << " | ";
            std::cout << "hex: " << std::hex << std::setw(2) << std::setfill('0') << (int)c.r << std::setw(2) << (int)c.g << std::setw(2) << (int)c.b << " | ";
            std::cout << "HSL: " << std::fixed << std::setprecision(0) << std::setw(3) << hue << " " << std::setw(3) << saturation * 100 << "% " << std::setw(3) << lightness * 100 << "%" << std::endl;


            colONSCREEN = true;
        }
    }

    return CallNextHookEx(NULL, nCode, wParam, lParam);
}


HHOOK SetMouseHook()
{
    return SetWindowsHookEx(WH_MOUSE_LL, lMouseProc, GetModuleHandle(NULL), 0);
}

void UnsetMouseHook(HHOOK hook)
{
    UnhookWindowsHookEx(hook);
}