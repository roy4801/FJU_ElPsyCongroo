#include <iostream>

using namespace std;

#define BT_SIZE 21

bool bt[BT_SIZE][BT_SIZE] = {false};

void connect(const int a, const int b)
{
	bt[a][b] = true;
}

void input(const int p)
{
	int l, r;

	scanf("%d", &l);

	if(l)
	{
		connect(p, l);
		input(l);
	}

	scanf("%d", &r);

	if(r)
	{
		connect(p, r);
		input(r);
	}
}

// global variables for storing states
bool first = true, found = false;;
void dfs(const int p, int sum, const int search)
{
	first = true;
	sum += p;

	// printf("%d\n", p);
	
	for(int i = 0; i < BT_SIZE; i++)
	{
		if(bt[p][i])
		{
			// Keep recursive searching through until it touchs a leaf;
			// then, it will jump out this for loop
			dfs(i, sum, search);
		}
	}

	// Only judge the first touching of leaf, ignoring the others
	if(first)
	{
		// printf("sum%d\n ", sum);
		if(sum == search)
			found = true;

		first = false;
	}
	
	// printf("---END--\n");
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	#endif
	int cases;

	scanf("%d", &cases);

	while(cases--)
	{
		int root, search;
		scanf("%d", &root);
		input(root);

		scanf("%d", &search);
		dfs(root, 0, search);

		if(found)
		{
			printf("True\n");
			found = false;
		}
		else
		{
			printf("False\n");
		}
	}

	return 0;
}