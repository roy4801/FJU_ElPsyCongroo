#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> P;
typedef long long int LL;
#define PB push_back


int main()
{

    string str,tmp;
    
    vector<string> ans;

    while(cin>>str){
        if( str == "bubble" || str == "tapioka" )
            continue;
        ans.push_back(str);
    }
    
    for(int i = 0 ; i < ans.size() ; i++ ){
        if(i) printf(" ");
        cout << ans[i];
    }
    
    if(ans.size()==0)
        cout << "nothing";
    cout << "\n";


}
