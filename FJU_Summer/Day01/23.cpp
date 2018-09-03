#include<cstdio>
#include "interactive/23.h"

int main()
{
	int n,in[3];
	GetN(n);  //n=3
	Get(in[0]);  //in[0]=3
	for(int i=1;i<n;i++)
	{
		Get(in[i]);  //in[1,2]=6,9
		Report(3);
	}
	Bye();
}
