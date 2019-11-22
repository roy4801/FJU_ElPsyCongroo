//m = (x mod m)的數字
//a = (x mod m)後的結果
vector <LL> m,a;

LL Euler(LL n){
    LL ans = n;
    for (LL i=2; i*i<= n; ++i){
        if (n%i==0){
            ans=ans/i*(i-1);
            while (n%i==0)
                n/=i;
        }
    }
    if (n>1)
        ans=ans/n*(n-1);
    return ans;
}
LL pow_mod(LL n, LL k, LL m)
{
    LL ans=1;
    for (n=(n>=m?n%m:n); k; k >>= 1){
        if (k&1)
            ans=ans*n%m;
        n=n*n%m;
    }
    return ans;
}
LL CRT()
{
    LL M=1,tM,ans=0;
    for(int i=0;i<m.size();++i)
        M*=m[i];
    for(int i=0;i<a.size();++i)
    {
        tM=M/m[i];
        //ans = a(模完結果)*M*t(M的逆元), t用費馬小求,
        ans=(ans+(a[i]*tM%M)*pow_mod(tM,Euler(m[i])-1,m[i])%M)%M;
    }
    return ans;
}
