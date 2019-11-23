#include <bits/stdc++.h>

using namespace std;


// untest
bool judgeEqual(int list[], const int size)
{
	int cal = 0;

	for(int i = 0; i < size-1; i++)
	{
		if(list[i] == list[i + 1])
			cal++;
	}

	if(cal == size - 1)
		return true;
	else 
		return false;
}

#ifdef DBG
void print(int arr[], const int size)
{
	for(int i = 0; i < size && (~printf("%d ", arr[i])); i++);
}
#endif

int main()
{
	#ifdef DBG
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
	#endif
	int cases, cup;
	int total,i,j;
	scanf("%d", &cases);

	for(i=0;i<cases;i=i+1){
		scanf("%d",&cup);
		int list[cup],small= INT_MAX;
		total=0;
		for(j=0;j<cup;j=j+1){
			scanf("%d",&list[j]);
			if(list[j]<small){
				small=list[j];
			}
		}

		for(j=0;j<cup;j=j+1){
			total=total+list[j]-small;
		}

		printf("%d\n",total );

	}

	return 0;
}