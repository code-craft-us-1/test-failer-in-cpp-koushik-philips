#include <assert.h>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <regex>

int printColorMap(std::ostream& out) {
    const char* majorColor[] = { "White", "Red", "Black", "Yellow", "Violet" };
    const char* minorColor[] = { "Blue", "Orange", "Green", "Brown", "Slate" };
    int i = 0, j = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            out << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[j] << "\n";
        }
    }
    return i * j;
}

int testPrintColorMap()
{
    std::stringstream ss;
    int result = printColorMap(ss);

    int nNumEntriesInPrint = 0;
    const char* majorColor[] = { "White", "Red", "Black", "Yellow", "Violet" };
    const char* minorColor[] = { "Blue", "Orange", "Green", "Brown", "Slate" };
    std::string inputStr;
    int nMajorIdx = 0, nMinorIdx = 0;
    while (std::getline(ss, inputStr, '\n'))
    {
        std::regex r("(^[0-9]+ )[|] ([a-zA-Z]+) [|] ([a-zA-Z]+)$");
        std::smatch s;
        assert(std::regex_search(inputStr, s, r));                  // Alignment of "|" check
        {
            assert((nMajorIdx * 5 + nMinorIdx) == std::stoi(s[1])); // Number check
            assert(majorColor[nMajorIdx] == s[2]);                  // MajorColor check
            assert(minorColor[nMinorIdx] == s[3]);                  // MinorColor check
            nMinorIdx++;
            if (nMinorIdx == 5) {
                nMinorIdx = 0;
                nMajorIdx++;
            }
        }
        nNumEntriesInPrint++;
    }
    return nNumEntriesInPrint;
}

int main() {
    int result = printColorMap(std::cout);
    assert(result == 25);
    assert(testPrintColorMap() == 25);
    std::cout << "All is well (maybe!)\n";
    return 0;
}
