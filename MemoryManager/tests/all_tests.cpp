#include <iostream>
#include <cstdlib>

int run_basic_test();
int run_fragmentation_tests();
int run_frag_char_tests();

int main() {
    if (run_basic_test() != EXIT_SUCCESS) return EXIT_FAILURE;
    if (run_fragmentation_tests() != EXIT_SUCCESS) return EXIT_FAILURE;
    if (run_frag_char_tests() != EXIT_SUCCESS) return EXIT_FAILURE;
    std::cout << "All tests passed\n";
    return EXIT_SUCCESS;
}