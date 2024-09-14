#include <assert.h>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <tuple>

int printColorMap(std::ostream& out) {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            out << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }
    return i * j;
}

// Test - core part
std::tuple<int, int, int, int> testPrintColorMap() {
    std::stringstream ss;
    int result = printColorMap(ss);
    // test
    const char* majorColor[] = { "White", "Red", "Black", "Yellow", "Violet" };
    const char* minorColor[] = { "Blue", "Orange", "Green", "Brown", "Slate" };
    int nCntNumMatch = 0, nCntMajorMatch = 0, nCntMinorMatch = 0, nCntFullMatch = 0;
    std::string inputStr;
    int i = 0, j = 0;
    while (std::getline(ss, inputStr, '\n')) {
        std::string numStr,  majorStr, minorStr, partitionStr;
        std::stringstream inputSS(inputStr);
        inputSS >> numStr >> partitionStr >> majorStr >> partitionStr >> minorStr;
        auto expectedNumStr = std::to_string(i * 5 + j);
        auto expectedMajorStr = majorColor[i];
        auto expectedMinorStr = minorColor[j];
        if (expectedNumStr == numStr) {
            nCntNumMatch++;
        }
        if (expectedMajorStr == majorStr) {
            nCntMajorMatch++;
        }
        if (expectedMinorStr == minorStr) {
            nCntMinorMatch++;
        }
        std::string expectedStr = expectedNumStr + " | " + expectedMajorStr
                                  + " | " + expectedMinorStr;
        if (expectedStr == inputStr) {
            nCntFullMatch++;
        }
        j++;
        if (j == 5) {
            j = 0;
            i++;
        }
    }
    return std::make_tuple(nCntNumMatch, nCntMajorMatch, nCntMinorMatch, nCntFullMatch);
}

int main() {
    int result = printColorMap(std::cout);
    assert(result == 25);
    auto [num, major, minor, full] = testPrintColorMap();
    assert(num == 25);      // Number match
    assert(major == 25);    // Major-colors match
    assert(minor == 25);    // Minor-colors match
    assert(full == 25);     // Full match
    std::cout << "All is well (maybe!)\n";
    return 0;
}
