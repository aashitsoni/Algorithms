#include <iostream>
#include <cstdlib>
#include "../lib/MemoryManager.h"

// Tests fragmentation: failure when free blocks are non-adjacent, success after coalescing.
// a similar test that is requested in actual problem - using very similar format from the fragmentation test - but with smaller blocks

int run_frag_char_tests() {
    char buffer[6];
    MemoryManager mm(buffer, sizeof(buffer));

    // allocate four equal blocks filling the buffer
    std::cerr << "\n** Entering: run_frag_char_tests\n";
    char* a = mm.Alloc(1);
    char* b = mm.Alloc(1);
    char* c = mm.Alloc(1);
    char* d = mm.Alloc(1);
    char* e = mm.Alloc(1);
    char* f = mm.Alloc(1);
    if (!a || !b || !c || !d || !e || !f) { std::cerr << "FAIL: initial allocs\n"; return EXIT_FAILURE; }

    // free two non-adjacent blocks -> fragmentation should prevent a 32-byte alloc
    mm.Free(b);
    mm.Free(d);
    char* x = mm.Alloc(2);
    if (x != nullptr) { std::cerr << "FAIL: Allocated 2 bytes despite fragmentation\n"; return EXIT_FAILURE; }

    // free the middle block to allow coalescing (b + c + d -> contiguous)
    mm.Free(c);
    char* y = mm.Alloc(3);
    if (y != b) { std::cerr << "FAIL: expected coalesced block at original b\n"; return EXIT_FAILURE; }

    // cleanup
    mm.Free(a);
    mm.Free(y);
    return EXIT_SUCCESS;
}