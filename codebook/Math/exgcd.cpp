//ax ≡ 1 (mod b)
//ax + by = 1,x=y=0
//a,b要互值

LL exgcd(LL a,LL b,LL &x,LL &y){//a*x+b*y=1
	if(b){
		LL tmd=exgcd(b,a%b,y,x);
		y-=a/b*x;
		return tmd;
	}
	x=1,y=0;
	return a;
}