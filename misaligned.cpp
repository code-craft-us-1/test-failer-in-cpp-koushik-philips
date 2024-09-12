#include <assert.h>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

void printColorPair(const char* majorColorArr[], const char* minorColorArr[], 
                   int i, int j, std::ostream& out){
    out << i * 5 + j << " | " << majorColorArr[i] << " | " << minorColorArr[i] << "\n";
}

void testPrintColorPair(const char* majorColorArr[], const char* minorColorArr[], 
                        int i, int j){
    std::stringstream ss;
    printColorPair(majorColorArr, minorColorArr, i, j, ss);
    // tests
    std::string str;
    std::getline(ss, str, '|');
    assert((i * 5 + j) == std::stoi(str));
    std::getline(ss, str, '|');
    str.erase(std::remove_if(str.begin(), str.end(), std::isspace), std::end(str));
    assert(majorColorArr[i] == str);
    std::getline(ss, str, '|');
    str.erase(std::remove_if(str.begin(), str.end(), std::isspace), std::end(str));
    assert(minorColorArr[j] == str);
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
