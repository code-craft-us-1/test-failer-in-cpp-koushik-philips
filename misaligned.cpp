#include <assert.h>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <tuple>
#include "colorMap.h"

struct ResultData {
    int nCntNumMatch = 0;
    int nCntMajorMatch = 0;
    int nCntMinorMatch = 0;
    int nCntFullMatch = 0;
};

// Test
ResultData testPrintColorMap() {
    std::stringstream ss;
    printColorMap(ss);
    // test
    const char* majorColor[] = { "White", "Red", "Black", "Yellow", "Violet" };
    const char* minorColor[] = { "Blue", "Orange", "Green", "Brown", "Slate" };
    ResultData testResult;
    std::string inputStr;
    int majorClrIdx = 0, minorClrIdx = 0;
    while (std::getline(ss, inputStr, '\n')) {
        std::string numStr,  majorStr, minorStr, partitionStr;
        std::stringstream inputSS(inputStr);
        inputSS >> numStr >> partitionStr >> majorStr >> partitionStr >> minorStr;
        auto expectedNumStr = std::to_string((majorClrIdx * 5 + minorClrIdx)+1);
        auto expectedMajorStr = majorColor[majorClrIdx];
        auto expectedMinorStr = minorColor[minorClrIdx];
        if (expectedNumStr == numStr) {
            testResult.nCntNumMatch++;
        }
        if (expectedMajorStr == majorStr) {
            testResult.nCntMajorMatch++;
        }
        if (expectedMinorStr == minorStr) {
            testResult.nCntMinorMatch++;
        }
        std::string expectedStr = expectedNumStr + " | " + expectedMajorStr
                                  + " | " + expectedMinorStr;
        if (expectedStr == inputStr) {
            testResult.nCntFullMatch++;
        }
        minorClrIdx++;
        if (minorClrIdx == 5) {
            minorClrIdx = 0;
            majorClrIdx++;
        }
    }
    return testResult;
}

int main() {
    int result = printColorMap(std::cout);          // Production code. Can be called separately
    assert(result == 25);                           // Test code.
    ResultData testResult = testPrintColorMap();    // Test code.
    assert(testResult.nCntNumMatch == 25);          // Number match
    assert(testResult.nCntMajorMatch == 25);        // Major-colors match
    assert(testResult.nCntMinorMatch == 25);        // Minor-colors match
    assert(testResult.nCntFullMatch == 25);         // Full match
    std::cout << "All is well (maybe!)\n";
    return 0;
}
