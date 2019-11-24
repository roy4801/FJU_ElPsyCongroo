#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> P;
typedef long long int LL;
typedef unsigned long long ULL;
typedef pair<LL,LL> PLL;
#define USE_CPPIO() ios_base::sync_with_stdio(0); cin.tie(0)
#define PB push_back
#define F first
#define S second
#define INF 0x3f3f3f3f
#define MP make_pair
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#define MAXN 1000000
#define N 65536

bitset <1000> mac[20];
bitset <1000> now;
int main()
{
    
    int kase;
    scanf("%d",&kase);
    int m,n;

    while(kase--){
        
        scanf("%d %d\n",&n,&m);
        //cout << m << " " << n << endl;
        for(int i = 0 ; i < 20 ; i++ )
            mac[i].reset();
        for(int i = 0 ; i < m ; i++ ){
            cin >> mac[i];
           // cout << mac[i] <<endl;
        }
        
        int ans = 50;
        for(int i = 1 ; i < pow(2,m+1) ; i++ ){
            bitset <20> b(i);
            now.reset();
            for(int j = 0 ; j < m ; j++){
                if( b[j] == 1 ){
                    now = now|mac[j];      
                }
            }
            if( now.count() == n && b.count() < ans ){
                ans = b.count();     
            }
        }
        
                cout << b << endl;

        if( ans == 50 ) ans = -1;
        
        cout << ans <<endl;


    }
    
    return 0;
}
