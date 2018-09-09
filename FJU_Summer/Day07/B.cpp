// #include <bits/stdc++.h>

#include <iostream>
#include <cmath>
#include <cstdint>
#include <cinttypes>

using namespace std;

#define TESTC ""
#define PROBLEM "B"

typedef unsigned __int128 uint128_t;

/*      UINT64_MAX 18446744073709551615ULL */
#define P10_UINT64 10000000000000000000ULL   /* 19 zeroes */
#define E10_UINT64 19

#define STRINGIZER(x)   # x
#define TO_STRING(x)    STRINGIZER(x)

static int print_u128_u(uint128_t u128)
{
    int rc;
    if (u128 > UINT64_MAX)
    {
        uint128_t leading  = u128 / P10_UINT64;
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

inline uint128_t getPair(const uint128_t m)
{
	return (m + (uint128_t)1) * m + (uint128_t)1;
}

// uint64_t getPair(const int m)
// {
// 	uint64_t a = m;
// 	return (a+(uint64_t)1) * a + (uint64_t)1;
// }

int main()
{
	#ifdef DBG
	freopen(PROBLEM ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif
	int cases;

	scanf("%d", &cases);

	int64_t i, j;

	while(cases-- && scanf("%lld %lld", &i, &j) != EOF)
	{
		i--, j--;
		// printf("%d %d\n", i, j);
		int64_t maxIJ = max(i, j);
		// printf("%lld\n", maxIJ);

		uint128_t vert = getPair(max(i, j));
		// printf("%llu\n", vert);

		uint128_t dif = i - j >= 0 ? i - j : j - i;

		bool flag;
		if(i > j)
			flag = false;
		else if(i < j)
			flag = true;
		else
		{
			print_u128_u(vert);
			putchar('\n');
			continue;
		}

		if(maxIJ != 0)
		{
			// odd
			if(maxIJ % 2 != 0)
			{
				// i < j up
				if(flag)
				{
					vert -= dif;
				}
				// i > j left
				else
				{
					vert += dif;
				}
			}
			// even
			else
			{
				// i < j up
				if(flag)
				{
					vert += dif;
				}
				// i > j left
				else
				{
					vert -= dif;
				}
			}
		}

		// printf("i=%d j=%d: ", i, j);
		// printf("%llu\n", vert);
		print_u128_u(vert);
		putchar('\n');
		// print_u128_u(vert);
	}

	return 0;
}