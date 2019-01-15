// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <cstring>

// AC by roy4801

using namespace std;

#define PROBLEM "B"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

int n;
stack<int> s;
int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif
	int num = 0;
	char c;
	cin >> n;
	cin.ignore();
	while(n--)
	{

		while(true)
		{
			c = getchar();
			if(isdigit(c))
			{
				num *= 10;
				num += c - '0';
			}
			else if(c == ' ')
			{
				s.push(num);
				num = 0;
			}
			else
			{
				if(!s.empty())
				{
					int b = s.top();
					s.pop();
					int a = s.top();
					s.pop();
					// printf("a=%d %c b=%d\n", a, c, b);
					switch(c)
					{
						case '+':
							s.push(a+b);
						break;
						case '-':
							s.push(a-b);
						break;
						case '*':
							s.push(a*b);
						break;
						case '/':
							s.push(a/b);
						break;
					}
					c = getchar();
					if(c == '\n' || c == EOF)
						break;
				}
			}
		}
		// cout << s.size() << '\n';
		cout << s.top() << '\n';
		s.pop();
	}
	return 0;
}
