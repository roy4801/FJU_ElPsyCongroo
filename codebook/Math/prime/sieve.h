#define N 100000
bool pr[N+5];
void buildPr()
{
	pr[0] = pr[1] = false;
	for(LL i = 2; i <= N; i++)
		pr[i] = true;

	for(LL i = 2; i <= N; i++)
		if(pr[i])
			for(LL a = i*i; a <= N; a += i)
				pr[a] = false;
}
