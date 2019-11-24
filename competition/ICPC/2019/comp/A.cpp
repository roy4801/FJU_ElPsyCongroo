#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> P;
typedef long long int LL;
#define PB push_back
int main()
{
    int n;
    
    while(cin >> n)
    {
        vector<int> vec;
        for(int i = 0,tmp; i < n; i++)
            cin >> tmp,vec.PB(tmp);
    
        bool flag = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                for(int k = 0; k < n; k++)
                {
                    if(i == j || j == k || i == k)
                        continue;
                    if( (vec[i] - vec[j]) % vec[k] != 0)
                    {
                        flag = 1;
                        break;
                    }
                }
            }
        }

        if(!flag)
            printf("yes\n");
        else
            printf("no\n");
    }
}
