#include <iostream>
#include <cinttypes>

using namespace std;

/*      UINT64_MAX 18446744073709551615ULL */
#define P10_UINT64 10000000000000000000ULL   /* 19 zeroes */
#define E10_UINT64 19

#define STRINGIZER(x)   # x
#define TO_STRING(x)    STRINGIZER(x)

#define UINT_128_MAX (((((__uint128_t)1 << 127)-1)<<1)+1)
#define UINT_128_MIN (__uint128_t)0

static int print_u128_u(__uint128_t u128)
{
    int rc;
    if (u128 > UINT64_MAX)
    {
        __uint128_t leading  = u128 / P10_UINT64;
        uint64_t  trailing = u128 % P10_UINT64;
        rc = print_u128_u(leading);
        rc += printf("%." TO_STRING(E10_UINT64) PRIu64, trailing);
    }
    else
    {
        uint64_t u64 = u128;
        rc = printf("%" PRIu64, u64);
    }
    return rc;
}

int main()
{
	// print_u128_u((__uint128_t)1 << 127);
	// putchar('\n');

	print_u128_u(UINT_128_MAX);
	putchar('\n');

	print_u128_u(UINT_128_MIN);
	putchar('\n');

	// for(__uint128_t i = UINT_128_MIN; i <= UINT_128_MAX; i++)
	{
		// print_u128_u(i);
		// putchar('\n');
	}

	return 0;
}