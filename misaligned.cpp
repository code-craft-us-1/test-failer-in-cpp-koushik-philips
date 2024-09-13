#include <assert.h>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

void printColorPair(const char* majorColorArr[], const char* minorColorArr[],
    int i, int j, std::ostream& out) {
    out << i * 5 + j << " | " << majorColorArr[i] << " | " << minorColorArr[i] << "\n";
}

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printColorPair(majorColor, minorColor, i, j, std::cout);  // core part
        }
    }
    return i * j;
}

// Test - core part
int testPrintColorMap() {
    const char* majorColor[] = { "White", "Red", "Black", "Yellow", "Violet" };
    const char* minorColor[] = { "Blue", "Orange", "Green", "Brown", "Slate" };
    int retNumSucessTests = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            std::stringstream ss;
            printColorPair(majorColor, minorColor, i, j, ss);
            // Donot stop test at first failure.
            // Count sucessfull tests and return it
            auto str = std::to_string((i * 5 + j)) + " | " + std::string(majorColor[i]) +
                " | " + std::string(minorColor[j]);
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
    int result = printColorMap();
    assert(result == 25);
    assert(testPrintColorMap() == 25);
    std::cout << "All is well (maybe!)\n";
    return 0;
}
