#include "ColorPair.h"

const char* MajorColorNames[] = {
        "White", "Red", "Black", "Yellow", "Violet"
    };

     const char* MinorColorNames[] = {
        "Blue", "Orange", "Green", "Brown", "Slate"
    };

    int numberOfMajorColors =
        sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
   
    int numberOfMinorColors =
        sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

std::string TelCoColorCoder::ColorPair::ToString() {
                std::string colorPairStr = MajorColorNames[majorColor];
                colorPairStr += " ";
                colorPairStr += MinorColorNames[minorColor];
                return colorPairStr;
}

TelCoColorCoder::ColorPair TelCoColorCoder::GetColorFromPairNumber(int pairNumber) {
        int zeroBasedPairNumber = pairNumber - 1;
        TelCoColorCoder::MajorColor majorColor = 
            (TelCoColorCoder::MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
        TelCoColorCoder::MinorColor minorColor =
            (TelCoColorCoder::MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
        return TelCoColorCoder::ColorPair(majorColor, minorColor);
}

int TelCoColorCoder::GetPairNumberFromColor(TelCoColorCoder::MajorColor major, TelCoColorCoder::MinorColor minor) {
        return major * numberOfMinorColors + minor + 1;
}

std::string printRefManualData(){
        std::string message = "\n------Reference Manual-------\n";
        for(int pairNumber = 1; pairNumber <= 25; pairNumber++) {
            TelCoColorCoder::ColorPair colorPair =
                TelCoColorCoder::GetColorFromPairNumber(pairNumber);
            message += std::to_string(pairNumber);
            message += " ";
            message += colorPair.ToString();
            message += "\n";
        }
        return message;
}