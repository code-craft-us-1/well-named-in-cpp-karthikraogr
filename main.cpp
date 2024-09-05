#include <iostream>
#include <cassert>
#include "ColorPair.h"

void testNumberToPair(const int pairNumber,
                      const TelCoColorCoder::MajorColor expectedMajor,
                      const TelCoColorCoder::MinorColor expectedMinor)
{
    const TelCoColorCoder::ColorPair colorPair = TelCoColorCoder::GetColorPairFromNumber(pairNumber);
    std::cout << "Got pair " << colorPair.getColorPairInString() << std::endl;
    assert(colorPair.getMajorColor() == expectedMajor);
    assert(colorPair.getMinorColor() == expectedMinor);
}

void testPairToNumber(
    const TelCoColorCoder::MajorColor major,
    const TelCoColorCoder::MinorColor minor,
    const int expectedPairNumber)
{
    const int pairNumber = GetNumberFromColorPair(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}

std::string printRefManualData(){
	//print reference manual for wiring personnel
        std::string message = "Color Coding Manual\n";
        for(int pairNumber = 1; pairNumber <= 25; pairNumber++) {
            TelCoColorCoder::ColorPair colorPair =
                TelCoColorCoder::GetColorPairFromNumber(pairNumber);
            message += std::to_string(pairNumber);
            message += " ";
            message += colorPair.getString();
            message += "\n";
        }
        return message;
}


int main() {
    testNumberToPair(4, TelCoColorCoder::MajorColor::WHITE, TelCoColorCoder::MinorColor::BROWN);
    testNumberToPair(5, TelCoColorCoder::MajorColor::WHITE, TelCoColorCoder::MinorColor::SLATE);

    testPairToNumber(TelCoColorCoder::MajorColor::BLACK, TelCoColorCoder::MinorColor::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::MajorColor::VIOLET, TelCoColorCoder::MinorColor::SLATE, 25);
    std::cout<<printRefManualData();
    return 0;
}
