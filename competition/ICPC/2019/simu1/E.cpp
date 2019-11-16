#include <bits/stdc++.h>

using namespace std;

#define PROBLEM ""
#define TESTC ""

#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> P;
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back

#define MAXN 100000
#define DEV 0.00000005

bool vis[MAXN+10];
long long table[MAXN+10];
int keyy[MAXN*3+10][2];
int n,m;
long long ans;

void backtracking(int k,long long now){

	ans = max(ans,now);
	// printf("ans:%d\n",ans );
	if( k == m ){
		// printf("---\n");
		return;
	}

	bool check = true;
	if( !vis[keyy[k][0]] ){
		// printf("%d:0\n", k );
		vis[keyy[k][0]] = true;
		backtracking(k+1,now+table[keyy[k][0]]);
		vis[keyy[k][0]] = false;
		check = false;
	}
	if( !vis[keyy[k][1]] ){
		// printf("%d:1\n", k );
		vis[keyy[k][1]] = true;
		backtracking(k+1,now+table[keyy[k][1]]);
		vis[keyy[k][1]] = false;
		check = false;
	}
	if( check ) backtracking(k+1,now);
}

int main()
{

	

	while( ~scanf("%d %d",&n,&m) ){

		memset(vis,0,sizeof(vis));
		for(int i = 1 ; i <= n ; i++ )
			scanf("%lld",&table[i]);
		for(int i = 0 ; i < m ; i++ )
			scanf("%d %d",&keyy[i][0],&keyy[i][1]);

		ans = 0;
		backtracking(0,0);
		printf("%lld\n", ans);


	}



	return 0;
}