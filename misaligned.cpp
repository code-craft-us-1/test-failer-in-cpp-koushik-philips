#include <assert.h>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

void printColorPair(const char* majorColorArr[], const char* minorColorArr[],
                   int i, int j, std::ostream& out) {
    out << i * 5 + j << " | " << majorColorArr[i] << " | " << minorColorArr[i] << "\n";
}

void testPrintColorPair(const char* majorColorArr[], const char* minorColorArr[],
                        int i, int j) {
    std::stringstream ss;
    printColorPair(majorColorArr, minorColorArr, i, j, ss);
    // test
    auto str = std::to_string((i * 5 + j)) + " | " + std::string(majorColorArr[i]) +
                              " | " + std::string(minorColorArr[j]);
    std::string inputStr;
    std::getline(ss, inputStr);
    assert(str == inputStr);
}

int printColorMap(const char** majorColorArr, const char** minorColorArr) {
    int i = 0, j = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printColorPair(majorColorArr, minorColorArr, i, j, std::cout);
        }
    }
    return i * j;
}

int main() {
    const char* majorColor[] = { "White", "Red", "Black", "Yellow", "Violet" };
    const char* minorColor[] = { "Blue", "Orange", "Green", "Brown", "Slate" };
    int result = printColorMap(majorColor, minorColor);
    testPrintColorPair(majorColor, minorColor, 1, 2);
    assert(result == 25);
    std::cout << "All is well (maybe!)\n";
    return 0;
}
