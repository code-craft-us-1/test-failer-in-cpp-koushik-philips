#include <assert.h>
#include <iostream>
#include "tshirts.h"

int main() {
    assert((size(38) == 'M') && (size(42) == 'L'));
    assert(size(37) == 'S');
    assert(size(40) == 'M');
    assert(size(43) == 'L');
    std::cout << "All is well (maybe!)\n";
    return 0;
}
