#include <iostream>
#include <cstdio>

using namespace std;

// By SunTalk

int main(int argc, char const *argv[])
{
	#ifdef DEBUG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	int number,engrgy,x1,x2;

	scanf("%d %d %d %d",&number,&engrgy,&x1,&x2);

	int laser[number], i;

	for(i = 0; i < number; i++)
	{
		laser[i] = i;
	}

	for(i = number-1; i >= 0; i--)
	{
		if(engrgy >= laser[i])
		{
			engrgy = engrgy - laser[i];
		}
		else
		{
			laser[i] = 0;
		}
	}

	for(i = number-1; i >= 0; i--)
	{
		if(i==0)
			printf("%d\n",laser[i]+1 );
		else
			printf("%d ",laser[i]+1 );
	}

	return 0;
}