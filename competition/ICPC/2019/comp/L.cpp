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
#define MAXN 5000
#define N

struct point
{
    int x,y;

    int dist(point b)
    {
        return (b.x-x) * (b.x-x) + (b.y-y) * (b.y-y);
    }

    int cross(point p2, point p3)
    {
        return (p2.x-x) * (p3.y-y) - (p2.y-y)*(p3.x-x)
    }
}base;

struct polygon
{
    vector<point> all;
    vector<point> checked;
}K[MAXN];

bool min_y(point a, point b)
{
    int c = base.cross(a,b);
    return c > 0 || (c == 0 && base.dist(a) < base.dist(b));
}

void convex_hull(int num)
{
    swap(K[num].all[0], *min_element(K[num].all.begin(), K[num].all.end(), min_y));
    base = k[num].all[0];
    sort(K[num].all.begin()+1, K[num].all.end(),c_clockwise);
    K[num].all.PB(base);

    int m = 0;
    for(int i = 0; i < K[num].all.size(); i++)
    {
        while( m >= 2&& K[num].checked[m-2].cross(K[num].checked[m-1], K[num].all[i]) <= 0)
        {
            K[num].checked.pop_back();
            m--;
        }
        K[num].checked.PB(K[num].all[i]);
        m++;
    }

}


bool ininside(point pnt, int num)
{
    for(int i = 1; i < K[num].checked.size(); i++)
    {
        if(K[num].checked[i-1].cross(K[num].checked[i],pnt) < 0)
            return false;
    }
    return true;
}


double area(int num)
{
    double a=0;
    for(int i = 1; i < K[num].checked.size(); i++)
    {
        a += (K[num].checked[i-1].x * K[num].checked[i].y) - (K[num].checked[i].x * K[num].checked[i-1].y);
    }

    a += (K[num].checked[K[num].checked.size()-1].x * K[num].checked[0].y) - (K[num].checked[0].x * K[num].checked[K[num].checked.size()-1].y);

    return a/2;
}



int main()
{
    int n,len;
    while(cin >> n)
    {
       while(n--)
       {
           cin >> len;
           int x,y;
           for(int i = 0; i < len; i++)
           {
               cin >> x >> y;
           }    
            K[0].PB();


       }
    }

}
