/*
 * __int128 print and scan function test
 * Author: roy4801
 * Team: FJU_ElPsyCongroo
 * ver 0.0.1
 */
#include "int128.h"

using namespace std;

/*
 * Compiling:
 * g++ -DDBG int128.cpp
 * Testing:
 * diff ./int128.out ./int128_cor.out
 */

// TODO: Maybe turn __int128 into a macro like int128_t?

int main() {
    #ifdef DBG
    freopen("./int128.in", "r", stdin);
    freopen("./int128.out", "w", stdout);
    #endif
    __int128 a, b = 0;

    while(scan_i128(&a) != EOF && scan_i128(&b) != EOF)
    {
        // print_i128(a);
        // putchar('\n');
        // print_i128(b);
        // putchar('\n');

        print_i128(a + b);
        putchar('\n');
    }

    // print_i128(a + b);
    // putchar('\n');

    return 0;
}