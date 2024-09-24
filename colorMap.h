#pragma once
#include <iostream>

int printColorMap(std::ostream& out) {
    const char* majorColor[] = { "White", "Red", "Black", "Yellow", "Violet" };
    const char* minorColor[] = { "Blue", "Orange", "Green", "Brown", "Slate" };
    int i = 0, j = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            out << (i * 5 + j) + 1 << " | " << majorColor[i] << " | " << minorColor[j] << "\n";
        }
    }
    return i * j;
}