/*
 * Author: SunTalk
 * WA WTF
 */
#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <utility>

using namespace std;

#define PROBLEM "G"
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

int main()
{
	#ifdef DBG
	freopen(PROBLEM TESTC ".in", "r", stdin);
	freopen(PROBLEM ".out", "w", stdout);
	#endif

	int times;
	scanf("%d",&times);
	string pattern;
	int num,i,j;
	vector <string> find;
	vector < pair<int,int> > sequence;
	vector < int > count;
	vector < int > tmp_count;

	while( times-- ){

		find.clear();
		sequence.clear();
		count.clear();
		tmp_count.clear();

		cin >> pattern;
		scanf("%d",&num);
		int tmp = 0;
		string tmp_ans = "";

		for( i = 0 ; i < pattern.size() ; i++ ){
			if( pattern[i] == '[' ){

				vector <char> tmp_find;
				i++;
				while( pattern[i] != ']' ){
					tmp_find.push_back( pattern[i] );
					i++;
				}
				sort(tmp_find.begin(),tmp_find.end());

				find.push_back("");
				tmp = find.size()-1;
				for( j = 0 ; j < tmp_find.size() ; j++ ){
					find[tmp] = find[tmp] + tmp_find[j];
				}
				pair<int ,int> fuck;
				fuck.first = tmp;
				fuck.second = tmp_ans.size();
				sequence.push_back(fuck);
				tmp_ans = tmp_ans + '%';
			}
			else if( pattern[i] == '*' ){
				find.push_back("aeiou");
				tmp = find.size()-1;
				pair<int ,int> fuck;
				fuck.first = tmp;
				fuck.second = tmp_ans.size();
				sequence.push_back(fuck);
				tmp_ans = tmp_ans + '%' ;
			}
			else
				tmp_ans = tmp_ans + pattern[i];

		}

		
		// printf("\n");
		// for( i = 0 ; i < sequence.size() ; i++ ){
		// 	printf("%d\n",sequence[i].second );
		// 	cout << find[sequence[i].first] << endl;
		// }
		// printf("\n");
		// cout << tmp_ans << endl;
		// printf("-------------------------------------\n");
		

		string ans = tmp_ans;

		for( i = sequence.size()-1 ; i >= 0  ; i-- ){
			tmp = find[sequence[i].first].size();
			count.push_back(tmp);
			tmp_count.push_back(0);
		}

		bool check = true;

		i = 0;
		tmp = num-1;
		while( tmp >= 0 ){
			if( i == count.size() ){
				break;
	 		}
			tmp_count[i] = tmp % count[i];
			tmp = tmp/count[i];
			i++;
		}

		if( tmp > 0 ){
			printf("*\n");
			continue;
		}


		for( i = 0 ; i < count.size() ; i++ ){
			j = count.size()-1 - i;
			ans[sequence[j].second] = find[sequence[j].first][tmp_count[i]];
		}

		cout << ans << endl;

	}

	// int test[3] = {0,0,0};
	// char fuck[5] = {'a','e','i','o','u'};
	// int tmp = 0;
	// while( tmp != 100 ){

	// 	for(i=2;i>=0;i--)
	// 		printf("%c",fuck[test[i]] );
	// 	printf("\n");
	// 	tmp++;
	// 	i = 0;
	// 	test[i]++;
	// 	while( test[i] == 5 ){
	// 		test[i] = 0;
	// 		i++;
	// 		test[i]++;
	// 	}
	// }


	return 0;
}