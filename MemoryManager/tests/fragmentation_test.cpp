#include <iostream>
#include <cstdlib>
#include "../lib/MemoryManager.h"

// Tests fragmentation: failure when free blocks are non-adjacent, success after coalescing.
int run_fragmentation_tests() {
    char buffer[64];
    MemoryManager mm(buffer, sizeof(buffer));

    // allocate four equal blocks filling the buffer
    std::cerr << "\n** Entering: run_fragmentation_tests\n";
    char* a = mm.Alloc(16);
    char* b = mm.Alloc(16);
    char* c = mm.Alloc(16);
    char* d = mm.Alloc(16);
    if (!a || !b || !c || !d) { std::cerr << "FAIL: initial allocs\n"; return EXIT_FAILURE; }

    // free two non-adjacent blocks -> fragmentation should prevent a 32-byte alloc
    mm.Free(b);
    mm.Free(d);
    char* x = mm.Alloc(32);
    if (x != nullptr) { std::cerr << "FAIL: Allocated 32 bytes despite fragmentation\n"; return EXIT_FAILURE; }

    // free the middle block to allow coalescing (b + c + d -> contiguous)
    mm.Free(c);
    char* y = mm.Alloc(32);
    if (y != b) { std::cerr << "FAIL: expected coalesced block at original b\n"; return EXIT_FAILURE; }

    // cleanup
    mm.Free(a);
    mm.Free(y);
    return EXIT_SUCCESS;
}