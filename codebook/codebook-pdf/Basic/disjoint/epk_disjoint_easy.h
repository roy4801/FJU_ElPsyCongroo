#define SIZE 1000005
int p[SIZE];

void init()
{
	for(int i = 0; i < SIZE; i++)
		p[i] = i;
}

int find(const int x)
{
	return x==p[x] ? (p[x] = find(p[x]));
}

void uni(const int a, const int b)
{
	p[find(a)] = p[find(b)];
}

bool equ(const int a, const int b)
{
	return find(a) == find(b);
}