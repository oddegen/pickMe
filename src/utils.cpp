#include <algorithm>
#include <cmath>
#include "_hook.h"


COLOR getPixelData(int x, int y, COLOR &c, COLORREF &pixel) {
    HDC hdc = GetDC(NULL);
    pixel = GetPixel(hdc, x, y);
    ReleaseDC(NULL, hdc);

    
    c.r = (BYTE)(pixel & rgbRed);
    c.g = (BYTE)(pixel & rgbGreen) >> 8;
    c.b = (BYTE)(pixel & rgbBlue) >> 16;

    return c;
}

void RGBtoHSL(BYTE red, BYTE green, BYTE blue, double& hue, double& saturation, double& lightness) {
    double r = red / 255.0;
    double g = green / 255.0;
    double b = blue / 255.0;
    
    double max = std::max(std::max(r, g), b);
    double min = std::min(std::min(r, g), b);
    double delta = max - min;

    if (delta == 0) {
        hue = 0;
    } else if (max == r) {
        hue = fmod((g - b) / delta, 6.0);
    } else if (max == g) {
        hue = (b - r) / delta + 2.0;
    } else if (max == b) {
        hue = (r - g) / delta + 4.0;
    }
    hue *= 60.0;

    lightness = (max + min) / 2.0;

    if (delta == 0) {
        saturation = 0;
    } else {
        saturation = delta / (1.0 - std::abs(2.0 * lightness - 1.0));
    }

}