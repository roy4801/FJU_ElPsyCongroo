#include <iostream>

using namespace std;

int f[105] = {0};;

void factor()
{
	// int d = 0;
	int sum = 1;

	// bool f2 = false, f5 = false;
	
	for(int i = 1; i <= 100; i++)
	{
		sum *= i;

		int tmp = sum, d = 0;
		while(tmp % 10 == 0)
		{
			d++;
		}
		f[i] = d;
		// sum *= i;

		// if(sum % 10 == 0)
		// {
		// 	sum /= 10;
		// 	sum %= 10;
		// }
		// printf("%d\n", sum);

		// if(i % 2 == 0)
		// {
		// 	if(sum && sum % 5 == 0)
		// 		d++;
		// 	f2 = true;
		// }
		// if(i % 5 == 0)
		// {
		// 	if(sum && sum % 2 == 0)
		// 		d++;
		// 	f5 = true;
		// }

		// if(f2 && f5)
		// {
		// 	f2 = f5 = false;
		// 	d += 1;
		// }
		// else
		// 	d = 0;
		// f[i] = f[i-1] + d;
	}
}

int main()
{
	factor();
	int n;

	// scanf("%d", &n);

	// for(int i = 1; i <= 100; i ++)
	// 	printf("%d: %d \n", i, f[i]);

	return 0;
}
