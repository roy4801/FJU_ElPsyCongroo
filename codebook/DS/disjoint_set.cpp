#define N 100000
int p[N+5], siz[N+5];
void init()
{
    for(int i = 0; i <= N; i++)
    {
        p[i] = i;
        siz[i] = 1;
    }
}
int find(int x)
{
    return p[x]==x ? x : (p[x]=find(p[x]));
}
void uni(int a, int b)
{
    a = find(a), b = find(b);
    if(siz[a] > siz[b])
    {
        p[b] = p[a];
        siz[a] += siz[b];
        siz[b] = 0;
    }
    else
    {
        p[a] = p[b];
        siz[b] += siz[a];
        siz[a] = 0;
    }
}

struct disjoin{

    int group[MAXN+5];
    void init(){
        for(int i = 0 ; i < MAXN+5 ; i++ )
            group[i] = i;
    }

    int find(int k){
        return group[k]==k ? k:(group[k]=find(group[k]));
    }

    void uni(int a,int b){
        group[find(a)] = group[find(b)];
    }

    bool is_group(int a, int b){
        if( find(a) == find(b) )
            return true;
        return false;
    }

};