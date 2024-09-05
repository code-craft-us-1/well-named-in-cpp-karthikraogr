#pragma once
#include <string>

namespace TelCoColorCoder
{
    enum MajorColor { WHITE, RED, BLACK, YELLOW, VIOLET, maxSizeMajorColor };
    enum MinorColor { BLUE, ORANGE, GREEN, BROWN, SLATE, maxSizeMinorColor };

    class ColorPair {
        MajorColor majorColor;
        MinorColor minorColor;
    public:
        ColorPair(MajorColor major, MinorColor minor);

        MajorColor getMajorColor() const; 

        MinorColor getMinorColor() const;

        std::string getColorPairInString() const;
    };

    ColorPair GetColorPairFromNumber(int pairNumber);
    int GetNumberFromColorPair(MajorColor major, MinorColor minor);
}
