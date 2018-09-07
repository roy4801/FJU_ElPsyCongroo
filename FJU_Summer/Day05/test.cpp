#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main2()
{
    char test[255 << 20];
    memset(test, 42, sizeof(test));
    printf(":)\n");
    return 0;
}

int main() {
    int size = 256 << 20;  // 256Mb
    char *p = (char*)malloc(size) + size;
    asm("movl  %0, %%esp\n"
        // "pushl $exit\n"    // if you get a compile error here under mingw/cygwin, 
        "jmp   main2\n"    // replace exit with _exit, and main2 with _main2.
        :: "r"(p));
}