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
#define MP make_pair
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#define MAXN
#define INF 1000000

int main()
{
    
    int kase;
    scanf("%d",&kase);
    int K,L;

    while( kase-- ){
        
        scanf("%d %d",&K,&L);
        if( L == 2 && K+2 <= INF){
            cout << 2 << endl;
            printf("-1 %d\n",K+2);
        }
        else if( 2 < L && L < 2000 ){
            bool check = true;
            int tmp = L;
            int x;
            if((tmp&1)==0) tmp--;
            
            if( K&1 ){
                while( (K+tmp)%(tmp-1)!=0 && tmp > 2 )
                    tmp -= 2;
                x = (K+tmp)/(tmp-1);
                if( tmp < 2 || x > INF )
                    check = false;
            }
            else{
                while( K%(tmp-1)!=0 && tmp > 2 )
                    tmp -= 2;
                x = K/(tmp-1);
                if( tmp < 2 || x > INF )
                    check = false;
            }
            
            if( check ){
                cout << L << endl;
                for(int i = 1 ; i < tmp ; i+=2 )
                    printf("%d %d ",x,-x);
                if( K&1 ) x--;
                printf("%d ",x);
                for(int i = tmp ; i < L ; i++ )
                    printf("%d ",-INF);
            }
            else cout << "-1";
            cout << "\n";

        }
        else{
            cout << "-1\n";
        }
    

    }

    return 0;

}
