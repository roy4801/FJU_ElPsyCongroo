#include <bits/stdc++.h>

using namespace std;

#define TESTC ""
#define PROBLEM "C"

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)

// bool alphbat(string one, string two){
// 	int i=0;
// 	while( one[i] == two[i] )
// 		i++;
// 	if(one[i]>two[i])
// 		return 1;
// 	else
// 		return 0;
// }


int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int number,i,j;
	scanf("%d",&number);
	string price;
	vector <string> output;
	bool check;

	for( i = 0 ; i < number ; i++ ){
		cin >> price;
		output.push_back(price);
	}

	// for( i = 1 ; i < output.size() ; i++ ){
	// 	int j = i;
	// 	while( alphbat(output[j-1],output[j]) && j != -1 ){
	// 		swap(output[j],output[j-1]);
	// 		j--;
	// 	}
	// }
	sort(output.begin(), output.end());

	int times;
	for( i = 0 ; i < output.size() ; i++ ){
		times = 1;
		cout << output[i];
		while( output[i+1] == output[i] ){
			i++;
			times++;
		}
		printf(" %d\n", times );
	}

	return 0;
}