#include <bits/stdc++.h>

// by roy4801 (QQ)

using namespace std;

#define TESTC ""
#define PROBLEM "B_r"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif
    USE_CPPIO();

    string a, b;
    int n;

    cin >> n;
    while(n-- && cin >> a >> b)
    {
        int maxLen = 0;

        for(int len = a.length(); len >= 1; len--)
        {
            for(int i = 0; i <= a.length()-len; i++) // a start
            {
                for(int j = 0; j <= b.length()-len; j++) // b start
                {
                    string asub = a.substr(i, len), bsub = b.substr(j, len);
                    // is substring
                    if(asub == bsub)
                    {
                        maxLen = max(maxLen, (int)asub.length());
                    }
                }
            }
        }
        
        cout << maxLen << '\n';
    }

	return 0;
}