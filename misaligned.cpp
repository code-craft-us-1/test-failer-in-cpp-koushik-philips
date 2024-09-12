#include <assert.h>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

void printColorPair(const char* majorColorArr[], const char* minorColorArr[],
                   int i, int j, std::ostream& out) {
    out << i * 5 + j << " | " << majorColorArr[i] << " | " << minorColorArr[i] << "\n";
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

// Test
int testPrintColorMap(const char* majorColorArr[], const char* minorColorArr[]) {
    int retNumSucessTests = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            std::stringstream ss;
            printColorPair(majorColorArr, minorColorArr, i, j, ss);
            // Donot stop test at first failure.
            // Count sucessfull & unsucessfull tests
            auto str = std::to_string((i * 5 + j)) + " | " + std::string(majorColorArr[i]) +
                " | " + std::string(minorColorArr[j]);
            std::string inputStr;
            std::getline(ss, inputStr);
            if (str == inputStr) {
                std::cout << "Test Successfull for: " << "(" << i << "," << j << ")" << "\n";
                retNumSucessTests++;
            } else {
                std::cout << "Test FAILED for: " << "(" << i << "," << j << ")" << "\n";
            }
        }
    return retNumSucessTests;
}

int main() {
    const char* majorColor[] = { "White", "Red", "Black", "Yellow", "Violet" };
    const char* minorColor[] = { "Blue", "Orange", "Green", "Brown", "Slate" };
    int result = printColorMap(majorColor, minorColor);
    assert(result == 25);
    assert(testPrintColorMap(majorColor, minorColor) == 25);
    std::cout << "All is well (maybe!)\n";
    return 0;
}
