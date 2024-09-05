#include <iostream>
#include <assert.h>
#pragma once

namespace TelCoColorCoder
{
    enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
    enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};

    
    class ColorPair {
        private:
            MajorColor majorColor;
            MinorColor minorColor;
        public:
            ColorPair(MajorColor major, MinorColor minor):
                majorColor(major), minorColor(minor)
            {}
            MajorColor getMajor() {
                return majorColor;
            }
            MinorColor getMinor() {
                return minorColor;
            }
            std::string ToString();
    };
    ColorPair GetColorFromPairNumber(int );
    int GetPairNumberFromColor(MajorColor , MinorColor );
}

void testNumberToPair(int ,TelCoColorCoder::MajorColor ,TelCoColorCoder::MinorColor );
void testPairToNumber(TelCoColorCoder::MajorColor ,TelCoColorCoder::MinorColor ,int );
std::string printRefManualData();