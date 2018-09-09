/*
 * __int128 print and scan function implmentation
 * Author: roy4801
 * Team: FJU_ElPsyCongroo
 * ver 0.0.1
 */
#include <iostream>
#include <assert.h>

/*
 * int print_i128(_int128 i128)
 * Description: Print a __int128 to stdout
 */
static int print_i128(__int128 i128)
{
    char ch128[40], *now = ch128, *head = ch128;

    if(i128 < 0)
    {
        putchar('-');
        i128 = -i128;
    }
    // Turn __int28 into char[] from lowest digit
    while(i128 > 9)
    {
        *now++ = i128 % 10 + '0';
        i128 /= 10;
    }
    *now++ = i128 + '0';
    *now = '\0';
    now--;
    // Reverse
    while(head <= now)
    {
        std::swap(*head++, *now--);
    }

    return printf("%s", ch128);
}
/*
 * int scan_i128(__int128 *n)
 * Description: Reads a __int128 to the passed in __int128 *
 */
static int scan_i128(__int128 *n)
{
    #ifdef DBG
    assert(n != NULL);
    #endif
    char num[40], *now = num;
    bool minus = false;
    *n = 0; // reset n

    int ret = scanf("%s", num);
    if(ret == EOF) // scanf fails
        return EOF;
    // Judge if minus
    if(*now == '-')
    {
        minus = true;
        now++; // skip '-'
    }

    // Add the digit and multiply it by 10 one after another
    while(*now)
    {
        *n += *now - '0';
        now++;
        if(*now) // check if now touches '\0'
            *n *= 10;
    }

    *n = minus ? -(*n) : *n;

    return 1;
}