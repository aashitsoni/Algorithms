#include <iostream>
#include <cstdlib>
#include "../lib/MemoryManager.h"

int run_basic_test() {
    char buffer[64];
    MemoryManager mm(buffer, sizeof(buffer));

    // basic adjacent allocation
    std::cerr << "\n** Entering: run_basic_test\n";
    char* a = mm.Alloc(10);
    if (!a) { std::cerr << "FAIL: Alloc a\n"; return EXIT_FAILURE; }

    char* b = mm.Alloc(10);
    if (!b) { std::cerr << "FAIL: Alloc b\n"; return EXIT_FAILURE; }
    if (b != a + 10) { std::cerr << "FAIL: b is not adjacent to a\n"; return EXIT_FAILURE; }

    // free tail block and ensure reuse of freed tail
    mm.Free(b);
    char* c = mm.Alloc(10);
    if (c != b) { std::cerr << "FAIL: freed tail block was not reused\n"; return EXIT_FAILURE; }

    // free remaining and ensure full-buffer allocation is possible
    mm.Free(a);
    mm.Free(c);
    char* big = mm.Alloc(sizeof(buffer));
    if (!big) { std::cerr << "FAIL: full-buffer allocation failed after frees\n"; return EXIT_FAILURE; }

    mm.Free(big);
    return EXIT_SUCCESS;
}